#include <netdb.h> // for addrinfo
#include <stddef.h>
#include <stdio.h>      // for fprintf, printf
#include <stdlib.h>     // for exit, EXIT_FAILURE, EXIT_SUCCESS
#include <string.h>     // for strlen
#include <sys/errno.h>  // for errno and strerrno
#include <sys/socket.h> // for socket and connect
#include <unistd.h>     // for close

#define BUFFER_SIZE 4096

typedef struct {
  char *msg_;
  size_t size_;
} ResponseStr;

static void GetPage(const char *host, const char *path);

int main(const int argc, const char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s hostname path\n", argv[0]);
    printf("Example: %s www.ucl.ac.uk /\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *host = argv[1];
  const char *path = argv[2];
  GetPage(host, path);
  return EXIT_SUCCESS;
}

// Adopted from CMU 15213
static void Getaddrinfo(const char *node, const char *service,
                        const struct addrinfo *hints, struct addrinfo **res) {
  int rc;
  if ((rc = getaddrinfo(node, service, hints, res)) != 0) {
    fprintf(stderr, "Getaddrinfo: %s\n", gai_strerror(rc));
    exit(EXIT_FAILURE);
  }
}

// Adopted from CMU 15213
static void Close(int fd) {
  int rc;

  if ((rc = close(fd)) < 0) {
    fprintf(stderr, "Close: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
}

// Adopted from CMU 15213
static int GetClientFd(const char *hostname, const char *port) {
  int clientfd;
  struct addrinfo hints = {0}, *listp, *p;

  /* Get a list of potential server addresses */
  hints.ai_socktype = SOCK_STREAM; /* Open a connection */
  hints.ai_flags = AI_NUMERICSERV; /* ... using a numeric port arg. */
  hints.ai_flags |= AI_ADDRCONFIG; /* Recommended for connections */
  Getaddrinfo(hostname, port, &hints, &listp);

  /* Walk the list for one that we can successfully connect to */
  for (p = listp; p; p = p->ai_next) {
    /* Create a socket descriptor */
    if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
      continue; /* Socket failed, try the next */

    /* Connect to the server */
    if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)
      break; /* Success */
    Close(clientfd);
    /* Connect failed, try another */ // line:netp:openclientfd:closefd
  }

  /* Clean up */
  freeaddrinfo(listp);
  if (!p) /* All connects failed */
    return -1;
  else /* The last connect succeeded */
    return clientfd;
}

// Never use this code in reality
// The return value of write needs to be checked to ensure content is
// successfully written
static void SendRequest(int fd, const char *host, const char *path) {
  const char *request_line_one_start = "GET ";
  const char *request_line_one_end = " HTTP/1.1\r\n";
  const char *request_line_two_start = "Host: ";
  const char *request_end = "\r\nConnection: close\r\n\r\n";

  write(fd, request_line_one_start, strlen(request_line_one_start));
  write(fd, path, strlen(path));
  write(fd, request_line_one_end, strlen(request_line_one_end));
  write(fd, request_line_two_start, strlen(request_line_two_start));
  write(fd, host, strlen(host));
  write(fd, request_end, strlen(request_end));
}

// Get Response from Fd
// Return null if all the content is read
//
// Very Inefficient
// and Return NULL should be considered as a bad design?
static ResponseStr GetResponse(int fd) {
  static char buffer[BUFFER_SIZE];
  ssize_t rc = read(fd, buffer, BUFFER_SIZE);
  if (rc > 0) {
    return (ResponseStr){buffer, (size_t)rc};
  } else if (rc < 0) {
    // neglect EINTR here for convenience
    // shouldn't do this in real world
    fprintf(stderr, "GetResponse: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  return (ResponseStr){NULL, 0};
}

static void GetPage(const char *host, const char *path) {
  int client_fd = GetClientFd(host, "80");
  if (client_fd == -1) {
    fputs("GetPage: failed to get client fd", stderr);
    exit(EXIT_FAILURE);
  }

  SendRequest(client_fd, host, path);
  for (ResponseStr response = GetResponse(client_fd); response.msg_ != NULL;
       response = GetResponse(client_fd)) {
    fwrite(response.msg_, sizeof(char), response.size_, stdout);
  }

  Close(client_fd);
}
