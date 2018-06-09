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
# -h,--dereference : follow symlinks, archive and dump the files they point to
tar tvf archive.tar.[gz|bz2|lzma|xz]  # Test (list) a compressed archive
tar xvf archive.tar.[gz|bz2|lzma|xz] -C ./archive # Extract the contents of a compressed archive to ./archive

zip archive.zip file -r dir  # create zip archive including file and dir
unzip -O gbk archive.zip -d ./archive  # unzip archive.zip to ./archive and specify filename encoding

ln -s target link_name  # make symbolic links between files, link_name -> target
ln -s ~/opt/miniconda3/bin/* ~/bin/ # link all files into ~/bin/*
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
sudo vi /etc/environment  # edit global environment variables

adduser username  # Add a new user
adduser user group  # Add user to group
groups user  # Show which groups user belongs to
finger user  # Tell more information about user
sudo chown -R newuser.newgroup dir  # Change the owner and group of a directory and all its contents

fdisk -l  # List the partition tables
mkfs.ext4 /dev/sda1  # Format /dev/sda1 to ext4 fs

sudo mount /dev/uba1 /mnt/usbdisk  # Mount a formatted partition
sudo umount /mnt/usbdisk  # Unmount a filesystem
mount -o loop test.img /mnt/img  # Mount a image file (iso,img...)

du -h  # report file system disk space usage
df -h  # estimate file space usage, -h: print sizes in human readable format

dd bs=1M count=2048 if=/dev/zero of=test conv=fdatasync  # test disk write speed
dd if=file.iso of=/dev/sdc  # burn iso into a disk

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


### Server 
```
nc -zv 183.3.143.131 22   # Check port
nc -zv [-w timeout] host port[-port]  # Test port connections
```

(SSH port forwarding rel.)[https://www.ibm.com/developerworks/cn/linux/l-cn-sshforward/]
```
ssh -L <local port>:<remote host>:<remote port> user@host -p <ssh-port>
ssh -N -f -L 8888:localhost:8888 user@host -p 18226  # example for jupyter
ssh -N -f -L 6006:localhost:6006 user@host  # example for tensorboard
```
