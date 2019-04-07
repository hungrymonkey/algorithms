use std::fmt;
use std::cmp::{Ordering};
use std::rc::Weak;

pub enum Node<T> {
   Leaf(T),
   //Parent, Left, Right
   Node(T, Option<Weak<Node<T>>>, Box<Node<T>>, Box<Node<T>>),
   Nil
}
impl<T : Eq + Ord> PartialEq for Node<T> {
   fn eq(&self, other: &Node<T>) -> bool {
      match (self.get(), other.get()) {
         (None, None) => true,
         (Some(l), Some(r)) => l == r,
         _ => false
      }
   }
}
impl<T: Ord> Eq for Node<T> {

}

impl<T: Ord> PartialOrd for Node<T> {
   fn partial_cmp(&self, other: &Node<T>) -> Option<Ordering> {
        Some(self.cmp(other))
   }
}

    
impl<T : Ord> Ord for Node<T> {
   fn cmp(&self, other: &Node<T>) -> Ordering {
      match (self.get(), other.get()) {
         (None, None) => Ordering::Equal,
         (None, Some(e)) => Ordering::Less,
         (Some(e), None) => Ordering::Greater,
         (Some(l), Some(r)) => if l > r { Ordering::Greater } else { Ordering::Less }
      }
   }
}
impl <T : Ord> Node<T> {
   pub fn new(v: T) -> Node<T> {
      Node::Leaf(v)
   }
   pub fn push(&mut self, v: T) -> Node<T> {
      
      Node::Nil
   }
   pub fn get(&self) -> Option<T> {
      match self {
         Node::Nil => None,
         Node::Leaf(e) => Some(*e),
         Node::Node(e,_,_,_) => Some(*e)
      }
   }
   pub fn cmp(&self, other: &Self) -> Ordering {
      match (self.get(), other.get()) {
         (None, None) => Ordering::Equal,
         (None, Some(e)) => Ordering::Less,
         (Some(e), None) => Ordering::Greater,
         (Some(l), Some(r)) => if l > r { Ordering::Greater } else { Ordering::Less }
      }
   }
   
}
impl <T: fmt::Display> fmt::Display for Node<T>{
   fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
      match *self {
         Node::Leaf(ref d) => write!(f, "{},", d),
         Node::Node(ref d, _, ref l, ref r) => write!(f, "{}{},{}", l, d, r),
         Node::Nil => write!(f, "{}", "")
      }
   }
}

