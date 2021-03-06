# Tree

node와 edge로 이뤄진 자료구조

트리는 값을 가진 노드와 이 노드를 연결해주는 간선(edge)로 이뤄져 있다.

## 특징

1. 트리에는 사이클이 존재할 수 없다. (만약, 사이클이 만들어진다면, 그건 트리가 아니고 그래프다.)
2. 모든 노드는 자료형으로 표현이 가능하다.
3. 루트에서 한 노드로 가는 경로는 유일한 경로 뿐이다.
4. 노드의 개수가 N개면 간선은 N-1개다.

! 그래프와 트리의 차이는 사이클의 유무다. (트리는 사이클이 없다.)

## 트리 순회 방식

1. pre-order (전위 순회)

- 각 루트를 순차적으로 방문하는 방식
- Root -> Left Child -> Right Child

2. in-order (중위 순회)

- 왼쪽 하위 트리를 방문 후 루트를 방문하는 방식
- Left Child -> Root -> Right Child

3. post-order (후위 순회)

- 왼쪽 하위 트리부터 하위를 모두 방문 후 루트를 방문하는 방식
- Left Child -> Right Child -> Root

4. level-order (레벨 순회)

- 루트부터 계층별로 방문하는 방식
- ex) index : 1->2->3->4 ...

# Binary Search Tree

이진 탐색 트리의 목적

- 이진 탐색 + 연결리스트

이진 탐색 : 탐색에 소요되는 시간 복잡도 O(logN), 그러나 삽입, 삭제가 불가능하다.

연결리스트 : 삽입, 삭제의 시간 복잡도 O(1), 그러나 탐색 O(N)이다.

이 두가의 장점을 합한 것이 **이진탐색 트리**

**즉, 효율적인 탐색 능력과 자료의 삽입, 삭제도 가능하게 만든 것**

## 특징

- 각 노드의 자식이 2개 이하
- 각 노드의 왼쪽 자식은 부모보다 작고, 오른쪽 자식은 부모보다 크다
- 중복된 노드는 없어야 한다.

? 중복이 없어야 하는 이유

- 검색 목적 자료구조인데, 굳이 중복이 많은 경우에 트리를 사용하여 검색 속도를 느리게 할 필요가 없다.
  (트리에 삽입하는 것보다, 노드에 count 값을 가지게 하여 처리하는 것이 훨씬 효율적이다.)

이진탐색트리의 순회는 '중위순회'다.
