mod linkedlist;
use linkedlist::LinkedList as LinkedList;

fn main() {
    let mut list = LinkedList::new();
    println!("{}", list);
    for i in 1..10 {
        list.append(i);
    }
    println!("{}", list);
}
