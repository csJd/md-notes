# MY UNIX/LINUX CHEAT SHEET

[Full PDF version here](https://free-electrons.com/doc/legacy/command-line/command_memento.pdf)

### Files and directories
```sh
mkdir -p dir1/dir2   # Create nested directories
rsync -a source_dir/ dest_dir/  # Copy directories recursively use rsync
ls [-a --all] [-t --time] [-S --size] [-l]  # list [all] by time/size in long format

find . -name "*log*" # Find all files in the current (.) directory and its subdirectories with log in their name
locate "*log*"  # Quick system-wide file search by pattern
which  # locate a command

tar zcvf archive.tar.gz dir  # Create a compressed archive (z:gzip, j:bzip2, J:xz)
tar tvf archive.tar.[gz|bz2|lzma|xz]  # Test (list) a compressed archive
tar xvf archive.tar.[gz|bz2|lzma|xz]  # Extract the contents of a compressed archive
# -h,--dereference : follow symlinks, archive and dump the files they point to

wc file  # (word count) Number of bytes, words and lines in file
du -sh dir1 file1  # (disk usage) Show the total size on disk of files or directories 
df -h .  # Show the size, total space and free space of the current partition
```

### Job control
```sh
ps -ef  # Show all running processes
top, htop  # Live hit-parade of processes
kill <pid>  # Send a termination signal to a process
kill -9 <pid>  # Have the kernel kill a process
kill -9 -1  # Kill all processes (at least all user ones)
```

### System/User administration
```sh
adduser username  # Add a new user
adduser user group  # Add user to group
groups user  # Show which groups user belongs to
finger user  # Tell more information about user
sudo chown -R newuser.newgroup dir  # Change the owner and group of a directory and all its contents

sudo mount /dev/uba1 /mnt/usbdisk  # Mount a formatted partition
sudo umount /mnt/usbdisk  # Unmount a filesystem

du -h  # report file system disk space usage
df -h  # estimate file space usage, -h: print sizes in human readable format

uname -a  # Check the system kernel version
```

### Hardware info
```
lshw -short  # list hardware

cat /proc/meminfo
free -h  # Display amount of free and used memory in the system

cat /proc/cpuinfo
lscpu  # display information about the CPU architecture

df -h  # filesystem and usage

lspci | grep -i vga  # vga card info
```


### Tmux
[Online](http://blog.csdn.net/robertbaker/article/details/42172203)
[Usage0](https://linux.cn/article-3952-1.html)
[Usage1](https://www.cnblogs.com/bamanzi/p/tmux-mouse-tips.html)
[Usage2](http://blog.csdn.net/skykingf/article/details/46345057)
```
<prefix> z  # Make current pane full-screen
<prefix> x  # Kill the current pane
<prefix> c  # Create a new window
<prefix> d  # Detach the current client
```
