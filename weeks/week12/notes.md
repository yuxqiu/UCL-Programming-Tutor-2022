# Week 12

## HTTP Basics

1. 4-Layer Model and the Web
   1. ![](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview/http-layers.png)
2. Client and Server
3. Text-based protocol
   1. simple and extensible
4. An example of a HTTP 1.1 request

    ```http
    GET / HTTP/1.1
    Host: www.ucl.ac.uk
    Connection: close

    ```
5. An example of a HTTP 1.1 response

    ```http
    HTTP/1.1 200 OK
    Connection: close
    Content-Length: 29769
    Content-Type: text/html

    <!DOCTYPE html>… (here come the 29769 bytes of the requested web page)
    ```

6. Syntax of the HTTP requests
   1. ![](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview/http_request.png)
   2. Available methods: `GET`, `POST`, `PATCH`, `UPDATE`...
   3. Headers
   4. Body
   5. Example

        ```http
        [Method] [Path] [Version of the Protocol]
        [Host]: [Domain]
        [Other Headers]

        [Body]
        ```

7. Syntax of the HTTP responses
   1. ![](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview/http_response.png)
   2. Version
   3. Status Code: [HTTP response status codes](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)
   4. Status Message: a non-authoritative short description of the status code. [HTTP Status Messages](https://www.w3schools.com/tags/ref_httpmessages.asp)
   5. Headers
   6. Body
   7. Example

        ```http
        [Version] [Status Code] [Status Message]
        [Other Headers]

        [Body]
        ```

8. Trivial Stuff
   1. Line Break: `\r\n`
   2. [New Line](https://en.wikipedia.org/wiki/Newline)
   3. [Carriage Return and Line Feed](https://stackoverflow.com/questions/3091524/what-are-carriage-return-linefeed-and-form-feed)


## Backend

1. What is Backend
   1. Definition
   2. Responsibility: APIs, database...

2. Backend Languages
   1. Any language with networking support can actually be the backend
   2. People most commonly use Java, JavaScript, PHP, Python

3. Demo: JavaScript + NodeJs + Koa2
   1. How to use `npm`
   2. Directory Structure
   3. Middleware
   4. Koa Router

4. Demo: Python + Flash
   1. Minimal Setup
   2. Abstractions: Routers and `flask`
      1. [Python Decorator](https://realpython.com/primer-on-python-decorators/)
   3. String-based Template

5. Demo: C
   1. Socket

6. Others
   1. Java: explore it later
   2. Haskell: [an example](https://dev.to/leandronsp/a-crud-journey-in-haskell-part-ii-socket-programming-2po1)

7. What's more (anything related with Backend)
   1. Databases: MySQL, Redis, NoSQL database -> Learn Database Theory
   2. Load Balancer: Nginx
   3. Distributed System (strictly speaking, this is a whole new area)
   4. Performance Tuning: asynchronous IO