# My Frequently Forgotten Facts (FFFs)

## `new` expression

[`new` expression](https://en.cppreference.com/w/cpp/language/new) creates and initializes objects with dynamic storage duration, that is, objects whose lifetime is not limited by the [scope](https://en.cppreference.com/w/cpp/language/scope) in which they were created.

## Bit operation

* `n = n & (n-1)`: change the lowest 1 bit to 0
* `n & (n-1) == 0`: if n is 2^k
* `a ^= b; b ^= a; a^= b`: swap two number
* `x ^ y >= 0`: check if a * b >= 0

## MISC

* `EOF`: `Ctrl+Z` in Windows, `Ctrl+D` in Linux/macOS
* `int a = 20, b = 024, c = 0x14`, a == b, b == c
* Variables defined **outside any function** are initialized to zero, which defined inside a function are uninitialized.
* A constant expression is an expression whose value cannot change and that can be evaluated at compile time. (P65)
* The number of elements in an array is part of the array’s type, the dimension must be known at compile time. (P113)
* The array returned by `s.c_str()` is not guaranteed to be valid indefinitely. Any subsequent use of s that might change the value of s can invalidate this array. (P125)
