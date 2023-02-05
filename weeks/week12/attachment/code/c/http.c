#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>      // for addrinfo
#include <sys/errno.h>  // for errno and strerrno
#include <sys/socket.h> // for socket and connect
#include <unistd.h>     // for close

#define LISTENQ 1024

static void Getaddrinfo(const char *node, const char *service,
                        const struct addrinfo *hints, struct addrinfo **res);
static void Close(int fd);
static int Open_listenfd(char *port);
static int Accept(int s, struct sockaddr *addr, socklen_t *addrlen);

// Don't do this
// We don't even check whether the request is a valid HTTP request
static void Reply(const int fd) {
  const char *response =
      "HTTP/1.1 200 OK\r\nContent-Length:11\r\nContent-Type: "
      "text/plain\r\n\r\nHello World\r\n";

  // should check the return value for error handling
  write(fd, response, strlen(response));
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const int listenfd = Open_listenfd(argv[1]);
  while (1) {
    socklen_t clientlen = sizeof(struct sockaddr_storage);
    struct sockaddr_storage clientaddr;
    const int connfd =
        Accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
    Reply(connfd);
    Close(connfd);
  }

  return 0;
}

// Adopted from CMU 15213
static void unix_error(const char *prefix) {
  fprintf(stderr, "%s: %s\n", prefix, strerror(errno));
  exit(EXIT_FAILURE);
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
    unix_error(__func__);
  }
}

// Adopted from CMU 15213
static void Setsockopt(int s, int level, int optname, const void *optval,
                       socklen_t optlen) {
  int rc;

  if ((rc = setsockopt(s, level, optname, optval, optlen)) < 0) {
    unix_error(__func__);
  }
}

// Adopted from CMU 15213
static int open_listenfd(char *port) {
  struct addrinfo hints = {.ai_socktype = SOCK_STREAM,
                           .ai_flags =
                               AI_PASSIVE | AI_ADDRCONFIG | AI_NUMERICSERV},
                  *listp, *p;
  int listenfd, optval = 1;

  Getaddrinfo(NULL, port, &hints, &listp);

  /* Walk the list for one that we can bind to */
  for (p = listp; p; p = p->ai_next) {
    /* Create a socket descriptor */
    if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
      continue; /* Socket failed, try the next */

    /* Eliminates "Address already in use" error from bind */
    Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval,
               sizeof(int));

    /* Bind the descriptor to the address */
    if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)
      break;         /* Success */
    Close(listenfd); /* Bind failed, try the next */
  }

  /* Clean up */
  freeaddrinfo(listp);
  if (!p) /* No address worked */
    return -1;

  /* Make it a listening socket ready to accept connection requests */
  if (listen(listenfd, LISTENQ) < 0) {
    Close(listenfd);
    return -1;
  }
  return listenfd;
}

// Adopted from CMU 15213
static int Open_listenfd(char *port) {
  int rc;
  if ((rc = open_listenfd(port)) < 0) {
    unix_error(__func__);
  }
  return rc;
}

// Adopted from CMU 15213
static int Accept(int s, struct sockaddr *addr, socklen_t *addrlen) {
  int rc;

  if ((rc = accept(s, addr, addrlen)) < 0) {
    unix_error(__func__);
  }
  return rc;
}
