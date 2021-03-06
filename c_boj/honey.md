#### int main() VS void main() VS main()

main = vodi main 같은 표현
return notthing

int main -> return int

#### 0.5 더하기

c언어에서 int연산을 하면 내림 연산을 한다.

4.4 + 0.5 = 4.9 이지만 4
4.6 + 0.5 = 5.1 이지만 5

0.5만 더해줘도 반올림한 효과가 난다.

#### 실수형 연산은 double!!

실수형 연산을 할 때는 float보다는 double을 사용하는 습관을 들이자.
float는 소숫점 6자리밖에 표현이 안되기 때문에 정확한 연산을 위해서는 double을 사용하도록 하자

#### %.0f

%f는 실수형을 출력한다. 소숫점 아래 자릿수만큼 %뒤에 뭍이면 소숫점 자리수에서 반올림한다.

12.3456이 있다고 한다면,
%.0f = 12
%.1f = 12.3
%.2f = 12.35
%.3f = 12.346
...

자동 반올림이 된다.

#### include

이 키워드(keyword : C언어에서 특정한 의미, 기능을 가지고 있는 단어로 **예약어** 라고도 부른다.)는 우리말로 **전처리기(preprocessor)** 라고도 한다.
전처리기는 #include로 시작하며, 그 옆에 있는 것을 포함한다는 뜻이다.

즉, #include <stdio.h> 라고 써있는 문장은 'stdio.h'를 포함한다. 라는 의미를 가진다.

#### <stdio.h>

<>는 그냥 단순하게 stdio.h를 감싸고 있는 시작과 끝을 나타내는 것일 뿐 큰 의미는 없다.

stdio.h = **standard input output** 의 약자이다. h는 header의 약자로 파일의 확장자를 나타낸다.

#### <stdlib.h>

프로그래밍 시, 범용적으로 사용되는 여러가지 함수들을 모아 놓고 있다.

ex) 동적 할당 관련 함수, 난수 생성 함수, 정수의 연산 함수, 검색 및 정렬 함수 등

malloc, calloc,free 등 함수가 선언된 헤더 파일

#### 동적할당(Dynamic Allocation) 왜 함?

1. 메모리
   일시적으로 갑자기 많은 메모리를 잡아야 할 경우가 있다.
   RAM의 메모리 자원은 한정적이다.
   사용할 때에만 잠시 잡았다가 필요 없으면 해당 메모리를 해지시켜서 다른 곳에서 활용할 수 있도록 하는게 리소스 관리에 효율적이다.
   내가 원할 때, 메모리를 할당햇다가, 필요없어지면 해지시킬 수 있도록 메모리 할당하는게 **동적할당** 이다.
   **50KB이상이면 동적으로 할당해줘야지 아니면 crash가 발생할 위험이 있다. 물론, 이는 플랫폼에 따라 다르다.**

2. 함수 리턴 이후에도 메모리 할당이 살아있게 하고 싶으면 동적할당을 써주자.

일반 변수나 함수의 경우 stack이라는 메모리 공간에 할당되는데, 얘네는 범위를 벗어나면 파괴되어 사용할 수 없다.
하지만 동적할당으로 잡은 메모리는 stack에 저장되지 않기 때문에 이 영향을 받지 않는다.
이렇게 **함수 리턴 이후에도 메모리 할당이 살아있게 하고 싶다면 동적할당을 써주자.**

3. 메모리 효율

예를 들어 100이라는 메모리 저장공간을 만들어놨다. 그러나 110만큼의 메모리를 할당하면 메모리 부족이 일어나고, 10만큼의 메모리를 할당하면 메모리가 너무 논다.

위와 같은 문제를 해결하기 위해서는 메모리를 동적할당해야한다.

malloc -> memory allocation

**malloc으로 할당했으면 꼭 free로 해제해주기**
**new로 할당했다면, 꼭 delete로 해제해주기**

**malloc VS calloc**

malloc은 할당된 공간의 값을 바꾸지 않는다.
calloc은 할당된 공간의 값을 모두 0으로 바꾼다.

그러니, 배열을 할당하고 모두 0으로 초기화할 필요가 있는 경우 calloc을 쓰면 편하다.

**속도는 비슷하다**
realloc : 이미 할당한 공간의 크기를 바꿀 때 사용한다.

```cpp
#include <stdlib.h>

// malloc 함수의 연형
void* malloc(size_t size)

// int형 데이터를 저장하기 위해서는 리턴되는 void*를 int*로 변환해야 한다.
int *i = (int*) malloc (sizeof(int));

// calloc함수 원형 elt_size 크기의 변수를 elt_count개 만큼 저장할 수 있는 메모리 공간을 할당하라는 의미
void* calloc(size_t elt_count, size_t elt_size)

// realloc, 이미 할당한 포인터 변수를 memblock에 넣고, 바꾸고 싶은 공간의 크기를 size에 입력하여 사용
void* realloc(void* memblock, size_t size)
```

#### main return

c++ : it shall have a return type of type int. but, otherwise its type is implementation defined
c++은 Int를 강력히 권고하지만 강요하지 않는다.

**but**
**gcc는 표준의 권고대로 main 함수의 리턴 타입으로 int만 인정한다.**

**main함수의 반환자료형이 void이면 부모 프로세스나 운영체제에 return statement 값을 리턴할 수 없다.**

#### pointer

장점

- 어느 곳에 있든지 주소를 직접적으로 참조함으로써 값을 가져올 수 있고 변경할 수 있다.
- 만약, 주소 값을 넘겨주지 않고, 그냥 변수의 값을 매개변수로 전달했을 때는 값이 복사되어 함수로 전달한다(call by value).

