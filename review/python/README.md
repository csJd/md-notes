# My Frequently Forgotten Facts (FFFs)

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

## Usage
* [`for ... break` statement](https://docs.python.org/3/tutorial/controlflow.html#break-and-continue-statements-and-else-clauses-on-loops)
