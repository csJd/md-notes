# 第16章 网络IPC：套接字

* 创建套接字 P474

```c
int socket(int domain, int type, int protocol);
```

* 输入通信特性（地址格式，套接字类型，协议类型）
* 禁止套接字I/O（单向关闭） P476

```c
int shutdown(int sockfd, int how);
```

* 处理器字节序和网络字节序间的转换 P478

```c
uint32_t hton1(uint32t hostint32);
```

* h表示主机字节序，n表示网络字节序
* 二进制地址与字符地址的自动转换（IPv4/6通用） P479

```c
const char* inet_ntop(int domain, const void* restrict addr, char* restrict str, socklen_t size);
int inet_pton(int domain, const char* restrict str, void* restrict addr);
```

* 关联地址和套接字 P486

```c
int bind(int sockfd, const struct sockaddr* addr, socklen_t len);
```

* （请求）建立连接 P487

```c
int connect(int sockfd, const struct sockaddr* addr, socklen_t len);
```

* （服务器）接受连接请求 P489

```c
int listen(int sockfd, int backlog);
```

* （套接字）接受请求 P489

```c
int accept(int sockfd, struct sockaddr* restrict addr, socklen_t* restrict len);
```

