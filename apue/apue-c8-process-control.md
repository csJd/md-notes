# 第8章 进程控制

## 1. `fork()` and pid P182

```c
#icnlude <unistd.h>
pid_t getppid(); // returns: parent process ID of calling process
uid_t getuid(); // returns: real user ID of calling process
pid_t fork(); // returns: 0 in child, process ID of child in parent, −1 on error
```

> fork()子进程获得父进程的数据空间、堆和栈的副本（父进程和子进程并不共享这些存储空间部分）

* I/O缓冲区的内容也会复制到子进程，注意区分行缓冲和全缓冲，`exit()`和`_exit()`
* `vfork()`不复制父进程数据空间、堆和栈的副本，且保证子进程先运行，子进程共享父进程空间



## 2. `exit ` function P189

* 5种正常终止方式，3种异常终止方式
* `_exit`立刻进入内核，`exit`则先执行一些清理处理（如对所有打开流调用`fclose`函数）


* 僵死进程：已经终止，但是其父进程尚未对其进行善后处理（获取其终止状态）

## 3. `wait` function P190

```c
#include <sys/wait.h>
pid_t wait(int *statloc); // block the caller until a child process terminates
pid_t waitpid(pid_t pid, int *statloc, int options);
// both return: process ID if222.201.139.57OK, 0 or −1 on error
int waitid(idtype_t idtype, id_t, id, siginfo_t *infop, int options); // P194
pid_t wait3(int *statloc, int options, struct rusage *rusage);
```



## 4. `exec` function P199

```c
#include <unistd.h>
int execl(const char *pathname, const char *arg0, ... /* (char *)0 */ );
int execv(const char *pathname, char *const argv[]);
int execle(const char *pathname, const char *arg0, ... /* (char *)0, char *const envp[] */ );
int execve(const char *pathname, char *const argv[], char *const envp[]);
int execlp(const char *filename, const char *arg0, ... /* (char *)0 */ );
int execvp(const char *filename, char *const argv[]);
int fexecve(int fd, char *const argv[], char *const envp[]);
All seven return: −1 on error, no return on success
```

* 如果`filename`中包含`'/'`则视为路径名，否则按`PATH`环境变量指定的路径查找可执行文件
* 命名规则：`l -> argList, v -> argv[], e -> envp[], p -> filename, f -> fd`

![关系图](https://github.com/csJd/csJd.github.io/raw/res/apue-c8-process-control-p1.png)

```c
#include <stdlib.h>
int system(const char *cmdstring); //P264
```



## 5. Changing User IDs and Group IDs

```c
#include <unistd.h>
int setuid(uid_t uid);
int setgid(gid_t gid); 
int seteuid(uid_t uid); //only the effective user ID may change
// all return: 0 if OK, -1 on error
```

* 若进程有 root 权限，则`setuid`将 read user ID, effective user ID 和 saved set-user-ID 都设置为`uid`，否则只有当`uid`为 read user ID 或 saved set-user-ID 时，`setuid`才会仅将effective user ID设置为`uid`
