# MY SHELL SCRIPTING CHEAT SHEET

[Online here](https://devhints.io/bash)
[vbird here](http://linux.vbird.org/linux_basic/0340bashshell-scripts.php)


### Basic
[some differences between expressions](https://stackoverflow.com/questions/18135451/what-is-the-difference-between-var-var-and-var-in-the-bash-shell)

```sh
#!/bin/bash

# variables
name="Deng"  # can not have spaces around '='
echo "Hi $name"  # => Hi Deng
echo 'Hi $name'  # => Hi $NAME

# conditional execution
test -e "shell.md" && echo 'exists' || echo 'not exists'
git commit && git push

# brace expansion
{A,B}     # => A B
{A,B}.js  # => A.js B.js
{1..5}    # => 1 2 3 4 5

# shell execution
echo "I'm in $(pwd)"
echo "I'm in `pwd`"
```


### Conditions
```sh
test expression # <=> [ expression ], spaces are necessary


if [ -z "$string" ]; then
  echo "String is empty"
elif [ -n "$string" ]; then
  echo "String is not empty"
fi
```


### Loops
```sh
# for loop
for i in /etc/rc.*; do
  echo $i
done

for i in {1..5}; do
    echo "Welcome $i"
done

for i in {5..50..5}; do
    echo "Welcome $i"
done

s=0
for((i=0; i<6; ++i)); do
    s=$(($s + $i))  # $((equation)) for calculate 
done
echo "The sum is $s"


# while loop
while [ condition ]; do
    echo "hello"
done

until [ condition ]; do
    echo "hello"
done

# forever
while true; do
  ···
done
```


### Functions
```sh
# defining functions
myfunc() {
    echo "hello $1"
}

# same as above (alternate syntax)
function myfunc() {
    echo "hello $1"
}
myfunc "Deng"

# returning values
myfunc() {
    local myresult='some value'
    echo $myresult
}
result=$(myfunc)

```
