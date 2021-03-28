#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct {
    int Value;
    int Exitence;
}HashMap;

typedef struct{
    int Value;
    LinkList *next;
}LinkList;
int arr[1000];

/* 删除第index位的元素 */
void DeleteIndexElem(int* arr, int Index, int length) {
    for (int k = Index + 1; k < length; k++) {
        arr[k - 1] = arr[k];
    }
}