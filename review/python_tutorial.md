# Python basic tutorial（2019.01.26）

- [Python basic tutorial（2019.01.26）](#python-basic-tutorial20190126)
  - [Prerequisites](#prerequisites)
  - [Python tutorial ( Forked from CS231)](#python-tutorial--forked-from-cs231)
    - [Standard Input & Output](#standard-input--output)
    - [Basic data types](#basic-data-types)
      - [Numbers](#numbers)
      - [Booleans](#booleans)
      - [Strings](#strings)
      - [None](#none)
      - [Type casting](#type-casting)
      - [Quiz #1: Calclating A + B + C](#quiz-1-calclating-a--b--c)
    - [Containers](#containers)
      - [Lists | [value, ]](#lists--value)
      - [Quiz #2: Fibonacci numbers](#quiz-2-fibonacci-numbers)
      - [Dictionaries | {key: value, }](#dictionaries--key-value)
      - [Sets | {element, }](#sets--element)
      - [Quiz #3: Remove repeated values](#quiz-3-remove-repeated-values)
      - [Tuples | (value, )](#tuples--value)
    - [Control flow](#control-flow)
      - [Condition](#condition)
      - [Loops](#loops)
    - [Functions](#functions)
      - [Quiz #4 : Implement `sqrt()` function](#quiz-4--implement-sqrt-function)
    - [Classes](#classes)
    - [File Input & Output](#file-input--output)
      - [Quiz #5: Char count](#quiz-5-char-count)
    - [Exceptions](#exceptions)
  - [END](#end)


## Prerequisites


* [VS Code](https://code.visualstudio.com/)

  - [Python extension](https://marketplace.visualstudio.com/items?itemName=ms-python.python)
* [Python 3  (conda version)](https://mirrors.tuna.tsinghua.edu.cn/anaconda/miniconda/)

  * Use tuna mirrors ([conda](https://mirrors.tuna.tsinghua.edu.cn/help/anaconda/) , [pypi](https://mirrors.tuna.tsinghua.edu.cn/help/pypi/) )

  * [IPython](https://ipython.org/), `pip(conda) install ipython`

  * [NumPy](http://www.numpy.org/) , `pip(conda) install numpy`

  * Create a Python 3.6 environment and activate it

    ```sh
    conda create --name py36 python=3.6
    activate py36
    # activate base
    ```
* [PyCharm (Community Version)](https://www.jetbrains.com/pycharm/download)

You can know more about conda package manager [in the documentation](https://conda.io/projects/conda/en/latest/user-guide/getting-started.html).



## Python tutorial ( Forked from [CS231](http://cs231n.github.io/python-numpy-tutorial/))



### Standard Input & Output

The [`input()`](https://docs.python.org/3/library/functions.html#input) built-in function read a line from standard input with trailing newline stripped.

The [`print()`](https://docs.python.org/3/library/functions.html#print) built-in function usually used to print something to standard output with adding a trailing newline.

```python
something = input()
print(something)

name = input("Input your name: ")
print("Hello", name)
```



### Basic data types

Like most languages, Python has a number of basic types including integers, floats, booleans, and strings. These data types behave in ways that are familiar from other programming languages.



#### Numbers

Integers and floats work as you would expect from other languages:

```python
x = 3
a, b = 1, 2
print(type(x)) # Prints "<class 'int'>"
print(x)       # Prints "3"
print(x + 1)   # Addition; prints "4"
print(x - 1)   # Subtraction; prints "2"
print(x * 2)   # Multiplication; prints "6"
print(x ** 3)  # Exponentiation; prints "27"
print(x / 2)   # Division
print(x // 2)  # Integer division
print(x % 2)   # Remainder of the division
x += 1
print(x)  # Prints "4"
x *= 2
print(x)  # Prints "8"
y = 2.5
print(type(y)) # Prints "<class 'float'>"
print(y, y + 1, y * 2, y ** 2) # Prints "2.5 3.5 5.0 6.25"
```

Note that unlike many languages, Python does not have unary increment (`x++`) or decrement (`x--`) operators.

Python also has built-in types for complex numbers; you can find all of the details [in the documentation](https://docs.python.org/3/library/stdtypes.html#numeric-types-int-float-complex).



#### Booleans

Python implements all of the usual operators for Boolean logic, but uses English words rather than symbols (`&&`, `||`, etc.):

```python
t = True
f = False
print(type(t)) # Prints "<class 'bool'>"
print(t and f) # Logical AND; prints "False"
print(t or f)  # Logical OR; prints "True"
print(not t)   # Logical NOT; prints "False"
print(t != f)  # Logical XOR; prints "True"
print(t == t)
```


#### Strings

Python has great support for strings:

```python
hello = 'hello'    # String literals can use single quotes
world = "world"    # or double quotes; it does not matter.
print(hello)       # Prints "hello"
print(hello[0])    # Prints ''
print(len(hello))  # String length; prints "5"
hw = hello + ' ' + world  # String concatenation
print(hw)  # prints "hello world"
hw12 = '%s %s %d' % (hello, world, 12)  # sprintf style string formatting
print(hw12)  # prints "hello world 12"
```

String objects have a bunch of useful methods; for example:

```python
s = "hello"
print(s.capitalize())  # Capitalize a string; prints "Hello"
print(s.upper())       # Convert a string to uppercase; prints "HELLO"
print(s.rjust(7))      # Right-justify a string, padding with spaces; prints "  hello"
print(s.center(7))     # Center a string, padding with spaces; prints " hello "
print(s.replace('l', '(ell)'))  # Replace all instances of one substring with another;
                                # prints "he(ell)(ell)o"
print('  world '.strip())  # Strip leading and trailing whitespace; prints "world"
print('hello world'.split())  
```

**Note**: strings in python are readonly objects

```python
hello = 'hello'
hello[0] = 'i'  # Invalid statement
```

You can find a list of all string methods [in the documentation](https://docs.python.org/3/library/stdtypes.html#string-methods).


#### None

The sole value of the type `NoneType`. [`None`](https://docs.python.org/3/library/constants.html#None) is frequently used to represent the absence of a value.


#### Type casting

```python
print(int(1.5))     # Convert floating point into integer truncates towards zero
print(int('-233'))  # A string must be a valid integer string to be converted into integer
print(float(1))
print(bool(1), bool(0), bool(1.1), bool(0.0))
print(bool(""), bool("hello"))
```

You can konw more about Python built-in types [in the documentation](https://docs.python.org/3/library/stdtypes.html).

#### Quiz #1: [Calclating A + B + C](https://nanti.jisuanke.com/t/1)




### Containers



Python includes several built-in container types: lists, dictionaries, sets, and tuples.



#### Lists | [value, ]

A list is the Python equivalent of an array, but is resizeable and can contain elements of different types:

```python
a = list()
b = []
print(type(a), type(b))

xs = [3, 1, 2]    # Create a list
print(1 in xs)    # Check whether an element is in a list
print(xs, xs[2])  # Prints "[3, 1, 2] 2"
print(xs[-1])     # Negative indices count from the end of the list; prints "2"
xs[2] = 'foo'     # Lists can contain elements of different types
print(xs)         # Prints "[3, 1, 'foo']"
xs.append('bar')  # Add a new element to the end of the list
print(xs)         # Prints "[3, 1, 'foo', 'bar']"
x = xs.pop()      # Remove and return the last element of the list
print(x, xs)      # Prints "bar [3, 1, 'foo']"
```

As usual, you can find all the gory details about lists [in the documentation](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists).

**Slicing:** In addition to accessing list elements one at a time, Python provides concise syntax to access sublists; this is known as *slicing*:

```python
nums = list(range(5))     # range is a built-in function that creates a list of integers
print(nums)               # Prints "[0, 1, 2, 3, 4]"
print(nums[2:4])          # Get a slice from index 2 to 4 (exclusive); prints "[2, 3]"
print(nums[2:])           # Get a slice from index 2 to the end; prints "[2, 3, 4]"
print(nums[:2])           # Get a slice from the start to index 2 (exclusive); prints "[0, 1]"
print(nums[:])            # Get a slice of the whole list; prints "[0, 1, 2, 3, 4]"
print(nums[:-1])          # Slice indices can be negative; prints "[0, 1, 2, 3]"
print(nums[0:4:2])        # Get a slice from index 0 to 4 (exclusive) with step 2
nums[2:4] = [8, 9]        # Assign a new sublist to a slice
print(nums)               # Prints "[0, 1, 8, 9, 4]"
```

We will see slicing again in the context of numpy arrays.

**Loops:** You can loop over the elements of a list like this:

```python
animals = ['cat', 'dog', 'monkey']
for animal in animals:
    print(animal)
# Prints "cat", "dog", "monkey", each on its own line.
```

If you want access to the index of each element within the body of a loop, use the built-in `enumerate` function:

```python
animals = ['cat', 'dog', 'monkey']
for idx, animal in enumerate(animals):
    print('#%d: %s' % (idx + 1, animal))
# Prints "#1: cat", "#2: dog", "#3: monkey", each on its own line
```

**List comprehensions:** When programming, frequently we want to transform one type of data into another. As a simple example, consider the following code that computes square numbers:

```python
nums = [0, 1, 2, 3, 4]
squares = []
for x in nums:
    squares.append(x ** 2)
print(squares)   # Prints [0, 1, 4, 9, 16]
```

You can make this code simpler using a **list comprehension**:

```python
nums = [0, 1, 2, 3, 4]
squares = [x ** 2 for x in nums]
print(squares)   # Prints [0, 1, 4, 9, 16]
```

List comprehensions can also contain conditions:

```python
nums = [0, 1, 2, 3, 4]
even_squares = [x ** 2 for x in nums if x % 2 == 0]
print(even_squares)  # Prints "[0, 4, 16]"
```

#### Quiz #2: [Fibonacci numbers](https://nanti.jisuanke.com/t/4)


#### Dictionaries | {key: value, }

A dictionary stores (key, value) pairs, similar to a `Map` in Java or an object in Javascript. You can use it like this:

```python
a = dict()
b = {}
print(type(a), type(b))

d = {'cat': 'cute', 'dog': 'furry'}  # Create a new dictionary with some data
print(d['cat'])       # Get an entry from a dictionary; prints "cute"
print('cat' in d)     # Check if a dictionary has a given key; prints "True"
d['fish'] = 'wet'     # Set an entry in a dictionary
print(d['fish'])      # Prints "wet"
# print(d['monkey'])  # KeyError: 'monkey' not a key of d
print(d.get('monkey', 'N/A'))  # Get an element with a default; prints "N/A"
print(d.get('fish', 'N/A'))    # Get an element with a default; prints "wet"
del d['fish']         # Remove an element from a dictionary
print(d.get('fish', 'N/A')) # "fish" is no longer a key; prints "N/A"
```

You can find all you need to know about dictionaries [in the documentation](https://docs.python.org/3/library/stdtypes.html#dict).

**Loops:** It is easy to iterate over the keys in a dictionary:

```python
d = {'person': 2, 'cat': 4, 'spider': 8}
for animal in d:
    legs = d[animal]
    print('A %s has %d legs' % (animal, legs))
# Prints "A person has 2 legs", "A cat has 4 legs", "A spider has 8 legs"
```

If you want access to keys and their corresponding values, use the `items` method:

```python
d = {'person': 2, 'cat': 4, 'spider': 8}
for animal, legs in d.items():
    print('A %s has %d legs' % (animal, legs))
# Prints "A person has 2 legs", "A cat has 4 legs", "A spider has 8 legs"
```

**Dictionary comprehensions:** These are similar to list comprehensions, but allow you to easily construct dictionaries. For example:

```python
nums = [0, 1, 2, 3, 4]
even_num_to_square = {x: x ** 2 for x in nums if x % 2 == 0}
print(even_num_to_square)  # Prints "{0: 0, 2: 4, 4: 16}"
```


#### Sets | {element, }

A set is an unordered collection of distinct elements. As a simple example, consider the following:

```python
a = set()
b = {}
print(type(a), type(b))

animals = {'cat', 'dog'}
print('cat' in animals)   # Check if an element is in a set; prints "True"
print('fish' in animals)  # prints "False"
animals.add('fish')       # Add an element to a set
print('fish' in animals)  # Prints "True"
print(len(animals))       # Number of elements in a set; prints "3"
animals.add('cat')        # Adding an element that is already in the set does nothing
print(len(animals))       # Prints "3"
animals.remove('cat')     # Remove an element from a set
print(len(animals))       # Prints "2"
```

As usual, everything you want to know about sets can be found [in the documentation](https://docs.python.org/3/library/stdtypes.html#set).

**Loops:** Iterating over a set has the same syntax as iterating over a list; however since sets are unordered, you cannot make assumptions about the order in which you visit the elements of the set:

```python
animals = {'cat', 'dog', 'fish'}
for idx, animal in enumerate(animals):
    print('#%d: %s' % (idx + 1, animal))
# Prints "#1: fish", "#2: dog", "#3: cat"
```

**Set comprehensions:** Like lists and dictionaries, we can easily construct sets using set comprehensions:

```python
from math import sqrt
nums = {int(sqrt(x)) for x in range(30)}
print(nums)  # Prints "{0, 1, 2, 3, 4, 5}"

```

#### Quiz #3: [Remove repeated values](https://nanti.jisuanke.com/t/11)



#### Tuples | (value, )

A tuple is an (immutable) ordered list of values. A tuple is in many ways similar to a list; one of the most important differences is that tuples can be used as keys in dictionaries and as elements of sets, while lists cannot. Here is a trivial example:

```python
d = {(x, x + 1): x for x in range(10)}  # Create a dictionary with tuple keys
t = (5, 6)        # Create a tuple
print(type(t))    # Prints "<class 'tuple'>"
print(d[t])       # Prints "5"
print(d[(1, 2)])  # Prints "1"
```

[The documentation](https://docs.python.org/3/tutorial/datastructures.html#tuples-and-sequences) has more information about tuples.





### Control flow



#### Condition

Python use [`if`](https://docs.python.org/3/reference/compound_stmts.html#if) statement to perform condition control flow.

```python
x = int(input("Please enter an integer: "))

if x < 0:
    x = 0
    print('Negative changed to zero')
elif x == 0:
    print('Zero')
elif x == 1:
    print('Single')
else:
    print('More')
```

There can be zero or more [`elif`](https://docs.python.org/3/reference/compound_stmts.html#elif) parts, and the [`else`](https://docs.python.org/3/reference/compound_stmts.html#else) part is optional. The keyword ‘`elif`’ is short for ‘else if’, and is useful to avoid excessive indentation. An `if` … `elif` … `elif` … sequence is a substitute for the `switch` or `case` statements found in other languages.



**Truth value testing** : Any object can be tested for truth value, for use in an [`if`](https://docs.python.org/3/reference/compound_stmts.html#if) or [`while`](https://docs.python.org/3/reference/compound_stmts.html#while) condition or as operand of the Boolean operations below. The following values are considered false:

- `None`
- `False`
- zero of any numeric type, for example, `0`, `0L`, `0.0`, `0j`.
- any empty sequence, for example, `''`, `()`, `[]`.
- any empty mapping, for example, `{}`.
- most of others are true.


#### Loops

The [`for`](https://docs.python.org/3/reference/compound_stmts.html#for) statement in Python differs a bit from other programming languages, Python’s `for` statement iterates over the items of any sequence (a list or a string), in the order that they appear in the sequence.

```python
# Loop over list:
words = ['cat', 'window', 'defenestrate']
for w in words:
    print(w, len(w))
word = words[2]

# Loop over string
for char in word:
    print(char)

# Loop over range
rng = range(10)
print(rng)
for i in range(10):
    print(i)
```

The [`while`](https://docs.python.org/3/reference/compound_stmts.html#while) statement is used for repeated execution as long as an expression is true.

```python
i = 0
while(i < 10):
    print(i)
    i += 1
```

A [`break`](https://docs.python.org/3/reference/simple_stmts.html#break) statement executed in the first suite terminates the loop without executing the `else` clause’s suite. 

```python
# judge whether a number is a prime number
x = int(input())
flag = True
for i in range(2, x):
    if x % i == 0:
        flag = False
        break
if flag:
    print("YES")
else:
    print("NO")
```

A [`continue`](https://docs.python.org/3/reference/simple_stmts.html#continue) statement executed in the first suite skips the rest of the suite and continues with the next item.

```python
for num in range(2, 10):
    if num % 2 == 0:
        print("Found an even number", num)
        continue
    print("Found a number", num)
```

The [`pass`](https://docs.python.org/3/reference/simple_stmts.html#pass) statement does nothing. It can be used when a statement is required syntactically but the program requires no action.

```python
if True:
    pass
```

You can know more about loops from [offical documents](https://docs.python.org/3/tutorial/datastructures.html#tut-loopidioms) , and more about Python's simple statements in [documents](https://docs.python.org/3/reference/simple_stmts.html) too





### Functions



Python functions are defined using the `def` keyword. For example:

```python
def sign(x):
    if x > 0:
        return 'positive'
    elif x < 0:
        return 'negative'
    else:
        return 'zero'

for x in [-1, 0, 1]:
    print(sign(x))
# Prints "negative", "zero", "positive"
```

We will often define functions to take optional keyword arguments, like this:

```python
def hello(name, loud=False):
    if loud:
        print('HELLO, %s!' % name.upper())
    else:
        print('Hello, %s' % name)

hello('Bob') # Prints "Hello, Bob"
hello('Fred', loud=True)  # Prints "HELLO, FRED!"
```

There are a number of built-in functions (like `len()`) in Python, you can konw more about them [in the documentation](https://docs.python.org/3/library/functions.html).

There is a lot more information about Python functions [in the documentation](https://docs.python.org/3/tutorial/controlflow.html#defining-functions).

#### Quiz #4 : [Implement `sqrt()` function](https://nanti.jisuanke.com/t/17)





### Classes

The syntax for defining classes in Python is straightforward:

```python
class Greeter(object):

    # Constructor
    def __init__(self, name):
        self.name = name  # Create an instance variable

    # Instance method
    def greet(self, loud=False):
        if loud:
            print('HELLO, %s!' % self.name.upper())
        else:
            print('Hello, %s' % self.name)

g = Greeter('Fred')  # Construct an instance of the Greeter class
g.greet()            # Call an instance method; prints "Hello, Fred"
g.greet(loud=True)   # Call an instance method; prints "HELLO, FRED!"
```

You can read a lot more about Python classes [in the documentation](https://docs.python.org/3/tutorial/classes.html).





### File Input & Output



Interact with files in Python is much easier than other languages , you can simply use [`open()`](https://docs.python.org/3/library/functions.html#open) built-in function.

```python
# wirte content into a file
file = open('file.txt', 'w')
file.write('hello\n')
file.write('\n1\n2\n3\n')
file.close()

# read from a file
file = open('file.txt')  # the default mode is 'r'
for line in file:
    print(line)
file.close()

# use 'with' statement (PEP343)
with open('file.txt') as file:
    print(file.readlines())
```



#### Quiz #5: Char count

[Download data file here](https://raw.githubusercontent.com/csJd/md-notes/master/review/python_tutorial.md). Calclate all characters' frequencies and save them into `charcount.txt` file like following.

```
char counts
-----------
.    233
a    2333
A    23333
```





### Exceptions



```python
def zero_division_fails():
    x = 1/0
    
def type_error_fails():
    x = "hello"
    x[0] = 'a'

def no_error():
    print("I'm fine")

def test(test_func):
    try:
        test_func()
    except ZeroDivisionError as err:
        print("Handling run-time error:", err)
    except TypeError as err:
        raise err
    finally:
        print("In finally")


print("test zero division case")
test(zero_division_fails)
print("\ntest type error case")
test(type_error_fails)
print("\nno error case")
test(no_error)
```

You can know more about errors and exceptions in Python [in the documentation](https://docs.python.org/3/tutorial/errors.html).




## END

You can read a lot more about Python in official [Python Tutorial](https://docs.python.org/3/tutorial/index.html).

Thank You.
