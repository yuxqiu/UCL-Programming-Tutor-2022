use std::ops::Index;

struct Pair {
    x: i32,
    y: i32,
}

impl Pair {
    fn new() -> Self {
        Pair { x: 0, y: 0 }
    }
}

impl Copy for Pair {}

impl Clone for Pair {
    fn clone(&self) -> Pair {
        *self
    }
}

fn main() {
    let mut v: Vec<i32> = Vec::new();
    v.push(1);
    v.push(2);

    println!("First element is: {}", v[0]);
    println!("Second element is: {}", v[1]);
    // println!("Third element? {}", v[2]);

    let _v_from_array = vec![1, 2, 3, 4, 5];

    // how does the square bracket work?
    // Index trait
    println!("First element is: {}", *v.index(0));

    let p1 = Pair { x: 1, y: 2 };
    let p2 = p1;
    let _p3 = Pair::new();
    println!("{} = {}", p1.x, p2.x);
    println!("{} = {}", p1.y, p2.y);

    // Can we implement this for our type
    // Yes
    println!("First element is {}", p1[0]);
    println!("Second element is {}", p1[1]);
    // println!("Third element? {}", p1[2]);
}

impl Index<i32> for Pair {
    type Output = i32;

    fn index(&self, index: i32) -> &Self::Output {
        match index {
            0 => &self.x,
            1 => &self.y,
            _ => panic!("Got index {}. Expected either 0 or 1.", index),
        }
    }
}
