#include <stdio.h>

#include "DBLinkedList.h"

int main(void) {
    List list;
    int data;
    ListInit(&list);

    for (int i = 1; i < 9; i++) {
        LInsert(&list, i);
    }  // 1~8 까지 리스트 생성

    if (LFirst(&list, &data)) {
        printf("%d ", data);

        while (LNext(&list, &data)) printf("%d ", data);
        printf("\n");

        printf("%d ", data);  // 현재 데이터 한번더 출력

        while (LPrevious(&list, &data)) printf("%d ", data);
        printf("\n");
    }

    if (LFirst(&list, &data)) {
        if (data % 2 == 0) LRemove(&list);

        while (LNext(&list, &data)) {
            if (data % 2 == 0) LRemove(&list);
        }
    }  // 2의 배수들만 삭제

    if (LFirst(&list, &data)) {
        printf("%d ", data);

        while (LNext(&list, &data)) printf("%d ", data);

    }  // 다시조회
    return 0;
}