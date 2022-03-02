# make Linked List with cursor


from __future__ import annotations
from typing import Any, Type

Null = -1


class Node:
    """node class for linked list"""

    def __init__(self, data=Null, next=Null, dnext=Null):
        """Initailization"""

        self.data = data
        self.next = next  # pointer at the back of the list 리스트의 뒤쪽 포인터
        self.dnext = dnext  # pointer at the back of the pre list 프리 리스트의 뒤쪽 포인터


class ArrayLinkedList:
    """linked list class(cursor v)"""

    def __init__(self, capacity: int):
        """initialization"""
        self.head = Null  # head node
        self.current = Null  # current node
        self.max = Null  # 사용중인 꼬리 레코드
        self.deleted = Null  # head node of pre-list
        self.capacity = capacity  # size of list
        self.n = [Node()] * self.capacity  # body of list
        self.no = 0

    def __len__(self) -> int:
        """return linked list length """
        return self.no

    def get_insert_index(self):
        """Find the index of the record to be inserted next  다음에 삽입할 레코드의 인덱스를 구함"""
        if self.deleted == Null:  # if deleted record is not exist
            if self.max + 1 < self.capacity:
                self.max += 1
                return self.max  # use new record
            else:
                return Null  # oversized

        else:
            rec = self.deleted
            # Take out the first rec from the pre-list 프리 리스트에서 맨 앞 rec 꺼내기
            self.deleted = self.n[rec].dnext
            return rec

        def delete_index(self, idx: int) -> None:
            """레코드, idx를 프리리스트에 등록"""
            if self.deleted == Null:  # 삭제 레코드는 존재하지 않음
                self.deleted = idx
                self.n[idx].dnext = Null  # idx를 프리리스트의 맨 앞에 등록
            else:
                rec = self.deleted
                self.deleted = idx  # idx를 프리리스트의 맨 앞에 삽입
                self.n[idx].dnext = rec

        def search(self, data: Any) -> int:
            """data와 값이 같은 노드를 검색"""
            cnt = 0
            ptr = self.head  # 현재 스캔 중인 노드
            while ptr != Null:
                if self.n[ptr].data == data:
                    self.current = ptr  # search success
                    return cnt
                cnt += 1
                ptr = self.n[ptr].next  # 뒤쪽 노드에 주목
        return Null  # search fail

        def __contains__(self, data: Any) -> bool:
            """연결 리스트에 data가 포함되어 있는지 확인"""
            return self.search(data) >= 0

        def add_first(self, data: Any):
            """insert to the head node"""
            ptr = self.head  # head node before insert
            rec = self.get_insert_index()
            if rec != Null:
                self.head = self.current = rec  # rec번째 레코드에 삽입
                self.n[self.head] = Node(data, ptr)
                self.no += 1

        def add_last(self, data: Any) -> None:
            """insert to the tail node"""
            if self.head == Null:  # if list is empty
                self.add_first(data)
            else:
                ptr = self.head
                while self.n[ptr].next != Null:
                    ptr = self.n[ptr].next
                rec = self.get_insert_index()

                if rec != Null:  # rec번째 레코드에 삽입
                    self.n[ptr].next = self.current = rec
                    self.n[rec] = Node(data)
                    self.no += 1

        def remove_first(self) -> None:
            """delete head node"""
            if self.head != Null:  # if list is not empty
                ptr = self.n[self.head].next
                self.delete_index(self.head)
                self.head = self.current = ptr
                self.no -= 1

        def remove_last(self) -> None:
            """delete tail node"""
            if self.head != Null:
                if self.n[self.head].next == Null:  # 노드가 1개 뿐이면
                    self.remove_first()
                else:
                    ptr = self.head  # 스캔 중인 노드
                    pre = self.head  # 스캔 중인 노드의 앞쪽 노드

                    while self.n[ptr].next != Null:
                        pre = ptr
                        ptr = self.n[ptr].next
                    self.n[pre].next = Null  # pre는 삭제한 뒤의 꼬리 노드
                    self.delete_index(ptr)
                    self.current = pre
                    self.no -= 1

        def remove(self, p: int) -> Node:
            """delete p record"""
            if self.head != Null:
                if p == self.head:
                    self.remove_first()
                else:
                    ptr = self.head

                    while self.n[ptr].next != p:
                        ptr = self.n[ptr].next
                        if ptr == Null:
                            return  # p는 리스트에 존재하지 않음

                    self.n[ptr].next = Null
                    self.delete_index(p)
                    self.n[ptr].next = self.n[p].net
                    self.current = ptr
                    self.no -= 1

        def remove_current_node(self) -> None:
            """delete current node"""
            self.remove(self.current)

        def clear(self) -> None:
            """delete all node"""
            while self.head != Null:  # 리스트 전체가 빌때까지
                self.remove_first()
            self.current = Null

        def next(self) -> bool:
            """주목 노드를 한칸 뒤로 이동"""
            if self.current == Null or self.n[self.current].next == Null:
                return False  # 이동할 수 없음
            self.current = self.n[self.current].next
            return True

        def print_current_node(self) -> None:
            """ print current node """
            if self.current == Null:
                print('주목 노드가 없습니다.')
            else:
                print(self.n[self.current].data)

        def print(self) -> None:
            """print all node"""
            ptr = self.head

            while ptr != Null:
                print(self.n[ptr].data)
                ptr = self.n[ptr].next

        def dump(self) -> None:
            """array dump"""
            for i in self.n:
                print(f'[{i}] {i.data} {i.next} {i.dnext}')

        def __iter__(self) -> ArrayLinkedListIterator:
            """return iterator"""
            return ArrayLinkedListIterator(self.n, self.head)


class ArrayLinkedListIterator:
    """클래스 ArrayLinkedList의 이터레이터용 클래스"""

    def __init__(self, n: int, head: int):
        self.n = n
        self.current = head

    def __iter__(self) -> ArrayLinkedListIterator:
        return self

    def __next__(self) -> Any:
        if self.current == Null:
            raise StopIteration
        else:
            data = self.n[self.current].data
            self.current = self.n[self.current].next
            return data
