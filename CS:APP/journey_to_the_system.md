# 1장 컴퓨터 시스템으로의 여행

## 정보는 비트와 컨텍스트로 이루어진다.

context ? 호출/응답간의 환경 정보

## 프로그램은 다른 프로그램에 의해 다른 형태로 번역된다.

gcc 컴파일러 드라이버는 소스파일 hello.c를 읽어서 실행파일인 hello로 번역한다.
번역은 4단계를 거쳐서 실행된다.
이 네 단계를 실행하는 프로그램(전처리기, 컴파일러, 어셈블러, 링커)을 합쳐서 **컴파일 시스템** 이라한다.

### 컴파일 시스템

1. 전처리 단계(cpp : Pre-processor) : 전처리기(cpp)는 본래의 c프로그램을 #문자로 시작하는 directive에 따라 수정한다.
   helloc.c -> hello.i
   ? directive : 전처리기에 내리는 명령

2. 컴파일 단계(cc1 : Compiler) : cc1은 텍스트파일 hello.i를 텍스트파일인 hello.s로 번역하며, 이 파일에는 어셈블리어 프로그램이 저장된다.
   hello.i -> hello.s

3. 어셈블리 단계(as : Assembler) : as가 hello.s를 기계어 인스트럭션으로 번역하고, 이들을 재배치 가능 목적 프로그램의 형태로 묶어서 hello.o라는 목적 파일에 그 결과를 저장한다.
   hello.s -> hello.o
   ? 실행 가능 목적 프로그램 = 목적 프로그램(Object Program) = 실행파일 (exe)
   ? instruction : 컴퓨터에게 일을 시키는 단위. 지시 또는 명령

4. 링크 단계(ld : Linker) : hello.o -> hello

## 컴파일 시스템이 어떻게 동작하는 지 이해하는 것은 중요하다.

중요한 이유

1. 프로그램 성능 최적화

2. 링크 에러 이해

3. 보안 약점

## 프로세서는 메모리에 저장된 인스트럭션을 읽고 이해한다.

Bus

- 시스템 내를 관통하는 전기적 배선군을 bus라 한다.

입출력 장치

- 시스템과 외부 세계와의 연결을 담당한다. 자세한 설명은 생략한다.

메인 메모리

- 물리적으로는 메인 메모리는 DRAM(Dynamic Random Access Memory) 칩들로 구성되어 있다.
- 논리적으로는 메모리는 연속적인 바이트들의 배열로, 각각 0부터 시작해서 고유의 주소를 가지고 있다. 일반적으로, 한개의 프로그램을 구성하는 각 기계어 인스트럭션은 다양한 바이트 크기를 갖는다.

프로세서

- 주기억장치(CPU) (= 프로세서)는 메인 메모리에 저장된 인스트럭션들을 해독(실행)하는 엔진이다.

## 캐시가 중요하다.

**메인 메모리를 더 빠르게 동작하도록 만드느 것보다 프로세서를 더 빨리 동작하도록 만드는 것이 더 쉽고 비용이 적게 든다.**

프로세서-메모리 간 격차에 대응하기 위해 시스템 설계자는 보다 작고 빠른 **캐시 메모리(=캐시)** 라고 부르는 저장장치를 고안하여 프로세서가 단기간에 필요로 할 가능성이 높은 정보를 임시로 저장할 목적으로 사용한다.

## 운영체제는 하드웨어를 관리한다.

**응용프로그램이 하드웨어를 제어하려면 언제나 운영체제를 통해서 해야한다.**

운영체제는 두가지 목적을 가진다.

1. 제멋대로 동작하는 응용프로그램들이 하드웨어를 잘못 사용하는 경우를 막기 위해
2. 응용프로그램들이 단순하고 균일한 메커니즘을 사용하여 복잡하고 매우 다른 저수준 하드웨어 장치들을 조작할 수 있도록 하기 위해

### 프로세스

프로세스란 ? 실행 중인 프로그램에 대한 운영체제의 추상화다.

concurrently(동시성) : 한 프로세스의 인스트럭션들이 다른 프로세스의 인스트럭션들과 섞이는 것을 의미한다.

커널 : 모든 프로세스를 관리하기 위해 시스템이 이용하는 코드와 자료구조의 집합

### Thread(쓰레드)

프로세스가 실제로 쓰레드라고 하는 다수의 실행 유닛으로 구성되어 있다.
쓰레드는 해당 프로세스의 컨텍스트에서 실행되며 동일한 코드와 전역 데이터를 공유한다.

**프로세스들에서보다 데이터의 공유가 더 쉽다는 점과 쓰레드가 프로세스보다 더 효율적이라는 점** 때문에, 프로그래밍 모델로서 중요성이 커지고 있다.

? 왜 효율적인데 ㅡ,ㅡ 그걸 알려줘야지 18

### 가상메모리

각 프로세스들이 메인 메모리 전체를 독점적으로 사용하고 있는 것 같은 환상을 제공하는 추상화이다.

### 쓰레드 수준 동시성

멀티 프로세서 시스템 : 여러 개의 프로세서를 가지고 하나의 운영체제 커널의 제어 하에 동작하는 경우

멀티 쓰레딩(=하이퍼쓰레딩) : 하나의 CPU가 여러개의 제어 흐름을 실행할 수 있게 해주는 기술

멀티 프로세싱을 이용해 시스템의 성능을 향상 시키는 법

1. 다수의 태스크를 실행할 때, 동시성을 시뮬레이션할 필요를 줄여준다.
2. 멀티프로세싱으로 하나의 응용 프로그램을 빠르게 실행할 수 있지만, 병렬로 효율적으로 실행할 수 있는 멀티스레딩 형태로 프로그램이 표현되어야 한다.

### 인스트럭션 수준 병렬성

최근의 프로세서들은 훨씬 낮은 수준에서의 추상화로 여러 개의 인스트럭션을 한번에 실행할 수 있다. 이러한 특성을 **인스트럭션 수준 병렬성** 이라고 한다.

super-scalar(슈퍼 스케일러) : 사이클당 한 개 이상의 인스트럭션을 실행할 수 있는 프로세서

### 컴퓨터 시스템에서 추상화의 중요성

운영체제 측면에서 3가지 추상화

1. 파일은 입출력장치의 추상화
2. 가상메모리는 메인 메모리와 디스크의 추상화
3. 프로세스는 프로세서, 메인 메모리, 입출력 장치의 추상화

! 네트워크는 컴퓨터 시스템이 서로 통신할 수 있는 방법을 제공한다. 특정 시스템의 관점으로 볼 때, 네트워크는 단지 또 하나의 입출력 장치다.
