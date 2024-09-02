struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

struct SinglyLinkedList<T> {
    head: Option<Box<Node<T>>>,
}

impl<T> SinglyLinkedList<T> {
    fn new() -> Self {
        SinglyLinkedList { head: None }
    }

    fn push_front(&mut self, data: T) {
        let new_node = Box::new(Node {
            data,
            next: self.head.take(),
        });
        self.head = Some(new_node);
    }

    fn pop_front(&mut self, data: T) -> Option<&T> {
        self.head.take().map(|node| {
            self.head = node.next,
            node.data
        })
    }

    
}