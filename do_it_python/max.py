# 시퀀스 원소의 최댓값 출력

from typing import Any, Sequence
# Any는 제약이 없는 임의의 자료형을 의미한다.
# Sequence는 시퀀스형을 의미한다. ex) List, bytearray, str, tuple, bytes ...


def max_of(a: Sequence) -> Any:
    """Sequence a원소의 최댓값을 반환"""
    maximum = a[0]
    for i in range(1, len(a)):
        if a[i] > maximum:
            maximum = a[i]
    return maximum
