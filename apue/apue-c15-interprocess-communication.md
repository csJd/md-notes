# 第15章 进程间通信

## 1. 管道 P430

* 管道的局限性：半双工，只能在具有公共祖先的两个进程间使用
* 使用`pipe`函数创建管道，`fd[0]`为读而打开，`fd[1]`为写而打开，`fd[1]`的输出是`fd[0]`的输入

```c
#include <unistd.h>
int pipe(int fd[2]); // returns: 0 if OK, −1 on error
```
![pipe after fork](https://github.com/csJd/csJd.github.io/raw/res/apue-c15-interprocess-communication-p0.png)
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



## 2. FIFO P445 

* FIFO是一种文件类型，有时也被成为命名管道，通过FIFO，不相关的进程也能交换数据
* 使用`mkfifo`函数创建FIFO，创建后可以用`open`来打开它，一般的I/O函数也适用于FIFO，如`close`, `read`,  `write`等

```c
#include <sys/stat.h>
int mlfifo(const char *path, mode_t mode);
int mkfifoat(int fd, const char *path, mode_t mode);
// both return: 0 if OK, −1 on error
```



## 3. XSI(X/Open System Interfaces) IPC P448

* XSI IPC包括信号量、消息队列和共享存储，每个IPC对象都与一个键（`key_t key`）和一个`ipc_perm`结构相关联

* 三种XSI IPC对比

  |                    | Message queues | Semaphores    | Shared Memory |
  | ------------------ | -------------- | ------------- | ------------- |
  | Header             | \<sys/msg.h\>  | \<sys/sem.h\> | \<sys/shm.h\> |
  | Create or open     | msgget         | semget        | shmget        |
  | Control operations | msgctl         | semctl        | shmctl        |
  | IPC operations     | msgsnd, msgrcv | semop         | shmat, shmdt  |

  ​



## 4. 消息队列 P451

* 每个队列有一个`msqid_ds`结构与其相关联 P451
* `msgget`函数打开一个现有队列或创建一个新队列，返回队列ID
* `msgctl`函数可由`cmd`参数指定对`msqid`指定的队列的多种操作，类似`ioctl`函数 P452
* `msgsnd`函数将`ptr`指向的消息结构的`nbytes`字节数据放到`msqid`指定的消息队列中
* `msgrcv`函数从`msqid`指定的消息队列读取`nbytes`字节到`ptr`指定的消息结构，`type`指定想读的消息类型 P454

```c
#include <sys/msg.h>
struct mymsg { // 若发送的最长消息是512字节，可以定义如下消息结构
  long mtype; //消息类型，后面的ptr参数指向该地址
  char mtext[512]; //消息内容，在内存中是紧跟着消息类型的
}
int msgget(key_t key, int flag); // returns: message queue ID if OK, −1 on error
int msgctl(int msqid, int cmd, struct msqid_ds *buf);
int msgsnd(int msqid, void *ptr, size_t nbytes, int flag); // both return: 0 if OK, −1 on error
ssize_t msgrcv(int msqid, void *ptr, size_t nbytes, long type, int flag);
// returns: size of data portion of message if OK, −1 on error
```



## 5. 信号量 P455

* 信号量是一个计数器，用于为多个进程提供对共享数据对象的访问，PV操作
* 内核为每个信号量集合维护着一个`semid_ds`结构，每个信号量由一个无名结构指定 P456
* `semget`函数用来引用或创建一个新的信号量集合，`nsems`指定新建集合的信号量数，返回信号量集合ID
* `semctl`函数可对`semid`指定的信号量集合进行`cmd`指定的多种操作 P457
* `semop`函数在`semid`指定的信号量集合上执行操作数组`sops`的前`nops`项
* 无论何时只要为信号量操作的`sem_flg`指定了`SEM_UNDO`标志，该进程终止时内核会处理好对信号量的调整

```c
#include <sys/sem.h>
int semget(key_t key, int nsems, int flag); // returns: semaphore ID if OK, −1 on error
int semctl(int semid, int semnum, int cmd, ... /* union semun arg */ );
struct sembuf { // 信号量操作结构 P458
    unsigned short sem_num;  // semaphore number
    short sem_op;   // semaphore operation
    short sem_flg;  // operation flags
}
int semop(int semid, struct sembuf sops[], size_t nops);
```



## 6. 共享存储 P459

* 内核为每个共享存储段维护着一个`shmid_ds`结构
* `shmget`函数引用或创建一个新的共享存储段，返回共享存储段ID
* `shmctl`函数可对`shmid`指定的共享存储段进行`cmd`指定的多种操作 P461
* `shmat`函数将`shmid`指定的共享存储段连接到进程的地址空间中，具体地址与`addr`（推荐值为0，表示由内核选择地址）相关，
* `shmdt`函数将与`addr`（应该是之前调用`shmat`所得到的地址）相连接的共享存储段分离

```c
#include <sys/shm.h>
int shmget(key_t key, size_t size, int flag); // returns: shared memory ID if OK, −1 on error
int shmctl(int shmid, int cmd, struct shmid_ds *buf); // returns: 0 if OK, −1 on error
void *shmat(int shmid, void *addr, int flag); // returns: pointer to shared memory segment if OK, −1 on error
int shmdt(const void *addr); //returns: 0 if OK, −1 on error
```



## 7.  Memory layout on an Intel-based Linux system 

![pipe after fork](https://github.com/csJd/csJd.github.io/raw/res/apue-c15-interprocess-communication-p1.png)



