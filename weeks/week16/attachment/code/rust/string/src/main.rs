fn main() {
    let mut s = String::from("hello");
    s.push_str(", world!"); // push_str() appends a literal to a String

    println!("{}", s); // This will print `hello, world!`

    {
        let _s = String::from("hello"); // s is valid from this point forward
                                        // do stuff with _s
    } // this scope is now over, and _s is no
      // longer valid

    {
        let s1 = String::from("hi");
        let s2 = s1;

        // we cannot do this because s1 is moved
        // println!("{}, world!", s1);
        println!("{}, world!", s2);
    }

    {
        let s1 = String::from("hi");
        let s2 = s1.clone();
        println!("{}, world!", s2);
    }

    {
        let x = 5;
        let y = x;

        println!("x = {}, y = {}", x, y);
    }

    // let mut sref: &String;
    // {
    //     let s2 = String::from("hi");
    //     sref = _take_two_and_return_a_reference(&s2, &s);
    // }
    // println!("{sref}");

}

fn _takes_ownership(some_string: String) {
    // some_string comes into scope
    println!("{}", some_string);
} // Here, some_string goes out of scope and `drop` is called. The backing
  // memory is freed.

fn _makes_copy(some_integer: i32) {
    // some_integer comes into scope
    println!("{}", some_integer);
} // Here, some_integer goes out of scope. Nothing special happens.

// This function takes a String and returns one
fn _takes_and_gives_back(a_string: String) -> String {
    // a_string comes into
    // scope

    a_string // a_string is returned and moves out to the calling function
}

fn _calculate_length(s: String) -> (String, usize) {
    let length = s.len(); // len() returns the length of a String

    (s, length)
}

// fn _return_a_dangling_reference() -> &String {
//     let s = String::from("hello");
//     &s
// }

fn _take_and_return_a_reference(s: &String) -> &String {
    s
}

fn _take_two_and_return_a_reference<'a, 'b>(_s1: &'a String, _s2: &'b String) -> &'a String {
    _s1
}
