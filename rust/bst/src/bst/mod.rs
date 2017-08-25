use std::fmt;

mod node;
use self::node::Node as Node;

pub struct BST<T> {
   size: u32,
   root: Node<T>
}

impl <T: Ord> BST<T> {
   pub fn new() -> BST<T> {
      BST{ size: 0, root: Node::Nil }
   }
   pub fn insert(&mut self, v: T) -> bool {
      if self.empty() {
          self.root = Node::Leaf(v);
          self.size = self.size + 1;
          return true;
      }
      return false;
          
      
   }
   pub fn empty(&self) -> bool {
      self.size == 0
   }
}

impl <T: fmt::Display> fmt::Display for BST<T> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "[{}]", self.root)
    }
}


