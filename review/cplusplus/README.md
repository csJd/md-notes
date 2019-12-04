# My Frequently Forgotten Facts (FFFs)

## Input/Output

* `int a = 42, b = 052, c = 0x2a; a == b, b == c`

  ```cpp
  cout << dec << 42 << endl;  // output: 42
  cout << oct << 42 << endl;  // output: 52
  cout << hex << 42 << endl;  // output: 2a
  // Input/output manipulators: https://en.cppreference.com/w/cpp/io/manip
  ```

* `'0' == 0x30, '1' == 0x31, '2' == 0x32, ..., '9' == 0x39`

* Bit operation
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

  * `const` and `constexpr`:

    varibale in a `const` declaration can be initialized by any valid expression; the compiler will verify that the variable is a constant expression when declaring a variable in a `constexpr` declaration. (P66)

  * const member function
    The nonconst member function will not be viable for const objects; we can only call const member functions on a const object. We can call either version on a nonconst object, but the nonconst version will be a better match. (P276)

    ```cpp
    class FooClass{
      public:
          void foo(){ /*...*/}  // nonconst member function, can only called by nonconst object
          void foo() const {/*...*/}  // const member function
      /*...*/
    };
    ```

* Rvalue References (P532)
  * Generally speaking, an lvalue expression refers to an object’s identity whereas an rvalue expression refers to an object’s value.
  * We can bind **rvalue references** (obtained by `&&`) to expressions that require a conversion, to literals, or to expressions that return an rvalue

    ``` cpp
    int i = 42;
    int &r = i;       // ok:r refers to i
    int &&rr = i;     // error: cannot bind an rvalue reference to an lvalue
    int &r2 = i * 42; // error: i*42 is an rvalue
    const int &r3 = i * 42; // ok: we can bind a reference to const to an rvalue
    int &&rr2 = i * 42;     // ok: bind rr2 to the result of the multiplication
    ```

  * Lvalues Persist; Rvalues Are Ephemeral; Variables Are Lvalues
  * Rvalues are moved, lvalues are copied, but rvalues are copied if there is no move constructor

* Reference collapsing applies only when a reference to a reference is cre- ated indirectly, such as in a type alias or a template parameter. (P688)
  * `X& &`, `X& &&`, and `X&& &` all collapse to type `X&`
  * The type `X&& &&` collapses to `X&&`
* An argument of any type can be passed to a function parameter that is an rvalue reference to a template parameter type (i.e., `T&&`). When an lvalue is passed to such a parameter, the function parameter is instantiated as an ordinary, lvalue reference (`T&`). (P689)
* We can explicitly cast an lvalue to an rvalue reference using `static_cast`. (P691)

## [Containers](https://en.cppreference.com/w/cpp/container)

