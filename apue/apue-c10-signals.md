# 第10章 信号 P249

## 1. 信号
* 信号是软件中断，每个信号都有一个名字（*signo*），这些名字都以`SIG`开头，`Ctrl+C`: SIGINT, `Ctrl+\`: SIGQUIT 见P251表
* 函数`signal` P256
 > signal() sets the disposition of the signal signum to handler, which is either SIG_IGN, SIG_DFL, or the address of a programmer-defined function (a "signal handler").
* `kill`函数给`pid`指定的进程或进程组发送`signo`信号，`raise`函数给进程自身发送信号 P267
* `alarm`函数在`seconds`秒后产生`SIGALRM`信号，如果忽略此信号（不捕捉），则默认终止调用alarm的进程
* `pause`函数使调用进程挂起直至捕捉到一个信号



```c
#include <signal.h>
void (*signal(int signo, void (*func)(int)))(int);
// returns: previous disposition of signal (see following) if OK, SIG_ERR on error
typedef void Sigfunc(int); // 使用typedef对signal函数改写
Sigfunc *signal(int signum, Sigfunc *handler);

int kill(pid_t pid, int signo); // P267
int raise(int signo); // both return: 0 if OK, −1 on error

#include <unistd.h>
unsigned int alarm(unsigned int seconds); // returns: 0 or number of seconds until previously set alarm
int pause(void); // returns: −1 with errno set to EINTR
```



## 2. 信号集和信号屏蔽字

* `sigset_t`结构表示信号集 P273
* `sigprocmask`函数可以检测或更改进程的信号屏蔽字 P275
* `sigpending`函数通过`set`参数返回一信号集，对于调用进程而言，这些信号 are blocked from delivery and currently pending
* `sigacton`函数检查或修改与指定信号相关联的处理动作 P278
* `sigsetjmp`和`siglongjmp`实现非局部转移并保存信号屏蔽字
* `sigsuspend`函数在一个原子操作中先恢复信号屏蔽字然后使进程休眠 P286

```c
#include <signal.h>
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signo);
int sigdelset(sigset_t *set, int signo); // all return: 0 if OK, −1 on error
int sigismember(const sigset_t *set, int signo); //returns: 1 if true, 0 if false, −1 on error
int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);
// returns: 0 if OK, −1 on error
int sigaction(int signo, const struct sigaction *restrict act, struct sigaction *restrict oact); //returns: 0 if OK, −1 on error
int sigsuspend(const sigset_t *sigmask); // returns: −1 with errno set to EINTR

#include <setjmp.h>
int sigsetjmp(sigjmp_buf env, int savemask); // returns: 0 if called directly, nonzero if returning from a call to siglongjmp
void siglongjmp(sigjmp_buf env, int val);
```



## 3. 其他信号相关

* `abort`函数使程序异常终止，将`SIGABRT`信号发送给调用进程 P291
* `sleep`, `nanasleep`和`clock_nanosleep`实现使进程挂起直到满足条件 P298
* `sigqueue`函数实现信号排队的支持 P301

```c
#include <stdlib.h>
void abort(void);

#include <unistd.h>
unsigned int sleep(unsigned int seconds); // returns: 0 or number of unslept seconds
#include <time.h>
int nanosleep(const struct timespec *reqtp, struct timespec *remtp); // returns: 0 if slept for requested time or −1 on error
int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec *reqtp, struct timespec *remtp);
// returns: 0 if slept for requested time or error number on failure

#include <signal.h>
int sigqueue(pid_t pid, int signo, const union sigval value) // returns: 0 if OK, −1 on error
```

