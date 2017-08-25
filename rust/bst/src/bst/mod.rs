mod node;
use self::node::Node;
pub struct BST<T> {
   size: u32,
   root: Node<T>
}
