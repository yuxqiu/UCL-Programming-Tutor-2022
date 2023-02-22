## Week16


### Syntax

1. A combination of a lot of programming languages and different paradigms

2. Examples
   1. `use`
   2. `println!`
   3. Variables: Mutability and Immutability
   4. IO: error checking
   5. `match`: does this remind you of Haskell?
   6. Exit Code?: we will look at this later

3. [Variables](https://doc.rust-lang.org/stable/book/ch03-01-variables-and-mutability.html)
   1. Mutability and Immutability
   2. Const and Type: compile time constant
   3. Shadowing

4. [Data Type](https://doc.rust-lang.org/stable/book/ch03-02-data-types.html)
   1. scalar type
   2. compound type (tuple, array)
   3. Safe by default

5. [Functions](https://doc.rust-lang.org/stable/book/ch03-03-how-functions-work.html)
   1. Syntax
   2. Parameters
   3. Return
   4. Expression and Statement
      1. Correct an mistake I made in last week

6. [Control Flow](https://doc.rust-lang.org/stable/book/ch03-05-control-flow.html)
   1. `if`
   2. `loop`
   3. `while`
   4. `for` with collections

7. Exit Code (Optional)
   1. [How to cleanly end the program with an exit code?](https://stackoverflow.com/questions/30281235/how-to-cleanly-end-the-program-with-an-exit-code)
   2. `std::process::exit`: pros and cons
   3. `Termination` trait: [Trait std::process::Termination](https://doc.rust-lang.org/stable/std/process/trait.Termination.html)
   4. `ExitCode`: [Struct std::process::ExitCode](https://doc.rust-lang.org/stable/std/process/struct.ExitCode.html)


### Semantics

1. [Ownership](https://doc.rust-lang.org/stable/book/ch04-01-what-is-ownership.html) (Can you see the following rules in C++?)
   1. Each value in Rust has an owner.
   2. There can only be one owner at a time.
   3. When the owner goes out of scope, the value will be dropped.
2. Example: `String`
   1. Move by default (unless you have `Copy` trait for the type)
   2. Move and the transfers the ownership
   3. `Clone`
   4. Ownership and Functions
3. [References and Borrowing](https://doc.rust-lang.org/stable/book/ch04-02-references-and-borrowing.html) (Completely different from C++?)
   1. Reference
   2. Mutable Reference
      1. [String doc](https://doc.rust-lang.org/std/string/struct.String.html)
   3. Return a reference
      1. Dangling Reference
      2. **Lifetime** Annotation
4. Rationale
   1. Why only 1 mutable ref
   2. Why many immutable refs


### Smart Pointers

1. Let's Go Back to C++
   1. `unique_ptr`
   2. `shared_ptr`
   3. `weak_ptr`
2. In Rust, we have these (with examples)
   1. `Box`: [Using Box<T> to Point to Data on the Heap](https://doc.rust-lang.org/stable/book/ch15-01-box.html)
   2. `Rc`: [Rc<T>, the Reference Counted Smart Pointer](https://doc.rust-lang.org/stable/book/ch15-04-rc.html)
   3. `RefCell`: [RefCell<T> and the Interior Mutability Pattern](https://doc.rust-lang.org/stable/book/ch15-05-interior-mutability.html)
   4. `Weak`: [Reference Cycles Can Leak Memory](https://doc.rust-lang.org/stable/book/ch15-06-reference-cycles.html)
   5. `Arc` (for multithreading)


### A Glimpse at Struct and Trait

1. [Define and Initialize Struct](https://doc.rust-lang.org/stable/book/ch05-01-defining-structs.html)
2. [Methods](https://doc.rust-lang.org/stable/book/ch05-03-method-syntax.html)
   1. `impl`
   2. static and instance methods
3. [Trait](https://doc.rust-lang.org/stable/book/ch10-02-traits.html)
   1. Interface?
   2. How to implement Trait for your custom types
   3. Common Traits
      1. `Copy` and `Clone`
      2. `vector` and `Index`


### What's More

1. Error Handling (Refer to Reference-4 for more details.)
   1. Optional
   2. Result
   3. Enum Type with Value
2. Object Oriented Rust (Refer to Reference-4 for more details.)
   1. Composition
   2. Can you implement your own linked list (singly and doubly) in Rust?
      People often claim that it's hard to implement the Linked List in Rust given the ownership model.
3. Traits and Generics (Refer to Reference-4 for more details.)
   1. Define your generic type
   2. Define your generic type bounded by Trait
   3. `dyn`
4. Type System
5. Multi-Threading (`Send` and `Sync` Trait are essential)
   1. [Send and Sync](https://stackoverflow.com/questions/59428096/understanding-the-send-trait)
6. When does move fail? (Check References-2)
   1. [Pin](https://doc.rust-lang.org/std/pin/index.html)
7. How does ownership/borrowing model benefit the multi-threading? (Check Reference-3)


### References

The design of this note is based on:
1. [The Rust Programming Language](https://doc.rust-lang.org/stable/book/) by Steve Klabnik and Carol Nichols
2. [Rust – What made it “click” for me (Ownership & memory internals)](https://deavid.wordpress.com/2021/06/06/rust-what-made-it-click-for-me-ownership-memory-internals/)
   1. There are some errors, but there are many concepts that deserve your attention.
3. [Rust: A unique perspective](https://limpet.net/mbrubeck/2019/02/07/rust-a-unique-perspective.html)
4. [CS 110L: Safety in Systems Programming](https://reberhardt.com/cs110l/spring-2020/)