mod linkedlist;
use linkedlist::LinkedList as LinkedList;

fn main() {
    let mut list = LinkedList::new();
    println!("{}", list);
    for i in 1..10 {
        list.append(i);
    }
    //list.next().append(10)
    println!("Size of list: {}", list.size());
    println!("{}", list);
}
