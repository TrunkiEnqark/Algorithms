use std::fmt;

pub struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

impl<T> Node<T> {
    pub fn new(data: T) -> Box<Self> {
        Box::new(Node {
            data: data,
            next: None,
        })
    }
}

pub struct SinglyLinkedList<T> {
    head: Option<Box<Node<T>>>,
}

impl<T> SinglyLinkedList<T> {
    pub fn new() -> Self {
        SinglyLinkedList { head: None }
    }

    pub fn len(&self) -> usize {
        let mut length: usize = 0;
        let mut current_node = &self.head;
        while let Some(node) = current_node {
            length += 1;
            current_node = &node.next;
        }
        length
    }

    pub fn push_front(&mut self, data: T) {
        let new_node = Box::new(Node {
            data,
            next: self.head.take(),
        });
        self.head = Some(new_node);
    }

    pub fn pop_front(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            node.data
        })
    }

    pub fn push_back(&mut self, data: T) {
        let new_node = Node::new(data);
        match self.head.as_mut() {
            None => self.head = Some(new_node),
            Some(mut current) => {
                while current.next.is_some() {
                    current = current.next.as_mut().unwrap();
                }
                current.next = Some(new_node);
            }
        }
    }

    pub fn pop_back(&mut self) {
        
    }
}

impl<T: fmt::Display> fmt::Display for SinglyLinkedList<T> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "[")?;
        let mut current = &self.head;
        while let Some(node) = current {
            write!(f, "{}", node.data)?;
            current = &node.next;
            if current.is_some() {
                write!(f, ", ")?;
            }
        }
        write!(f, "]")
    }
}