주의점

1. 포인터 변수 선언시 초기화하기

- 만약, 포인터가 선언만 되고 초기화되지 않았다면 포인터는 쓰레기 값을 가진다.
  이와 같은 상태에서 포인터를 사용하여 메모리의 내용을 변경한다면 문제가 생길 소지가 있다.
  만약, 우연히 포인터가 중요한 값을 가리키고 있었다면 중요한 정보를 덮어쓸 수도 있으며, 따라서 전체 시스템을 다운 시킬 수도 있으니, 그냥 **포인터를 단순히 선언만 하지 말고 선언 시, 초기화를 사용하거나, NULL 포인터로 만들어 주는 것이 바람직하다.**

2. NULL포인터 사용

- 포인터가 아무것도 가리키지 않을 때 NULL로 설정하는 것이 좋다.
  NULL은 헤더 파일 stdio.h에 0으로 정의되어 있다.
  **주소 0은 CPU가 사용하는 영역이어서 일반 프로그램은 주소 0에 접근할 수 없기 때문에 안정성이 높다.**

3. 포인터 자료형과 변수의 자료형 일치

- 만약 포인터의 자료형이 변수의 자료형보다 크다면, 포인터를 통해 변수의 주소를 통해 쓰게 될 경우 변수의 범위를 넘어가서 이웃바이트를 덮어쓰게 되어 문제가 생길 수 있다.

4. 절대 주소 사용 금지

- 절대 주소는 아두이노와 같은 임베디드 시스템에서만 사용한다.
  그 이유는, PC는 윈도우와 같은 운영체제가 프로그램을 관리하기 때문에, 프로그래머가 사용하고자 하는 주소가 어떠한 용도로 사용되는지 모르기 때문이다.
  **실행을 할 때마다 할당되는 주소가 다르기 때문에 절대주소는 사용하면 안된다.**

#### puts() VS printf()

모두 전처리 지시자 #include로 헤더파일 <stdio.h>를 사용해야한다.

puts()

- 문자열을 출력하는 함수, 오직 **문자열** 만 출력하는 역할이다.
- 문자열 출력 후 줄바꿈을 시전한다.
- !printf("\n")보다 puts("")가 한 줄 비울때 더 빨라서 자주 사용한다.

printf()

- 다양한 정보를 서식화하여 출력하는 함수다. Ex) 문자열, 정수, 실수, 문자 ...
- 줄바꿈 없음

#### 매크로 사용하기

c언어에서는 컴파일러에 특정 작업을 지시하는 preprocessor를 제공한다.
보통 전처리기는 반복되는 값이나 작업을 미리 정의할 때 사용하며, 컴파일 옵션 설정이나 조건부 컴파일도 가능하다.

전처리기에서 #define으로 매크로를 정의하는 방법!

- #define 매크로이름 값
  보통 매크로는 대문자를 사용한다.

```c
#define ARRAY_SIZE 10
// 10을 ARRAY_SIZE로 정의
```

### 구조체 struct

struct 구조체이름 {
자료형 멤버이름;
}(구조체변수이름);

구조체 변수이름은 생략가능

- 구조체는 정의만 해서 사용 할 수가 없다. 따라서, **구조체도 변수로 선언해서 사용한다.**
- struct 구조체이름 변수이름;

```cpp
#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일

struct Person {   // 구조체 정의
    char name[20];        // 구조체 멤버 1
    int age;              // 구조체 멤버 2
    char address[100];    // 구조체 멤버 3
};

int main()
{
    struct Person p1;     // 구조체 변수 선언

    // 점으로 구조체 멤버에 접근하여 값 할당
    strcpy(p1.name, "홍길동");
    p1.age = 30;
    strcpy(p1.address, "서울시 용산구 한남동");

    // 점으로 구조체 멤버에 접근하여 값 출력
    printf("이름: %s\n", p1.name);       // 이름: 홍길동
    printf("나이: %d\n", p1.age);        // 나이: 30
    printf("주소: %s\n", p1.address);    // 주소: 서울시 용산구 한남동

    return 0;
}
```

#### 문자열 함수와 보안경고

Visual Studio에서 scanf, strcpy, strcat, sprintf, strtok 등의 함수를 사용했을 때, 보안 경고로 인한 컴파일 에러가 발생한다면
헤더 파일 위에 #define \_CRT_SECURE_NO_WARNINGS 를 넣어주자.

```c
#define _CRT_SECURE_NO_WARNINGS // 보안 경고로 인한 컴파일 에러방지
```

### typedef

typedef는 자료형의 별칭을 만드는 기능이다.
따라서, 구조체뿐만 아니라 모든 자료형의 별칭을 만들 수 있다.

- typedef 자료형 별칭
- typedef 자료형\* 별칭

```cpp
typedef int MYINT;      // int를 별칭 MYINT로 정의
typedef int* PMYINT;    // int 포인터를 별칭 PMYINT로 정의

MYINT num1;        // MYINT로 변수 선언
PMYINT numPtr1;    // PMYINT로 포인터 변수 선언

numPtr1 = &num1;   // 포인터에 변수의 주소 저장
                   // 사용 방법은 일반 변수, 포인터와 같음
```

### 문자열 -> 숫자 변환

atoi 함수 사용

```cpp
int *str ='213';

atoi(&str[1]);
// 1
```

ASCII 사용
아스키 코드상 1-> 49 2->50 ... 임 그래서 '0'을 빼주면 숫자가 됨
ex )아스키 코드상 문자 1==49, 0==48 이기 때문에
49-48 == 1이 됨. 나머지 숫자도 동일

즉, 문자열의 숫자 - '0' == 정수형 숫자

1541.c 참고