* [STL Container Performance](http://john-ahlgren.blogspot.com/2013/10/stl-container-performance.html)
* Sequential containers (P327):
 `vector`,
 `deque`,
 `list`,
 `forward_list`,
 `array`,
 `string`

  ```cpp
  vector<int> ivec(10, -1);  // ten int elements,each initialized to -1
  list<string> svec(10,"hi!");  // ten strings; each element is "hi!"
  forward_list<int> ivec(10);  // ten elements, each initialized to 0
  deque<string> svec(10);  // ten elements, each an empty string

  array<int, 42> iarr; // type is: array that holds 42 ints, the size is part of its type;
  // each element of iarr is initialized to 0
  ```

  we cannot copy or assign objects of built-in array types (P114), there is no such restriction on `array` container, but the left and right-hand operands must have the same type.

* Associative containers:
  [`map`](https://en.cppreference.com/w/cpp/container/map),
  [`set`](https://en.cppreference.com/w/cpp/container/set),
  [`multimap`](https://en.cppreference.com/w/cpp/container/multimap),
  [`multiset`](https://en.cppreference.com/w/cpp/container/multiset),
  [`unordered_*`](https://en.cppreference.com/w/cpp/container#Unordered_associative_containers)

  * Ordered associative containers

    ```cpp
    map<string, size_t> word_count = {{"x", 0}, {"y", 0}};
    set<string> dict = {"a", "hi", "the"};

    word_count.insert({"foo", 1});
    word_count.emplace("bar", 1);  // the element is inserted (or constructed) only if an element with the given key is not already in word_count.
    word_count["foo"] = 2;

    c.erase(k);  // Removes every element with key k from c
    c.find(k);  // Returns an iterator to the (first) element with key k, or the off-the-end iterator
    c.count(k);  // Returns the number of elements with key k
    c.lower_bound(k);  // Returns an iterator to the first element with key not less than k
    ```

  * Unordered associative containers
    * Unordered associative containers use a hash function and the key type’s == operator. (P443)
    * The unordered containers are organized as a collection of buckets, each of which holds zero or more elements. These containers use a hash function to map elements to buckets.

    ```cpp
    unordered_map<string, size_t> word_count;
    unordered_set<string> dict;

    c.bucket_count();  // Number of buckets in use
    c.load_factor();  // Average number of elements per bucket. Returns float

    ```

  * [`pair`](https://en.cppreference.com/w/cpp/utility/pair) and [`tuple`](https://en.cppreference.com/w/cpp/utility/tuple)
    A `pair` is a specific case of a `tuple` with two elements.

    ```cpp
    pair<string, int> pir = make_pair("a", 1);
    tuple<string, int, double> tup = make_tuple("one", 1, 1.0);
    cout << pir.first << endl;
    cout << get<0>(tup) << endl;
    ```

  * [`bitset`](https://en.cppreference.com/w/cpp/utility/bitset): `bitset<n> b;` `b` has `n` bits; each bit is 0.

* When we initialize a container as a copy of another container, the **container type** and **element type** of both containers must be identical. (P335)
* Every container type supports the equality operators (== and !=); all the containers except the unordered associative containers also support the relational operators (>, >=, <, <=). (P340)
* [`string`](https://en.cppreference.com/w/cpp/string/basic_string) Operations (P360)
  additional ways to construct strings

  ```cpp
  string s(cstr, n);  // s is a copy of the first n chars of cstr
  string s(s2, pos2);  // s is a copy of string s2 from pos2
  string s(s2, pos2, len2)  // s is a copy of len2 chars from s2 starting at pos2
  ```

  `string` related

  ``` cpp
  to_string(val);  // return the string representation of val. val can be any arithmetic type
  stoi(s, pos, base);  // https://en.cppreference.com/w/cpp/string/basic_string/stol
  // pos is address of an integer to store the number of characters processed, default: pos = 0, base = 10

  s.size();  // return the number of char elements in the string
  s.find(str, start_pos);  // return position of the first character of the found substring or npos if no such substring is found, default: start_pos = 0
  s.substr(pos, count);  // return string containing the substring [pos, pos+count), defaut: pos = 0, count = npos
  ```

  `npos` is of type `string::size_type`  and is initialized with the value -1, it means `npos` is equal to the largest possible size any string could have

* Container adaptors:
  [`stack`](https://en.cppreference.com/w/cpp/container/stack),
  [`queue`](https://en.cppreference.com/w/cpp/container/queue) and
  [`priority_queue`](https://en.cppreference.com/w/cpp/container/priority_queue)

  * A container adaptor takes an existing container type and makes it act like a different type. (P369)
  * By default both `stack` and `queue` are implemented in terms of `deque`, and a `priority_queue` is implemented on a `vector`.

* [Member functions of containers](http://www.cplusplus.com/reference/stl/)

## [Generic Algorithms](https://en.cppreference.com/w/cpp/algorithm)

* [find()](https://en.cppreference.com/w/cpp/algorithm/find),
  [accumulate()](https://en.cppreference.com/w/cpp/algorithm/accumulate),
  [fill()](https://en.cppreference.com/w/cpp/algorithm/fill),
  [replace()](https://en.cppreference.com/w/cpp/algorithm/replace),
  [copy()](https://en.cppreference.com/w/cpp/algorithm/copy),
  [unique()](https://en.cppreference.com/w/cpp/algorithm/unique)
* [sort()](https://en.cppreference.com/w/cpp/algorithm/sort),
  [find_if()](https://en.cppreference.com/w/cpp/algorithm/find),
  [for_each()](https://en.cppreference.com/w/cpp/algorithm/for_each),
  [transform()](https://en.cppreference.com/w/cpp/algorithm/transform)
  * A predicate is an expression that can be called and that returns a value that can be used as a condition. (P386)

  * Lambda Expression as predicate

    ```cpp
    sort(words.begin(), words.end(),
        [](const string &a, const string &b)
          { return a.size() < b.size();});
    ```

* Lambda Expression
  * A lambda expression represents a callable unit of code. It can be thought of as an unnamed, inline function. (P388)

    `[capture list](parameter list) -> return type { function body }`

    ```cpp
    auto f = [] { return 42; };  // equals to: auto f = []() -> int { return 42; };
    cout << f() << endl;
    ```

  * Omitting the parentheses and the parameter list in a lambda is equivalent to specifying an empty parameter list
  * When omitting the return type, the return type is inferred from the type of the expression that is returned if the function body is just a return statement, otherwise, the return type is void.
  * Although a lambda may appear inside a function, it can use variables local to that function only if it specifies which variables it intends to use. (P390)

* 4 kinds of `callable object`:
  * functions (P201)
  * funtion pointers (P247)
  * classes that overload the function-call operator `()` (P571)
  * lambda expressions (P388)

## Memory management

> Global objects are allocated at program start-up and destroyed when the program ends.
> Local, automatic objects are created and destroyed when the block in which they are defined is entered and exited.
> Local static objects are allocated before their first use and are destroyed when the program ends. (P449)
---
> Dynamically allocated objects have a lifetime that is independent of where they are created; they exist until they are explicitly freed.

* Smart pointers:
  [unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr),
  [shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr),
  [weak_ptr](https://en.cppreference.com/w/cpp/memory/weak_ptr)

  A smart pointer acts like a regular pointer with the important exception that it automatically deletes the object to which it points.
  `shared_ptr` allows multiple pointers to refer to the same object, and `unique_ptr` “owns” the object to which it points. (P451)

  ```cpp
  shared_ptr<string> p1;  // shared_ptr that can point at a string
  shared_ptr<list<int>> p2;  // shared_ptr that can point at a list of ints
  ```

  `make_shared` function allocates and initializes an object in dynamic memory and returns a shared_ptr that points to that object.

  ```cpp
  shared_ptr<int> p1 = make_shared<int>(42);  // shared_ptr that points to an int with value 42
  auto p2 = make_shared<string>(10, '9');  // shared_ptr that points to a string with value 9999999999
  auto p3(p2);  // p3 and p2 point to the same object

  // Ways to define and change shared_ptrs P465
  shared_ptr<T> p(q);  // p manages the object to which the built-in pointer q points, q must from new,
  shared_ptr<T> p(q, d);  // if a callable object d is given, p uses d in place of `delete` to free q.
  shared_ptr<T> p(u);  // p assumes ownership from the unique_ptr u; makes u null
  p.reset();  // If p is the only shared_ptr pointing at its object, reset frees p’s existing object,
  p.reset(q);  // if the optional built-in pointer q is passed, makes p point to q, otherwise makes p null.
  ```

  Binding a weak_ptr to a shared_ptr does not change the reference count of that shared_ptr (P473)

  ```cpp
  auto p = make_shared<int>(42);
  weak_ptr<int> wp(p);  // wp weakly shares with p; use count in p is unchanged
  ```

* `new` and `delete`
  * [`new` expression](https://en.cppreference.com/w/cpp/language/new) allocates, and optionally initializes, an object in dynamic memory and returns a pointer to that object.
  * [`delete` expression](https://en.cppreference.com/w/cpp/language/delete) takes a pointer to a dynamic object, destroys that object, and frees the associated memory.
  * Deleting a pointer to memory that was not allocated by `new`, or deleting the same pointer value more than once, is undefined. (P460)
  * Dynamically allocated objects exist until they are freed.
  * A **dangling pointer** is one that refers to memory that once held an object but no longer does so. (P463)
  * we cannot implicitly convert a built-in pointer to a smart pointer; we must use the direct form of initialization. (P464)
  * we recommend using `make_shared` rather than `new`.

  ``` cpp
  int *p = new int(42);
  delete p;
  int *pa = new int[10]();
  delete [] pa;

  unique_ptr<int[]> up(new int[10]);  // up points to an array of ten uninitialized ints
  up[i];  // returns the object at position i in the array that u owns. u must point to an array.
  up.release();  // automatically uses delete[] to destroy its pointer
  // unlike unique_ptr, shared_ptrs provide no direct support for managing a dynamic array.
  ```

## Object-oriented

* Special member functions
  * Five special member functions: copy constructor, copy-assignment operator, move constructor, move-assignment operator, and destructor.
  * **explicit** constructors can be used only for direct initialization. (P296)
  * When we do not define a copy constructor for a class, the compiler synthesizes one. (P497)
  * The compiler generates a **synthesized copy-assignment operator** for a class if the class does not define its own. (P500)
  * The destructor takes no parameters, it cannot be overloaded.
  * The compiler will not let us define variables or create temporaries of a type that has a deleted destructor.
  * `= default` and `= delete` (P507)

    ```cpp
    struct NoCopy {
      NoCopy() = default;                         // use the synthesized default constructor
      NoCopy(const NoCopy &) = delete;            // no copy
      NoCopy &operator=(const NoCopy &) = delete; // no assignment
      ~NoCopy() = default;                        // use the synthesized destructor
      // other members
    };
    ```

* Dynamic binding happens **only** when a **virtual function** is called through a reference (or a pointer) to a base class. (P594)

  ```cpp
  class NoDerived final {/* */};  // final class cannot be derived

  class Base {
    public:
      void fun() { cout << "fun() in Base; "; }
      virtual void virtfun() { cout << "virtfun() in Base" << endl; }
      // virtual void pvirtfun() = 0;  // pure virtual function
      virtual ~Base() = default;  // virtual destructor needed if a base pointer pointing to a derived object is deleted
  };

  class Derived : public Base {
    public:
      void fun() { cout << "fun() in Derived; "; } // fun is not virtual; it hides fun in the base
      void virtfun() override { cout << "virtfun() in Derived" << endl; }
      // `override` is not necessary, if given, it must overide a virtual function in Base
      void pvirtfun() override {/* */};
  };

  void run(Base &b) {
      b.fun();     // statically bound, calls Base::fun()
      b.virtfun(); // dynamically bound
  }

  int main() {
      Derived d;
      run(d);              // output: fun() in Base; virtfun() in Derived
      Base *pb = &d;       // valid, derived-to-base conversion
      Base b = d;          // derived objects are “sliced down” when assigned to a base-type object
      b.virtfun();         // output: virtfun() in Base
      // Derived *pd = pb; // invalid
      Derived *pd = static_cast<Derived *>(pb); // valid, named casts (P162), only when you know its safe
  }
  ```

* Any nonstatic member function, other than a constructor, may be virtual. (P595)
* The **static type** of an expression is always known at compile time—it is the type with which a variable is declared or that an expression yields.
* The **dynamic type** is the type of the object in memory that the variable or expression represents. (P601)
* The dynamic type of an expression that is **neither a reference nor a pointer** is always the same as that expression’s static type.
* Conversions among classes related by inheritance (P604):
  * The conversion from derived to base applies **only** to pointer or reference types.
  * There is no implicit conversion from the base-class type to the derived type.
  * Like any member, the derived-to-base conversion may be inaccessible due to access controls.
* A class containing a **pure virtual function** is an abstract base class, We cannot (directly) create objects of a type that is an abstract base class.
* **BEST PRACTICE**: Aside from overriding inherited virtual functions, a derived class usually should not reuse names defined in its base class.

> KEY CONCEPT: NAME LOOKUP AND INHERITANCE (P619)
> Understanding how function calls are resolved is crucial to understanding inheritance
> in C++. Given the call `p->mem()` (or `obj.mem()`), the following four steps happen:  
>  
> * First determine the static type of `p` (or `obj`). Because we’re calling a member,that type must be a class type.  
> * Look for `mem` in the class that corresponds to the static type of `p` (or `obj`).
If `mem` is not found, look in the direct base class and continue up the chain of classes until `mem` is found or the last class is searched.
If `mem` is not found in the class or its enclosing base classes, then the call will not compile.  
> * Once `mem` is found, do normal type checking (§6.1, p. 203) to see if this call is legal given the definition that was found.  
> * Assuming the call is legal, the compiler generates code,which varies depending on whether the call is virtual or not:  
>  
>   * If mem is virtual and the call is made through a reference or pointer, then the compiler generates code to determine at run time which version to run based on the dynamic type of the object.  
>   * Otherwise,if the function is nonvirtual, or if the call is on an object (not a reference or pointer), the compiler generates a normal function call.

* Multiple Inheritance and Virtual Inheritance
  * The order in which base classes are constructed depends on the order in which they appear in the class derivation list. (P804)
  * By default, if the same base class appears more than once in the derivation, then the derived object will have more than one subobject of that type. (P810)
  * **Virtual inheritance** lets a class specify that it is willing to share its base class. The shared base-class subobject is called a **virtual base class**.(P811)

    ```cpp
    struct Base {
        void bar(int); // public by default
      protected:
        int ival;
    };

    struct Derived1 : virtual public Base {
        void bar(char); // public by default
        void foo(char);
      protected:
        char cval;
    };

    struct Derived2 : virtual public Base {
        void foo(int); // public by default
      protected:
        int ival;
        char cval;
    };

    class VMI : public Derived1, public Derived2 {
        void fun(int i) {
            bar(i);     // bar() of Derived1, the version in the derived class is given precedence over the shared virtual base class
            // foo(i);  // invalid, foo() is defined in both D1 and D2, direct access to it is ambiguous
            Derived1::foo(i);   // ok
            i = Derived2::cval; // ok
        }
    };
    ```

  * A class can have more than one virtual base class. In that case, the virtual subob- jects are constructed in left-to-right order as they appear in the derivation list. (P814)

* Polymorphism
  * Overloaded functions must differ in the number or the type(s) of their parameters. The compiler can figure out which function to call. (P231)
  * The fact that the static and dynamic types of references and pointers can differ is the cornerstone of how C++ supports polymorphism. (P605)

## MISC

* [Scope](https://en.cppreference.com/w/cpp/language/scope)
* [Use](https://www.studytonight.com/cpp/static-keyword.php) of [`static`](https://en.cppreference.com/w/cpp/keyword/static) keyword.
* Assignmnet and initialization are different, **copy initialization** and **direct initialization** are different. P(497)
* [ASCII](https://en.wikipedia.org/wiki/ASCII) encodes 128 specified characters into seven-bit integers
* `EOF`: `Ctrl+Z` in Windows, `Ctrl+D` in Linux/macOS
* Variables defined **outside any function** are initialized to zero, which defined inside a function are uninitialized
* A constant expression is an expression whose value cannot change and that can be evaluated at compile time. (P65)
* The number of elements in an array is part of the array’s type, the dimension must be known at compile time. (P113)
* The array returned by `s.c_str()` is not guaranteed to be valid indefinitely. Any subsequent use of s that might change the value of s can invalidate this array. (P125)
* We can write a function that takes an unknown number of arguments of a single type by using an `initializer_list` parameter. (P220)
* If a destructor does an operation that might throw, it should wrap that operation in a try block and handle it locally to the destructor. (P774)
* Calling a destructor destroys an object but does not free the memory. (P824)
* [`volatile`](https://en.cppreference.com/w/cpp/keyword/volatile) Type qualifier that signifies to the compiler that a variable might be changed outside the direct control of the program. It is a signal to the compiler that it may not perform certain optimizations. (P856)
