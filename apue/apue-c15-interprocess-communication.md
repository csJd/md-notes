# 第15章 进程间通信

## 1. 管道 P430

* 管道的局限性：半双工，只能在具有公共祖先的两个进程间使用
* 使用`pipe`函数创建管道，`fd[0]`为读而打开，`fd[1]`为写而打开，`fd[1]`的输出是`fd[0]`的输入

```c
#include <unistd.h>
int pipe(int fd[2]); // returns: 0 if OK, −1 on error
```
![pipe after fork](https://github.com/csJd/csJd.github.io/raw/res/apue-c15-interprocess-communication-p1.png)
* 父进程关闭管道的读端（fd[0]），子进程关闭写端（fd[1])，就形成了一个从父进程到子进程的管道 P432

```c
if ((pid = fork()) > 0) { // parent
  close(fd[0]);
  write(fd[1], "hello apue\n", 11);
} else if (pid == 0) { // child
  close(fd[1]);
  int n = read(fd[0], line, MAXLINE);
  write(STDOUT_FILENO, line, n);
}
```



# 2. FIFO P445 

* FIFO是一种文件类型，有时也被成为命名管道，通过FIFO，不相关的进程也能交换数据
* 使用`mkfifo`函数创建FIFO，创建后可以用`open`来打开它，一般的I/O函数也适用于FIFO，如`close`, `read`,  `write`等

```c
#include <sys/stat.h>
int mlfifo(const char *path, mode_t mode);
int mkfifoat(int fd, const char *path, mode_t mode);
// both return: 0 if OK, −1 on error
```



# 3. 信号量 P455

* 用于实现共享资源的P/V操作
* 使用`semget`函数来获得一个信号量ID

```c
#include <sys/sem.h>
int semget(key_t key, int nsems, int flag);
// returns: semaphore ID if OK, −1 on error
```

