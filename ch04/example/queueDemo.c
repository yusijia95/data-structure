//
// Created by 李熠 on 2019/10/12.
//
#include "queue.h"

int main(void) {
//    SeqList *seqListAddr = seqListCreate();
//    seqQueueOffer(seqListAddr,5);
//    seqQueueOffer(seqListAddr,15);
//    seqQueueOffer(seqListAddr,25);
//    seqListDisplay(seqListAddr);
//    printf("%d\n",seqQueuePoll(seqListAddr));
//    printf("%d\n",seqQueuePoll(seqListAddr));
//    printf("peek=%d\n",seqQueuePeek(seqListAddr));
//    printf("isEmpty=%d\n",seqQueueIsEmpty(seqListAddr));
//    printf("%d\n",seqQueuePoll(seqListAddr));
//    printf("isEmpty=%d\n",seqQueueIsEmpty(seqListAddr));
//    seqListDisplay(seqListAddr);

    SinglyIntNode *singlyListAddr=singlyIntNodeCreate();
    linkedQueueOffer(singlyListAddr,5);
    linkedQueueOffer(singlyListAddr,15);
    linkedQueueOffer(singlyListAddr,25);
    singlyIntNodeDisplay(singlyListAddr);
    printf("%d\n",linkedQueuePoll(singlyListAddr));
    printf("%d\n",linkedQueuePoll(singlyListAddr));
    printf("%d\n",linkedQueuePeek(singlyListAddr));
    printf("%d\n",linkedIsEmpty(singlyListAddr));
    printf("%d\n",linkedQueuePoll(singlyListAddr));
    printf("%d\n",linkedIsEmpty(singlyListAddr));

    return 0;
}