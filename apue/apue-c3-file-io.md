# 第3章 文件I/O

## 1. 打开、创建和关闭文件 P50

```c
#include <fcntl.h> // 本章以下所有代码默认包含<fcntl.h>头文件
int open(const char *pathname, int flags, /* mode_t mode */);
int openat(int fd, const char* path, int flags, /* mode_t mode */);
int creat(const char *pathname, mode_t mode); // create for write-only, p52
// creat(pathname, mode); 等价于 open(pathname, O_WRONLY|O_CREAT|O_TRUNC, mode);
// all return: file descriptor if OK, −1 on error
int close(int fd); // returns: 0 if OK, −1 on error, p53
```

* `flags`参数指定打开文件的多个选项：`O_RDONLY`只读，`O_RDWR`可读可写，`O_CREAT`不存在则创建
* `mode` 参数指定新建文件的mode，若没有新建文件，忽略该参数


## 2. 设置偏移量 P53

```c
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence); // returns: new file offset if OK, −1 on error
```

`whence` 参数的含义：

* `whence == SEEK_SET` ：将该文件的偏移量设置为`offset`
* `whence == SEEK_CUR` ：将文件的偏移量设置为当前值加`offset`
* `whence == SEEK_END` ：将该文件的偏移量设置为文件长度加`offset`


## 3. 读和写文件 P57

```c
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count); 
ssize_t pwrite(int fd, const void *buf, size_t nbytes, off_t offset);
// 在offset处开始写，相当于先用lseek再write，但不更新文件的偏移量  P63
// both return: number of bytes written if OK, −1 on error
ssize_t read(int fd, void *buf, size_t count);
// returns: number of bytes read, 0 if end of file, −1 on error
```


### 4. 复制现有的文件标识符 P63

```c
#include <unistd.h>
int dup(int fd); // 返回最小的可用文件描述符
int dup2(int fd, int fd2); // 指定新文件描述符为fd2，若fd2已经打开且不等于fd则现将其关闭
// both return: new file descriptor if OK, −1 on error
dup(fd); 等效于 fcntl(fd, F_DUPFD, 0);
dup(fd, fd2); 等效于 close(fd2); fcntl(fd, F_DUPFD, fd2);
```


### 5. 其他 P65

```c
#include <fcntl.h>
int fcntl(int fd, int cmd,  ... /* int arg */);
```

* `cmd` 为 `F_GETFL`(`F_SETFL`)时，获取（设置）文件状态标志

```c
#include <sys/ioctl.h>
int ioctl(int fd, int request, ...);
```

* `/dev/stdin` 等效于`/dev/fd/0`，标准输入的路径名，可以作为`open`等的文件路径名

