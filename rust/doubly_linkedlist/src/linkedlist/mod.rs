use std::fmt;

use std::cell::RefCell;
use std::rc::{Rc, Weak};

pub struct Cons<T> {
	//Cons( Data, next, prev)
	pub entry: T,
	pub prev: Option<Weak<RefCell<Cons<T>>>>,
	pub next: Option<Rc<RefCell<Cons<T>>>>,
}

impl <T> Cons<T> {
	pub fn new(v: T) -> Self {
		Self { entry: v, prev: None, next: None }
	}
	
	pub fn append(prev: &mut Rc<RefCell<Cons<T>>>, data: T) -> Option<Rc<RefCell<Cons<T>>>> {
		//
		// Check if the node is a tail
		match &mut prev.borrow_mut().next {
			Some(next) => {
				let mut e = Self { entry: data, prev: Some(Rc::downgrade(&prev)), next: Some(next.clone()) };
				let rc = Rc::new(RefCell::new(e));
				prev.borrow_mut().next = Some(rc.clone());
				next.borrow_mut().prev = Some(Rc::downgrade(&rc));
				Some(rc)
			}
			None => {
				//let mut e = Cons::new(data);
				//e.prev = Some(Rc::downgrade(&prev));
				let mut e = Self { entry: data, prev: Some(Rc::downgrade(&prev)), next: None };
				let rc = Rc::new(RefCell::new(e));
				prev.borrow_mut().next = Some(rc.clone());
				Some(rc)
			}
		}
	}
}

pub struct LinkedList<T> {
	head: Option<Rc<RefCell<Cons<T>>>>,
	tail: Option<Rc<RefCell<Cons<T>>>>
}

impl <T> LinkedList<T> {
	pub fn new() -> Self {
		Self { head: None, tail: None }
	}
	pub fn append( &mut self, entry: T ) {
		match &mut self.tail {
			Some(tail) => { Cons::append(tail, entry); }
			None => {
				let e = Rc::new(RefCell::new(Cons::new(entry)));
				self.head = Some(e.clone());
            	self.tail = Some(e);
			}
		}
	}
}