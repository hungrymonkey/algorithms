use std::fmt;
use std::cell::RefCell;
use std::rc::{Rc  };


mod node;
use self::node::{Node, NodeRef};

pub struct BST<T> {
   size: u32,
   root: Node<T>,
}

impl <T: Ord> BST<T> {
   pub fn new() -> BST<T> {
      BST{ size: 0, root: Node::Nil }
   }
   pub fn insert(&mut self, v: T) -> bool {
      
      match &self.root {
         Node::Nil => {
            self.root = 
               Node::Node(
                  v, None, None, None
               );
            self.size += 1;
            return true;
         },
         Node::Node(e, None, None, None) => {

         },
         _ => {

         }
      }
      return false;
          
      
   }
   pub fn empty(&self) -> bool {
      self.size == 0
   }
}
/*
impl <T: fmt::Display> fmt::Display for BST<T> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "[{}]", self.root)
    }
}
*/

