# Heap

힙은, 우선순위 큐를 위해 만들어진 자료구조다.

## 우선순위 큐

우선순위의 개념을 큐에 도입한 자료구조
데이터들이 우선순위를 가지고, 우선순위가 높은 데이터가 먼저 나간다.

when use? 시뮬레이션 시스템, 작업스케쥴링, 수치해석 계산

우선순위 큐는 배열, 연결리스트, 힙으로 구현할수 있다.
(힙으로 구현하는 것이 가장 효율적이다.)

삽입 : O(logn)
삭제 : O(logn)

## Heap

완전 이진 트리의 일종
여러 값 중, 최대값과 최소값을 빠르게 찾아내도록 만들어진 자료구조

반정렬 상태
힙 트리는 중복된 값을 허용한다.(이진 탐색 트리는 중복값을 허용하지 않는다.)

### 종류

max heap (최대 힙)

- 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리

min heap (최소 힙)

- 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진 트리

### 구현

힙을 저장하는 표준적인 자료구조는 _배열_

구현을 쉽게 하기 위해 배열의 첫번째 인덱스 0은 사용하지 않는다.

특정 위치의 노드 번호는 새로운 노드가 추가되어도 변하지 않는다.
ex) 루트 노드(1)의 오른쪽 노드 번호는 항상 3이다.

```
// realation of parent node and child node

// Left child node index = parent node * 2
// Right child node index = parent node * 2 + 1
// parent node index = parent node / 2
```

#### insert the heap

1. 힙에 새로운 요소가 들어오면, 일단 새로운 노드를 힙의 마지막 노드에 삽입

2. 새로운 노드를 부모 노드들과 교환

최대 힙 삽입 구현

- 부모 노드는 자신의 인덱스의 /2 이므로, 비교하고 자신이 더 크면 swap하는 방식

```
const insertMaxHeap = fucntion(x){
  // 힙 크기를 하나 증가시키고, 마지막 노드에 x를 넣는다.
  maxHeap[++heapSize] = x;

  for(int i =heapSize; i>1; i/=2){
    //마지막 노드가 자신의 부모 노드보다 크면 swap
    if(maxHeap[i/2]< maxHeap[i]){
      maxHeap[i/2], maxHeap[i] = maxHeap[i], maxHeap[i/2];
    }else break;
  }
}
```

#### delete the heap

1. 최대 힙에서 최대 값은 루트 노드이므로 루트 노드가 삭제된다.

2. 삭제된 루트 노드에는 힙의 마지막 노드를 가져온다.

3. 힙을 재구성

최대 힙 삭제 구현

```
cosnt deleteMaxHeap = function(){
  // 배열이 비어있다면 0 리턴
  if(heapSize ===0) return 0;

  // 루트 노드의 값을 저장
  let item = maxHeap[1];
  // 마지막 노드 값을 루트로 이동
  maxHeap[1] = maxHeap[heapSize];
  // 힙 크기를 하나 줄이고 마지막 노드 0으로 초기화
  maxHeap[heapSize--] = 0;

  for(int i=1; i*2 <=heapSize;>){

    // 마지막 노드가 왼쪽 노드와 오른쪽 노드보다 크면 break;
    if(maxHeap[i] > maxHeap[i*2] && maxHeap[i] > maxHeap[i*2 +1]) break;

    // 왼쪽 노드가 더 큰 경우 swap
    else if(maxHeap[i*2] > maxHeap[i*2+1]){
      maxHeap[i], maxHeap[i*2] = maxHeap[i*2], maxHeap[i];
    }

    // 오른쪽 노드가 더 큰 경우 swap
    else{
      maxHeap[i], maxHeap[i*2+1] = maxHeap[i*2+1], maxHeap[i];
    }
  }
  return item;
}
```
