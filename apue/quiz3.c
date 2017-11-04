/*
   Description：
   用户不断从标准输入输入一个数n
   主线程得到N后，创建一个新线程计算total=total + n
   其中total是一个全局变量
*/

#include <stdio.h>
#include <pthread.h>

// pthread_mutex_t mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int total;

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
    pthread_mutex_lock(&mutex);
    printf("the total is %d\n", total);
    pthread_mutex_unlock(&mutex);

    return 0;
}
