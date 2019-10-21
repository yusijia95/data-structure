//
// Created by 李熠 on 2019/10/10.
//
#include "seqlist.h"
#include "singlyIntNode.h"

/**
 * 返回位于栈顶的元素，并在堆栈中删除它
 * @param list
 * @return  栈顶的元素
 */
int seqStackPop(SeqList *list) {
    int rlt = seqListGet(list, list->length - 1);
    seqListDelete(list, list->length - 1);
    return rlt;
}

int seqStackPush(SeqList *list, int elem) {
    seqListAdd(list, elem);
    return elem;
}

int seqStackIsEmpty(SeqList *list) {
    return list->length == 0;
}

int seqStackPeek(SeqList *list) {
    return seqListGet(list, list->length - 1);
}

int seqStackSearch(SeqList *list, int elem) {
    int count = 0;
    while (list->head[count] != elem) {
        count++;
    }
    if (count != 0) {
        return count;
    } else {
        return -1;
    }
}

int linkedStackPop(SinglyIntNode *list) {
    int rlt = singlyIntNodeGet(list, list->value - 1);
    singlyIntNodeDelete(list, list->value - 1);
    return rlt;
}

int linkedStackPush(SinglyIntNode *list, int elem){
    singlyIntNodeAdd(list,elem);
    return 30;
}

int linkedStackIsEmpty(SinglyIntNode *list){
    return list->value==0;
}

int linkedStackPeek(SinglyIntNode *list){
    return singlyIntNodeGet(list,list->value-1);
}

int linkedStackSearch(SinglyIntNode *list, int elem){
    int count=0;
    while(list->next->value!=elem){
        count++;
        list=list->next;
    }
    if(count!=0){
        return count;
    }else{
        return -1;
    }
}


