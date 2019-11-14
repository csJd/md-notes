# My Frequently Forgotten Facts (FFFs)

## `new` expression

[`new` expression](https://en.cppreference.com/w/cpp/language/new) creates and initializes objects with dynamic storage duration, that is, objects whose lifetime is not limited by the [scope](https://en.cppreference.com/w/cpp/language/scope) in which they were created.

## Bit operation

* `n = n & (n-1)`: change the lowest 1 bit to 0
* `n & (n-1) == 0`: if n is 2^k
* `a ^= b; b ^= a; a^= b`: swap two number
* `x ^ y >= 0`: check if a * b >= 0

## Pointer, Reference and Array

* Difference of pointer and reference (P52)
  > A pointer is a compound type that “points to” another type. Like references, pointers are used for indirect access to other objects. Unlike a reference, a pointer is an object in its own right. Pointers can be assigned and copied; a single pointer can point to several different objects over its lifetime. Unlike a reference, a pointer need not be initialized at the time it is defined. Like other built-in types, pointers defined at block scope have undefined value if they are not initialized.

* Pointer to an array and array of pointers (P229)

  ```cpp
  int arr[10];           // arr is an array of ten ints
  int *p1[10];           // p1 is an array of ten pointers
  int (*p2)[10] = &arr;  // p2 points to an array of ten ints

  int (*func(int i))[10];   // declare a function which return a pointer to an array of ten ints
  ```

* `const`

  **top-level const**: object itself is a const;

  **low-level const**: pointer point to a const object. (P64)

  ```cpp
  int i = 0;
  int *const p1 = &i;    // we can't change the value of p1; const is top-level
  const int ci = 42;     // we cannot change ci; const is top-level
  const int *p2 = &ci;   // we can change p2; const is low-level
  const int *const p3 = p2; // right-most const is top-level, left-most is not
  const int &r = ci;     // const in reference types is always low-level

  const int &r2 = 42;    // ok: r2 is a reference to const (P61)
  const int &r3 = 3.14;  // ok; compiler convert it to ` const int tmp = 3.14; const int &r3 = tmp;
  ```

  `const` and `constexpr`:

  varibale in a `const` declaration can be initialized by any valid expression; the compiler will verify that the variable is a constant expression when declaring a variable in a `constexpr` declaration. (P66)

## Polymorphism

* Overloaded functions must differ in the number or the type(s) of their parameters. The compiler can figure out which function to call. (P231)

## MISC

* `EOF`: `Ctrl+Z` in Windows, `Ctrl+D` in Linux/macOS
* `int a = 20, b = 024, c = 0x14`, a == b, b == c
* Variables defined **outside any function** are initialized to zero, which defined inside a function are uninitialized.
* A constant expression is an expression whose value cannot change and that can be evaluated at compile time. (P65)
* The number of elements in an array is part of the array’s type, the dimension must be known at compile time. (P113)
* The array returned by `s.c_str()` is not guaranteed to be valid indefinitely. Any subsequent use of s that might change the value of s can invalidate this array. (P125)
