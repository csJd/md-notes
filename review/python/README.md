# My Frequently Forgotten Facts (FFFs)

## [Data Model](https://docs.python.org/3/reference/datamodel.html)

* All data in a Python program is represented by objects or by relations between objects.
* Every object has an identity ([`id(x)`](https://docs.python.org/3/library/functions.html#id)), a type ([`type(x)`](https://docs.python.org/3/library/functions.html#type)) and a value (`x`). For CPython, `id(x)` is the memory address where `x` is stored.

  ```python
  In [1]: x = 1
  In [2]: id(x)
  Out[2]: 4485575824

  In [3]: type(x)
  Out[3]: int

  In [4]: x
  Out[4]: 1
  ```

* For immutable types, operations that compute new values **may** actually return a reference to any existing object with the same type and value, while for mutable objects this is not allowed.
* A string is a sequence of values that represent Unicode code points. All the code points in the range `U+0000 - U+10FFFF` can be represented in a string.

## [Python STL](https://docs.python.org/3/library/index.html)

* [`heapq`](https://docs.python.org/3/library/heapq.html): Heap, Priority queue
* [`bisect`](https://docs.python.org/3/library/bisect.html): Binary search library
* [`array`](https://docs.python.org/3/library/array.html): Efficient arrays of numeric values

## [Built-in Functions](https://docs.python.org/3/library/functions.html)

* `bin(i)`, `oct(i)`, `hex(i)`, integer in different system
* `int(s, base=10)`, `s` should be `str` object
* `ord(c)`, `chr(i)`, char and Unicode code
* `evel(...)`, `exec(...)`

## [PEP498: f-strings](https://www.python.org/dev/peps/pep-0498/)

* [`str.format()` and built-in `format()`](https://docs.python.org/3/library/string.html#formatspec)

  ```python
  >>> format(14, '#b'), format(14, 'b')
  ('0b1110', '1110')
  >>> f'{14:#b}', f'{14:b}'
  ('0b1110', '1110')
  >>> date = datetime.date(1991, 10, 12)
  >>> f'{date} was on a {date:%A}'
  '1991-10-12 was on a Saturday'
  ```

## GIL

* The CPython interpreter is not thread-safe internally, so it has a Global Interpreter Lock (GIL), which allows only one thread at a time to execute Python bytecodes. That’s why a single Python process usually cannot use multiple CPU cores at the same time. (Fluent Python P515)

## Misc

* [Python Glossary](https://docs.python.org/3/glossary.html)
* [Time complexity of operations](https://wiki.python.org/moin/TimeComplexity)
* [Operator precedence](https://docs.python.org/3/reference/expressions.html#operator-precedence)
* [Object default methods](https://docs.python.org/3/reference/datamodel.html#basic-customization)
* [`for ... break` statement](https://docs.python.org/3/tutorial/controlflow.html#break-and-continue-statements-and-else-clauses-on-loops)
* [liscomps and genexps](https://docs.python-guide.org/writing/style/#short-ways-to-manipulate-lists)
* `10 == 0b1010 == 0o12 == 0xa`: True, they are all valid literal of integer 10
* If your module is the main program, then `__name__` will be set to "__main__" instead of module name (filename without .py)

## Be careful

* Do Not use mutable types as parameter defaults (Fluent Python P230)

```python
In [1]: def func(a=[]):
    ...:     a.append(1)
    ...:     print(a)

In [2]: func()
[1]

In [3]: func()
[1, 1]
```

* CPython does not intern all strings or integers. Never depend on str or int interning! Always use == and not is to compare them for equality (Fluent Python P241)

```python
In [1]: a = 10086

In [2]: b = 10086

In [3]: a is b
Out[3]: False

In [4]: a = 1

In [5]: b = 1

In [6]: a is b
Out[6]: True
```
