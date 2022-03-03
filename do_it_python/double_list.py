# circular double list

from __future__ import annotations
from typing import Any, Type


class Node:
    """node class for circular double list """

    def __init__(self, data: Any = None, prev: Node = None, next: Node = None) -> None:
        """Initialization"""
        self.data = data
        self.prev = prev or self  # front of pointer
        self.next = next or self  # back of pointer


class DoubleLinkedList:
    """circular double list class """

    def __init__(self) -> None:
        """Initialization"""
        self.head = self.current = Node()  # create dummy node
        self.no = 0

    def __len__(self) -> int:
        """return number of linked list"""
        return self.no

    def is_empty(self) -> bool:
        """리스트가 비었는지 확인 빈경우-> true"""
        return self.head.next is self.head

    def search(self, data: Any) -> Any:
        """데이터와 값이 같은 노드를 검색"""
        cnt = 0
        ptr = self.head.next  # scanning node
        while ptr is not self.head:  # 리스트가 비어있지 않다면
            if data == ptr.data:
                self.current = ptr
                return cnt  # 검색성공
            cnt += 1
            ptr = ptr.next  # 뒤쪽 노드에 주목
        return -1  # search fail

    def __contains__(self, data: Any) -> bool:
        """연결리스트에 데이터가 포함되어 있는지 판단"""
        return self.search(data) >= 0

    def print_current_node(self) -> None:
        """print current node """
        if self.is_empty():
            print('주목 노드는 없습니다.')
        else:
            print(self.current.data)

    def print(self) -> None:
        """print all node"""
        ptr = self.head.next  # dummy node of back node
        while ptr is not self.head:
            print(ptr.data)
            ptr = ptr.next

    def print_reverse(self) -> None:
        """print all node reverse"""
        ptr = self.head.prev  # 더미노드의 앞쪽 노드
        while ptr is not self.head:
            print(ptr.data)
            ptr = ptr.prev

    def next(self) -> bool:
        """주목 노드를 한칸 뒤로 이동"""
        if self.is_empty() or self.current.next is self.head:  # if list is empty
            return False
        self.current = self.current.next
        return True

    def prev(self) -> bool:
        """주목 노드를 한칸 앞으로 이동"""
        if self.is_empty or self.current.prev is self.head:
            return False
        self.current = self.current.prev
        return True

    def add(self, data: Any) -> None:
        """주목 노드 바로 뒤에 노드를 삽입"""
        node = Node(data, self.current, self.current.next)
        self.current.next.prev = node
        self.current.next = node
        self.current = node
        self.no += 1

    def add_last(self, data: Any) -> None:
        """맨 뒤에 노드를 삽입"""
        self.current = self.head.prev  # 꼬리 노드 head.prev의 바로 뒤에 삽입
        self.add(data)

    def remove_current_node(self) -> None:
        """주목 노드를 삭제"""
        if not self.is_empty():
            self.current.prev.next = self.current.next
            self.current.next.prev = self.current.prev
            self.current = self.current.prev
            self.no -= 1
            if self.current is self.head:
                self.current = self.head.next

    def remove(self, p: Node) -> None:
        """ delete node p"""
        ptr = self.head.next

        while ptr is not self.head:
            if ptr is p:  # p 발견
                self.current = p
                self.remove_current_node()
                break
            ptr = ptr.next

    def remove_first(self) -> None:
        """delete head node"""
        self.current = self.head.next  # 머리노드 head.next를 삭제
        self.remove_current_node()

    def remove_last(self) -> None:
        """delete tail node """
        self.current = self.head.prev  # 꼬리노드 head.prev를 삭제 ?? head.next.prev가 돼야하지 않나
        self.remove_current_node()

    def clear(self) -> None:
        """delete all node"""
        while not self.is_empty():  # 리스트 전체가 빌때까지
            self.remove_first()
        self.no = 0

    def __iter__(self) -> DoubleLinkedListIterator:
        """return iterator"""
        return DoubleLinkedListIterator(self.head)

    def __reversed__(self) -> DoubleLinkedListReverseIterator:
        """내림차순 이터레이터를 반환"""
        return DoubleLinkedListReverseIterator(self.head)


class DoubleLinkedListIterator:
    """DoubleLinkedListIterator의 이터레이터용 클래스"""

    def __init__(self, head: Node):
        self.head = head
        self.current = head.next

    def __iter__(self) -> DoubleLinkedListIterator:
        return self

    def __next__(self) -> Any:
        if self.current is self.head:
            raise StopIteration
        else:
            data = self.current.data
            self.current = self.current.next
            return data


class DoubleLinkedListReverseIterator:
    """DoubleLinkedListIterator의 내림차순 이터레이터클래스 """

    def __init__(self, head: Node):
        self.head = head
        self.current = head.prev

    def __iter__(self) -> DoubleLinkedListReverseIterator:
        return self

    def __next__(self) -> Any:
        if self.current is self.head:
            raise StopIteration
        else:
            data = self.current.data
            self.current = self.current.prev
            return data
