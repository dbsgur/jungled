이것은 sw정글을 가기 전 기초 Computer Science, C, Python, Algorithm, 자료구조에 대해 예습을 하고자 만든 것입니다.

## 각 폴더 설명

### computer architecture

1. arm_processor

- ARM 프로세서란 ?
- 장점

2. cache_memory

- 캐시 메모리란?
- 캐시 미스의 경우
- 구조 및 작동 방식

3. computer_configuration

- 컴퓨터 구성 (중앙처리장치, 기억장치, 시스템 버스)
- 버스의 종류

4. how_cpu_works

- cpu의 동작 원리, 과정
- 연산장치(ALU), 제어장치(CU), 레지스터(Register)
- 특수 목적 레지스터 중 중요한 것들 MAR, PC, MBR, AC ...
- 명령어 세트

### Data Structure

1. array_linkedlist_arraylist

- Array란? 장점 및 단점
- List란 ? 장점 및 단점
- LinkedList란 ? 장점 및 단점
- Array VS List VS LinkedList

2. hash

- hash란? 언제 씀?
- collision이란? collision 해결 방법

3. heap

- heap이란 ? 우선순위 큐란?
- 종류
- 간단한 구현
- insert the heap 단계 간단한 구현
- delete the heap 단계 간단한 구현

4. stack_queue

- stack이란? 언제 쓰는지?
- queue란? 언제 쓰는지?
- 일반 큐, 원형 큐의 단점과 연결리스트 큐의 장점

5. tree

- 트리란?
- 트리의 특징
- 트리 순회 방식
- 이진 탐색 트리란? 이진탐색 트리의 목적
- 이진 탐색 트리의 특징

### CS:APP

1. Journey To The System

- 컴파일 시스템의 동작 단계
- 컴파일 시스템이 어떻게 동작하는지 이해하는 것이 중요한 이유
- 프로세서는 메모리에 저장된 인스트럭션을 읽고 이해한다.
- 캐시가 중요한 이유.
- 운영체제는 하드웨어를 관리한다. (두가지 목적)
- 프로세스, 스레드, 가상메모리란 ?
- 쓰레드 수준 동시성
- 인스트럭션 수준 병렬성
- 컴퓨터 시스템에서 추상화의 중요성

### do_it_python

'Do it! 자료구조와 함께 배우는 알고리즘 입문'

data structure

1. max.py : 배열 원소의 최댓 값 구하기
2. max_of_test_randit : 난수 생성후 최댓 값 구하기

search algorithm

1. ssearch_while : while문으로 작성한 선형 검색 알고리즘
2. ssearch_sentinel : 선형 검색 알고리즘을 보초법으로 수정
3. bsearch : 이진 검색 알고리즘
4. chianed_hash, chained_hasy_test : 체인법으로 해시 구현 및 사용
5. open_hash, open_hash_test : 오픈 주소법으로 해시함수 구현 및 사용

stack and queue

1. fixed_stack, fixed_stack_test : 고정 길이 스택 클래스 구현 및 사용
2. stack : collection.deque를 사용해 고정 길이 스택 클래스 구현
3. fixed_queue, fixed_queue_test : 고정 길이 큐 클래스 구현

recursion algorithm

1. factorial : 양의 정수 n의 팩토리얼 구하기
2. gcd : 유클리드 호제법으로 최대공약수 구하기
3. hanoi : 하노이 탑 구현
4. 8queen : 8 queen문제 알고리즘 구현

sort algorithm

1. bubble_sort : 버블 정렬 알고리즘 구현
2. selection_sort : 단순 선택 정렬 알고리즘 구현
3. insertion_sort : 단순 삽입 정렬 알고리즘 구현
4. binary_insertion_sort : 이진 삽입 정렬 알고리즘 구현
5. shell_sort : 셸 정렬 알고리즘 구현
6. quick_sort : 퀵 정렬 알고리즘 구현
7. merge_sort : 병합 정렬 알고리즘 구현
8. heap_sort : 힙 정렬 알고리즘 구현
9. counting_sort : 도수 정렬 알고리즘 구현

search string

1. bf_match : 브루트 포스법으로 문자열 검색하기
2. kmp_match : KMP법으로 문자열 검색하기
3. bm_match : 보이어-무어법으로 문자열 검색하기

list

1. linked_list : 포인터로 연결리스트 구현하기
2. array_list : 커서로 연결리스트 구현하기
3. double_list : 원형 이중 연결 리스트 구현하기

tree

1. bst : 이진 검색 트리 구현하기

### python_boj

python3으로 백준 문제 풀이

1018, 1436, 1699, 2022, 2231,
2750, 2751, 2798, 7568, 10828,
10989

### c_boj

C언어 기초, c언어로 백준 문제 풀이

hello, 10828 ...
