# 第7章 进程环境

## 1. 进程终止 P158

* `exit`, `_exit`和`_exit`用于正常终止一个程序
* `atexit`函数将 `func`指定的函数登记到进程的 *exit handlers*

```c
#include <stdlib.h>
void exit(int status);
void _Exit(int status);
int atexit(void (*func)(void)); // returns: 0 if OK, nonzero on error
#include <unistd.h>
void _exit(int status);
```

* 进程有5种正常终止方式
  * 执行`return`语句（这等效于调用exit）
  * 调用`exit`函数（其操作包括调用各终止处理程序，然后关闭所有标准I/O流等）
  * 调用`_exit`或`_Exit`函数（立即进入内核。此二者为进程提供一种无需运行终止处理程序或信号处理程序而终止的方法）
  * 进程的最后一个线程在其启动例程中返回
  * 进程的最后一个线程调用`pthread_exit`函数
* 进程有3种异常终止方式
  * 调用`abort`（它产生`SIGABRT`信号）
  * 当进程接收到某些信号时（比如终止信号）
  * 最后一个线程对取消请求作出响应
* 在任意一种情况下，该终止进程的父进程都能用`wait`或`waitpid`函数取得其终止状态(8.3 P190)

> 当一个进程由于某种原因终止时，内核并不是立即把它从系统中清除。相反，进程被保持在一种已终止的状态中，直到被它的父进程回收。当父进程回收已终止的子进程时，内核将子进程的退出状态传递给父进程，然后抛弃已终止的进程，从此时开始，该进程就不存在了，一个终止了但还未被回收的进程称为僵死进程。



## 2. 存储空间分配 P163

* C程序的存储空间布局 P164
  * 栈（stack）： 自动变量和函数时调用保存的信息
  * 堆（heap）：通常在堆中进行动态存储分配
  * 未初始化数据段（uninitialized data, bss）：未初始化的全局变量
  * 初始化数据段（initialized data）：显式赋予初值的全局变量
  * 正文段（text）：存储机器指令，可共享
* `malloc`, `calloc`和`realloc`函数用于动态存储空间分配，返回申请到的存储空间的首地址
* `free`函数释放`ptr`指向的存储空间

```c
#include <stdlib.h>
void *malloc(size_t size);
void *calloc(size_t nobj, size_t size); // 为nobj个size字节的对象申请地址
void *realloc(void *ptr, size_t newsize); // 减小或增加以前分配区的长度
// all return: non-null pointer if OK, NULL on error
void free(void *ptr);
```



## 3. 环境表和环境变量 P168

* 环境表是一个字符指针数组，全局变量`extern char **environ`称为环境指针，指向环境表 P163
* `getenv`函数取`name`指定的环境变量值，返回指向*name=value*字符串中的*value*的指针
* `putenv`将`str`放入环境表中，`str`指向的字符串改变会导致对应环境变量的改变
* `setenv`将`name`环境变量值设置为`value`，`rewrite`为0则不改变已有的定义
* `unsetenv`从环境表中删除`name`的定义（如果有）

```c
#include <stdlib.h>
char *getenv(const char *name); // returns: pointer to value associated with name, NULL if not found
int putenv(char *str); // returns: 0 if OK, nonzero on error
int setenv(const char *name, const char *value, int rewrite);
int unsetenv(const char *name); // both return: 0 if OK, −1 on error
```



## 4. 跨越函数"goto" P170

```c
#include <setjmp.h>
int setjmp(jmp_buf env); // returns: 0 if called directly, nonzero if returning from a call to longjmp
void longjmp(jmp_buf env, int val);
```



## 5. 进程的资源限制 P175

```c
#include <sys/resource.h>
int getrlimit(int resource, struct rlimit *rlptr);
int setrlimit(int resource, const struct rlimit *rlptr);
// both return: 0 if OK, −1 on error
```

