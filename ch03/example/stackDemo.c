//
// Created by 李熠 on 2019/10/10.
//

#include "stack.h"

int main(void) {
//    SeqList *seqListAddr = seqListCreate();
//    seqStackPush(seqListAddr,5);
//    seqStackPush(seqListAddr,15);
//    seqStackPush(seqListAddr,25);
//    seqListDisplay(seqListAddr);
//    printf("%d\n",seqStackSearch(seqListAddr,15));
//    printf("%d\n",seqStackPop(seqListAddr));
//    printf("%d\n",seqStackPop(seqListAddr));
//    printf("peek=%d\n",seqStackPeek(seqListAddr));
//    printf("isEmpty=%d\n",seqStackIsEmpty(seqListAddr));
//    printf("%d\n",seqStackPop(seqListAddr));
//    printf("isEmpty=%d\n",seqStackIsEmpty(seqListAddr));
//    seqListDisplay(seqListAddr);

    SinglyIntNode *singlyListAddr = singlyIntNodeCreate();
    linkedStackPush(singlyListAddr,5);
    linkedStackPush(singlyListAddr,15);
    linkedStackPush(singlyListAddr,25);
    singlyIntNodeDisplay(singlyListAddr);
    printf("%d\n",linkedStackSearch(singlyListAddr,15));
    printf("%d\n",linkedStackPop(singlyListAddr));
    printf("%d\n",linkedStackPop(singlyListAddr));
    printf("%d\n",linkedStackPeek(singlyListAddr));
    printf("%d\n",linkedStackIsEmpty(singlyListAddr));
    printf("%d\n",linkedStackPop(singlyListAddr));
    printf("%d\n",linkedStackIsEmpty(singlyListAddr));

    return 0;
}