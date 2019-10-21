//
// Created by edz on 2019/10/16.
//
#include <stdio.h>
#include <queue.h>

int main(void) {
    int no, num;
    SeqList *seqListAddr = seqListCreate();
    printf("请输入一个整数：");
    scanf("%d", &no);
    for (int i = 0; i < 32; i++) {
        num = (no >> i) & 1;
        seqStackPush(seqListAddr, num);
    }
//    seqListDisplay(seqListAddr);
    for (int i = 0; i < 32; i++)
        printf("%d", seqStackPop(seqListAddr));
}

