#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int coef;
    int expo;
} el;

int compare(const void* a, const void* b) {
    return ((el*)b)->expo - ((el*)a)->expo;
}

int main() {
    FILE* fp;
    fp = fopen("input.txt", "r");

    char temp[11];
    el poly1[10001];
    el poly2[10001];
    el result[20002];
    int temp_top = -1;
    int p1_top = -1;
    int p2_top = -1;
    int res_top = -1;
    int a, b;
    int num;

    int start_p1 = 0;
    int start_p2 = 0;
    int finish_p1 = 0;
    int finish_p2 = 0;

    while (1) {
        int temp = fscanf(fp, "(%d,%d)", &a, &b);
        if (temp != 2) {  // scanf에 입력값이두개가 아니라면 반복문종료
            break;
        }
        poly1[++p1_top].coef = a;
        poly1[p1_top].expo = b;
    }

    fgetc(fp);

    while (1) {
        int temp = fscanf(fp, "(%d,%d)", &a, &b);

        if (temp != 2) {  // scanf에 입력값이두개가 아니라면 반복문종료
            break;
        }
        poly2[++p2_top].coef = a;
        poly2[p2_top].expo = b;
    }
    fclose(fp);
    qsort(poly1, p1_top + 1, sizeof(poly1[0]), compare);
    qsort(poly2, p2_top + 1, sizeof(poly1[0]), compare);

    finish_p1 = p1_top;
    finish_p2 = p2_top;

    while (start_p1 <= finish_p1 && start_p2 <= finish_p2) {
        if (poly1[start_p1].expo > poly2[start_p2].expo) {
            result[++res_top] = poly1[start_p1++];
        } else if (poly1[start_p1].expo == poly2[start_p2].expo) {
            result[++res_top].coef = poly1[start_p1].coef + poly2[start_p2].coef;
            result[res_top].expo = poly1[start_p1].expo;
            start_p1++;
            start_p2++;
        } else {
            result[++res_top] = poly2[start_p2++];
        }
    }

    for (int i = 0; i <= res_top; i++) {// 음수면 스페이스 - 스페이스 양수면 스페이스 + 스페이스
        if (i != res_top) {
            printf("%dx^%d ", result[i].coef, result[i].expo);
            if (i + 1 >= res_top && i)
        };
            else
            printf("%dx^%d", result[i].coef, result[i].expo);
    }

}
