pub enum Node<T> {
   Node { v: T, p: Box<Node<T>> , l: Box<Node<T>>, r: Box<Node<T>> },
   None
}

