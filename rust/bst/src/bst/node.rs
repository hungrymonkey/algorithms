use std::fmt;

pub enum Node<T> {
   Leaf(T),
   Node(T, Box<Node<T>>, Box<Node<T>>, Box<Node<T>>),
   Nil
}


impl <T> Node<T> {
   pub fn new(v: T) -> Node<T>{
      Node::Leaf(v)
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

