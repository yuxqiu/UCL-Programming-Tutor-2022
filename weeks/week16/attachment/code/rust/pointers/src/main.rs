use std::{
    borrow::BorrowMut,
    cell::RefCell,
    ops::{Deref, DerefMut},
    rc::Rc,
};

fn main() {
    let mut b = Box::new(5);
    println!("b = {}", b);

    let rc1 = Rc::new(5);
    let rc2 = Rc::clone(&rc1);
    let _rc3 = rc2.clone();

    let b1 = b.deref_mut();
    take_mut(b1);
    let b2 = b.borrow_mut();
    take_mut(b2);
    let b3 = &mut b;
    take_mut(b3);

    // immutability
    // take_mut(&mut rc1);

    // Rc RefCell pattern
    // Enforce ownership rule at runtime
    let rcref = Rc::new(RefCell::new(5));
    let _rcref2 = rcref.clone();

    let _dummy = _rcref2.deref().borrow_mut();
    // this causes a panic
    // let _dummy2 = _rcref2.deref().borrow_mut();
}

fn take_mut(num: &mut i32) {
    *num = 1;
}
