# Implementing a Linked List with pointers

from __future__ import annotations
from typing import Any, Type


class Node:
    """node class for linked list"""

    def __init__(self, data: Any = None, next: Node = None):
        """Initialization"""
        self.data = data
        self.next = next


class LinkedList:
    """Linked List Class"""

    def __init__(self) -> None:
        """Initialization"""
        self.no = 0  # number of node
        self.head = None  # head node
        self.current = None  # attention node

    def __len__(self) -> int:
        """Returns the number of nodes in a linked list"""
        return self.no

    def search(self, data: Any) -> int:
        """Search for nodes with the same value as the data"""
        cnt = 0
        ptr = self.head
        while ptr is not None:
            if ptr.data == data:
                self.current = ptr
                return cnt
            cnt += 1
            ptr = ptr.next
        return -1

    def __contains__(self, data: Any) -> bool:
        """Check Linked List contains data"""
        return self.search(data) >= 0

    def add_first(self, data: Any) -> None:
        """Insert the node in the front"""
        ptr = self.head  # head before insert
        self.head = self.current = Node(data, ptr)
        self.no += 1

    def add_last(self, data: Any):
        """Insert the node in the tail"""
        if self.head is None:  # if list is empty,
            self.add_first(data)  # insert the node in the front
        else:
            ptr = self.head
            while ptr.next is not None:
                ptr = ptr.next
            ptr.next = self.current = Node(data, None)
            self.no += 1

    def remove_first(self) -> None:
        """remove the front node"""
        if self.head is not None:  # if list is not empty,
            self.head = self.current = self.head.next
            self.no -= 1
        # ? 비어 있는 경우 예외처리

    def remove_last(self):
        """delete tail node"""
        if self.head is not None:
            if self.head.next is None:  # if node is only
                self.remove_first()
            else:
                ptr = self.head  # node that being scan 스캔중인 노드
                pre = self.head  # the front of the node that being scan 스캔중인 노드의 앞쪽 노드

                while ptr.next is not None:
                    pre = ptr
                    ptr = ptr.next
                pre.next = None
                self.current = pre
                self.no -= 1

    def remove(self, p: None) -> None:
        """delete node p """
        if self.head is not None:
            if p is self.head:  # if p == head node
                self.remove_first()  # delete head node
            else:
                ptr = self.head

                while ptr.next is not p:
                    ptr = ptr.next
                    if ptr is None:
                        return  # ptr doesn't exist in the list

                ptr.next = p.next
                self.current = ptr
                self.no -= 1

    def remove_current_node(self) -> None:
        """ delete current node"""
        self.remove(self.current)

    def clear(self) -> None:
        """delete ALL"""
        while self.head is not None:  # still all empty 전체가 빌때까지
            self.remove_first()
        self.current = None
        self.no = 0

    def next(self) -> bool:
        """move current node back one space"""
        if self.current is None or self.current.next is None:
            return False
        self.current = self.current.next
        return True

    def print_current_node(self) -> None:
        """print current node"""
        if self.current is None:
            print('주목 노드가 존재하지 않습니다.')
        else:
            print(self.current.data)

    def print(self) -> None:
        """print all node"""
        ptr = self.head

        while ptr is not None:
            print(ptr.data)
            ptr = ptr.next

    def __iter__(self) -> LinkedListIterator:
        """return iterator"""
        return LinkedListIterator(self.head)


class LinkedListIterator:
    """iterator class of class LinkedListIterator"""

    def __init__(self, head: Node):
        self.current = head

    def __iter__(self) -> LinkedListIterator:
        return self

    def __next__(self) -> Any:
        if self.current is None:
            raise StopIteration
        else:
            data = self.current.data
            self.current = self.current.next
            return data
