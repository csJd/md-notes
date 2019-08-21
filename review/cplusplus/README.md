# My Frequently Forgotten Facts (FFFs)

## `new` expression

[`new` expression](https://en.cppreference.com/w/cpp/language/new) creates and initializes objects with dynamic storage duration, that is, objects whose lifetime is not limited by the [scope](https://en.cppreference.com/w/cpp/language/scope) in which they were created.

## Bit operation

* `n = n & (n-1)`: change the lowest 1 bit to 0
* `n & (n-1) == 0`: if n is 2^k
* `a ^= b; b ^= a; a^= b`: swap two number
* `x ^ y >= 0`: check if a * b >= 0
