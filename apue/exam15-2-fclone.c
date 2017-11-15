#include <fcntl.h> // for open, close
#include <stdio.h> // for io, BUFSIZ
#include <sys/stat.h> // for stat
#include <stdlib.h> // for exit, EXITFAIURE
#include <unistd.h> // for read, write

int main(int argc, char *argv[])
{
    if (argc != 3){
        fprintf(stderr, "Usage: %s srcfile newfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *srcfn = argv[1];
    char *newfn = argv[2];
    int srcfd, newfd;

    if ((srcfd = open(srcfn, O_RDONLY)) == -1) {
        fprintf(stderr, "Open file %s error\n", srcfn);
        exit(EXIT_FAILURE);
    }

    int nf_mode = 0666;
    newfd = open(newfn, O_RDWR|O_CREAT|O_TRUNC, nf_mode);

    char buf[BUFSIZ];
    int nbytes;
    while ((nbytes = read(srcfd, &buf, BUFSIZ)) != 0) {
        write(newfd, &buf, nbytes);
    }

    struct stat sbuf;
    struct timespec tbuf[2];
    stat(srcfn, &sbuf);
    tbuf[0] = sbuf.st_atim;
    tbuf[1] = sbuf.st_mtim;
    futimens(newfd, tbuf); 
    close(newfd);
    close(srcfd);

    return 0;
}
