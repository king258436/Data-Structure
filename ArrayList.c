#include "ArrayList.h"
#include <stdio.h>

void ListInit(List* plist)
{
    plist->curPosition = -1;
    plist->numOfData = 0;
}

void LInsert(List* plist, LData data)
{
    if (plist->numOfData >= LIST_LEN) {
        printf("꽉찼어염\n");
    } else {
        plist->arr[plist->numOfData++] = data;
    }
}

int LFirst(List* plist, LData* pdata)
{
    if (plist->numOfData == 0) {
        printf("저장된 데이터가 없쪄염\n");
        return FALSE;
    } else {
        plist->curPosition = 0;
        *pdata = plist->arr[plist->curPosition];
        return TRUE;
    }
}

int LNext(List* plist, LData* pdata)
{
    if (plist->curPosition + 1 >= plist->numOfData) {
        return FALSE;
    } else {

        *pdata = plist->arr[++plist->curPosition];
        return TRUE;
    }
}

LData LRemove(List* plist)
{
    int i;
    LData rdata = plist->arr[plist->curPosition];
    for (i = plist->curPosition; i < plist->numOfData - 1; i++) {
        plist->arr[i] = plist->arr[i + 1];
    }
    plist->curPosition--;
    plist->numOfData--;
    return rdata;
}

int LCount(List* plist)
{
    return plist->numOfData;
}