# 第11章 线程

## 1. `pthread_t` P307

* 进程ID用`pid_t`数据类型来表示，类似的，线程ID用`pthread_t`数据类型来表示

```c
#include <pthread.h>
// 判断线程id相等不能用`tid1 == tid2`
int pthread_equal(pthread_t tid1, pthread_t tid2); // returns: nonzero if equal, 0 otherwise
pthread_t pthread_self(); // returns: the thread ID of the calling thread

```


## 2. 线程创建 P309

* `pthread_create`函数创建一个线程，新线程从`start_routine`函数开始运行
* `tidp`参数指向的变量保存新创建线程的线程id
* `arg`参数为`start_routine`函数的参数，如果需要传递多个参数，就需要使用结构体指针
* `attr`参数可以设置线程属性，置为`NULL`即创建一个默认属性的线程
* 线程创建时**不保证**哪个线程会先运行，新线程**共享进程的地址空间**，并且继承调用线程的浮点环境和信号屏蔽字

```c
#include <pthread.h>
int pthread_create(pthread_t *tidp, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
// returns: 0 if OK, error number on failure
```


## 3. 线程终止 P311

> 如果进程中的任意线程调用了`exit`、`_exit`或`_Exit`，整个进程就会终止。

* 单个线程有3种退出方式：从启动例程返回、被同一进程的其他线程取消、线程调用`pthread_exit`

```c
#include <pthread.h>
// retval为传给启动例程的指针，进程中的其他线程可以通过调用 pthread_join 函数访问这个指针
void pthread_exit(void *retval);

// 调用pthread_join的线程将一直阻塞，直到thread指定的线程退出
int pthread_join(pthread_t thread, void **retval); // returns: 0 if OK, error number on failure

// 取消同一进程中的其他某一线程,被取消的线程可以忽略该取消 P316
int pthread_cancel(pthread_t tid); // returns: 0 if OK, error number on failure
```


## 4. 线程同步 P320

* pthread 提供使用互斥量的互斥接口
* 互斥变量用`pthread_mutex_t`数据类型表示，使用之前必须对它进行初始化

```c
#include <pthread.h>
// 对 mutex 指向的互斥量进行初始化，用默认的属性初始化只需把 attr 设为 NULL
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex); 
// both return: 0 if OK, error number on failure

// 也可以静态分配互斥量
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
```

* 可以调用`pthread_mutex_lock`对互斥量加锁，如果互斥量已经上锁，调用线程将阻塞直到互斥量被解锁

```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
// both return: 0 if OK, error number on failure
```

* 条件变量用`pthread_cond_t`数据类型表示，类似互斥变量，使用前也必须初始化 **P332**
* 线程调用`pthread_cond_wait`函数等待条件变量满足条件
* `pthread_cond_signal`和`pthread_cond_broadcast`函数可以通知线程条件满足

```c
#include <pthread.h>
int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
int pthread_cond_signal(pthread_cond_t *cond); //至少能唤醒一个
int pthread_cond_signal(pthread_cond_t *cond); //唤醒所有等待该条件的
// all return: 0 if OK, error number on failure
```

## 5. 课堂作业
> 用户不断从标准输入输入一个数N
> 
> 主线程得到N后，创建一个新线程计算total=total + N
> 
> 其中total是一个全局变量

My Solution：

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // for sleep

// pthread_mutex_t mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int total = 0;

void *run(void *arg)
{
    pthread_mutex_lock(&mutex);
    total = total + (int)arg;
    pthread_mutex_unlock(&mutex);
}

int main()
{
    int n;
    pthread_t tid;
    // pthread_mutex_init(&mutex, NULL);
    while (scanf("%d", &n) == 1)
    {
        pthread_create(&tid, NULL, run, (void *)n);
    }
    sleep(1);
    printf("the total is %d\n", total);
    pthread_mutex_destroy(&mutex);

    return 0;
}
// gcc quiz3.c -lpthread
```
