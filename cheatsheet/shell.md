# MY SHELL SCRIPTING CHEAT SHEET

[Online here](https://devhints.io/bash)

[vbird here](http://linux.vbird.org/linux_basic/0340bashshell-scripts.php)


### Basic
[some differences between expressions](https://stackoverflow.com/questions/18135451/what-is-the-difference-between-var-var-and-var-in-the-bash-shell)

[somthing about strict mode](http://redsymbol.net/articles/unofficial-bash-strict-mode/)

`. script.sh` and `source script.sh` exec in current shell

`./script.sh`, `sh script.sh` and `bash script.sh` exec in sub shell

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

# strict mode
set -euo pipefail
IFS=$'\n\t'
```


### Conditions
```sh
test expression # <=> [ expression ], spaces are necessary


if [ -z "$string" ]; then
  echo "String is empty"
elif [ -n "$string" ]; then
  echo "String is not empty"
else
  echo "..."
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


### String

```sh
str="hello world"

# substring
${FOO:0:3}  # substring (position, length)
${FOO:-3:3} # substring from the right

# regex
if [[ $str =~ "^h" ]]
```


### Arrays
```sh
Fruits=('Apple' 'Banana' 'Orange')
Fruits[0]="Apple"
Fruits[1]="Banana"
Fruits[2]="Orange"

echo ${Fruits[0]}           # Element #0
echo ${Fruits[@]}           # All elements, space-separated
echo ${#Fruits[@]}          # Number of elements
echo ${#Fruits}             # String length of the 1st element
echo ${#Fruits[3]}          # String length of the Nth element
echo ${Fruits[@]:3:2}       # Range (from position 3, length 2)
```
