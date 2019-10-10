//
// Created by 李熠 on 2019/10/8.
//
#include "seqlist.h"

//int *getIntList() {
//    int a = 5;
//    return &a;
//}

int main(void) {

    SeqList *seqList = seqListCreate();

    for (int i = 0; i < seqList->capacity; i++) {
        printf("[%d]=", i);
        scanf("%d", &seqList->head[i]);
        seqList->length++;
    }

    seqListAdd(seqList, 14);
    seqListDisplay(seqList);

    seqListDelete(seqList,9);
    seqListDisplay(seqList);

    seqListDeleteElem(seqList, 14);
    seqListDisplay(seqList);

    seqListRevert(seqList);
    seqListDisplay(seqList);

    seqListInsert(seqList, 9, 14);
    seqListDisplay(seqList);

    seqListUpdate(seqList, 9, 14);
    seqListDisplay(seqList);

    seqListGet(seqList, 9);
    seqListDisplay(seqList);

    seqListDestroy(seqList);





//    int *p = getIntList();
//    printf("%d\n", *p);
//    *p = 10;
//    printf("*p = %d\n", *p);
//    printf("p = %p\n", p);
//    int *p2 = getIntList();
//    printf("*p2 = %d\n", *p2);
//    printf("p2 = %p\n", p2);
//    *p2 = 15;
//    printf("*p = %d\n", *p);
//    printf("p = %p\n", p);
//    printf("*p2 = %d\n", *p2);
//    printf("p2 = %p\n", p2);
//    printf("*p = %d\n", *p);
//    printf("p = %p\n", p);


}

