#include "apue.h"

int globvar = 88;
char buf[] = "a write\n";

int main(){
    int var;
    pid_t pid;
    var = 6;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {
        err_sys("write error");
    }
    printf("before fork\n");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        globvar++;
        var++;
    } else {
        sleep(2);
    }
    printf("pid = %d, glob = %d, var = %d\n", getpid(), globvar, var);

    _exit(0);
}
