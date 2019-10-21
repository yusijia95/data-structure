//
// Created by 李熠 on 2019/10/10.
//
#include "singlyIntNode.h"

SinglyIntNode *singlyIntNodeCreate() {
    SinglyIntNode *rlt = (SinglyIntNode *) malloc(sizeof(SinglyIntNode));

    rlt->value = 0;
    rlt->next = NULL;
    return rlt;
}

void singlyIntNodeAdd(SinglyIntNode *head, int elem) {
    SinglyIntNode *newNode = singlyIntNodeCreate();
    SinglyIntNode *lastNode = head;

    while (lastNode->next) {
        lastNode = lastNode->next;
    }

    newNode->value = elem;
    lastNode->next = newNode;
    head->value++;
}

void singlyIntNodeDisplay(const SinglyIntNode *head) {
    printf("singly node size=%d\n", head->value);
    SinglyIntNode *curNode = head->next;
    int count = 0;

    while (curNode != NULL) {
        printf("[%d]=%d ", count++, curNode->value);
        curNode = curNode->next;
    }

    printf("\n");
}

void singlyIntNodeDestroy(SinglyIntNode *head) {
    SinglyIntNode *curNode = head;
    SinglyIntNode *temp;

    while (curNode != NULL) {
        temp = curNode->next;
        free(curNode);
        curNode = temp;
    }
}

int singlyIntNodeInsert(SinglyIntNode *head, int index, int elem) {
    if (index < 0 || index >= head->value) {
        printf("index is illegal!\n");
        return 0;
    }

    SinglyIntNode *beforeIndexNode = head;

    for (int i = 0; i < index; ++i) {
        beforeIndexNode = beforeIndexNode->next;
    }

    SinglyIntNode *newNode = singlyIntNodeCreate();
    newNode->next = beforeIndexNode->next;
    newNode->value = elem;
    beforeIndexNode->next = newNode;
    head->value++;
    return 1;

}

int singlyIntNodeDelete(SinglyIntNode *head, int index) {

    if (index < 0 || index >= head->value) {
        printf("index is illegal!\n");
        return 0;
    }

    SinglyIntNode *beforeIndexNode = head;

    for (int i = 0; i < index; i++) {
        beforeIndexNode = beforeIndexNode->next;
    }

    beforeIndexNode->next->value = NULL;
    beforeIndexNode->next = beforeIndexNode->next->next;
    head->value--;
    return 1;
}

int singlyIntNodeDeleteElem(SinglyIntNode *head, int elem) {
    SinglyIntNode *beforeNode = head;
    int count = 0;

    while (beforeNode->next->value != elem) {
        count++;
        beforeNode = beforeNode->next;

        if (count == beforeNode->value) {
            printf("删除失败");
            return 0;
        }
    }

    beforeNode->next->value = NULL;
    beforeNode->next = beforeNode->next->next;
    free(beforeNode);
    return 1;
}

void singlyIntNodeRevert(SinglyIntNode *head) {
    if (head->value <= 1) {
        return;
    }
    int count = head->value;
    SinglyIntNode *curNode = head->next;
    SinglyIntNode *beforeNode = head;
    SinglyIntNode *firstNode = head->next;
    SinglyIntNode *temp;

    for (int i = 0; i < count; i++) {
        temp = curNode->next;
        curNode->next = beforeNode;
        beforeNode = curNode;
        curNode = temp;
    }
    head->next = beforeNode;
    firstNode->next = NULL;

}

int singlyIntNodeUpdate(SinglyIntNode *head, int index, int elem) {
    SinglyIntNode *curIndexNode = head;

    if (index >= curIndexNode->value) {
        printf("更新失败");
        return 0;
    }

    for (int i = 0; i < index; i++) {
        curIndexNode = curIndexNode->next;
    }

    curIndexNode->value = elem;
    return 1;
}

int singlyIntNodeGet(SinglyIntNode *head, int index) {
    SinglyIntNode *curIndexNode = head;

    if (index >= curIndexNode->value) {
        printf("更新失败\n");
        return 0;
    }

    for (int i = 0; i < index; i++) {
        curIndexNode = curIndexNode->next;
    }

//    printf("%d\n", curIndexNode->next->value);
    return curIndexNode->next->value;
}

