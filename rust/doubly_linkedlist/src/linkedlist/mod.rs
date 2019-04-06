use std::fmt;

use std::cell::RefCell;
use std::rc::{Rc, Weak};

pub enum Cons<T> {
	//Cons( Data, next, prev)
	Some(T),
	Cons(T, Rc<RefCell<Cons<T>>>, Weak<RefCell<Cons<T>>>),
}

impl <T> Cons<T> {
	pub fn new(v: T) -> Self {
		Cons::Some(v)
	}
	pub fn append(v: T) -> Self {
		
	}
	
}

pub struct LinkedList<T> {
	root: Cons<T>
}