#include <stdio.h>

int BsearchRecur(int ar[], int first, int last, int target)
{
    int mid = (first + last) / 2;
    if (first > last)
        return -1;
    if (ar[mid] == target) {
        return mid;
    } else if (ar[mid] > target) {
        return BsearchRecur(ar, first, mid - 1, target);
    } else {
        return BsearchRecur(ar, mid + 1, last, target);
    }
}
int main()
{
    int arr[] = { 1, 3, 5, 7, 9 };
    int idx;

    idx = BsearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
    if (idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스 : %d\n", idx);

    idx = BsearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);

    if (idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스 : %d\n", idx);

    return 0;
}
