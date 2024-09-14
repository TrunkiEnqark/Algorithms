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

    pub fn is_empty(&self) -> bool {
        self.head.is_none()
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

    pub fn pop_back(&mut self) -> Option<T> {
        match self.head.as_mut() {
            None => None,
            Some(mut current) if current.next.is_none() => {
                self.head.take().map(|node| node.data)
            }
            Some(mut current) => {
                while current.next.as_ref().unwrap().next.is_some() {
                    current = current.next.as_mut().unwrap();
                }
                current.next.take().map(|node| node.data)
            }
        }
    }

    pub fn peek_front(&mut self) -> Option<&T> { // return immutable reference
        self.head.as_ref().map(|node| &node.data)
    }

    pub fn peek_front_mut(&mut self) -> Option<&mut T> { // return mutable reference
        self.head.as_mut().map(|node| &mut node.data)
    }

    pub fn peek_back(&self) -> Option<&T> { // return immutable reference
        let mut current = self.head.as_ref()?;
        while let Some(next) = current.next.as_ref() {
            current = next;
        }
        Some(&current.data)
    }

    pub fn peek_back_mut(&mut self) -> Option<&mut T> { // return mutable reference
        let mut current = self.head.as_mut()?;
        while let Some(next) = current.next.as_mut() {
            current = next;
        }
        Some(&mut current.data)
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