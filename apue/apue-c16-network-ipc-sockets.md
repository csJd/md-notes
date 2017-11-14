# 第16章 网络IPC：套接字

## 1. 套接字 P437

* `socket`函数创建一个套接字，返回套接字描述符，套接字描述符是用文件描述符实现的，`protocol`参数通常为0，表示按`domain`和`type`来选择默认协议
* 套接字通信是双向的，`shutdown`函数用来关闭套接字的读端/写端，与`close`区别 P439
* `htonl`和`htons`将处理器字节序标识的整数转换为网络字节序表示的整数，`ntohl`和`ntohs`反之 P440

```c
#include <sys/socket.h>
int socket(int domain, int type, int protocol); // returns: socket descriptor if OK, −1 on error
int shutdown(int sockfd, int how); // returns: 0 if OK, −1 on error

#include <arpa/inet.h>
uint32_t htonl(uint32_t hostint32); // returns: 32-bit integer in network byte order
uint16_t ntohs(uint16_t netint16); // returns: 16-bit integer in host byte order
```



## 2. 地址格式 P441

* 为了使不同格式地址能够被传入套接字函数，地址被强制转换为通用的地址结构`sockaddr`
* 函数`inet_ntop`将二进制地址 (numeric) 转换为点分十进制字符串 (presentation) 格式，函数`inet_pton`反之 P442
* 函数`gethostent`得到给定计算机的主机信息 P443
* 函数`getaddrinfo`将一个主机名和服务名映射到一个地址 P445

```c
struct sockaddr { // sockaddr on linux
    sa_family_t sa_family; // address family
    char sa_data[14]; // variable-length address
};

#include <arpa/inet.h>
const char *inet_ntop(int domain, const void *addr, char *str, socklen_t size); 
// returns: pointer to address string on success, NULL on error
int inet_pton(int domain, const char *str, void *addr);
// returns: 1 on success, 0 if the format is invalid, or −1 on error

#include <netdb.h>
struct hostent *gethostent(); // returns: pointer if OK, NULL on error
int getaddrinfo(char *host, char *service, struct addrinfo *hint, struct addrinfo **res);
// returns: 0 if OK, nonzero error code on error
```



## 3. TCP套接字基础

![](https://github.com/csJd/csJd.github.io/raw/res/apue-c16-network-ipc-sockets-p0.png)

* `bind`函数将地址绑定到一个套接字
* 服务器调用`listen`后，套接字就能接受连接请求，使用`accept`获得连接请求并建立连接
* `connect`函数在客户端套接字和服务器套接字间建立一个连接 P450
* P455开始的5个示例程序 16-4 ~ 16-8，第3版 16.16 ~ 16.20

```c
#include <sys/socket.h>
int bind(int sockfd, const struct sockaddr *addr, socklen_t len); // returns: 0 if OK, −1 on error
int listen(int sockfd, int backlog); //returns: 0 if OK, −1 on error
int accept(int sockfd, struct sockaddr *addr, socklen_t *len); // returns: file (socket) descriptor if OK, −1 on error
int connect(int sockfd, const struct sockaddr *addr, socklen_t len); // returns: 0 if OK, −1 on error
```
