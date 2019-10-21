//
// Created by 李熠 on 2019/10/10.
//
#include "doublyIntNode.h"

DoublyIntNode *doublyIntNodeCreate() {
    DoublyIntNode *rlt = (DoublyIntNode *) malloc(sizeof(DoublyIntNode));
    rlt->value = 0;
    rlt->next = NULL;
    rlt->prev = NULL;
    return rlt;
}

void doublyIntNodeDestroy(DoublyIntNode *head) {
    DoublyIntNode *curNode = head;
    DoublyIntNode *temp;

    while (curNode != NULL) {
        temp = curNode->next;
        free(curNode);
        curNode = temp;
    }

}

void doublyIntNodeDisplay(const DoublyIntNode *head) {
    printf("doubly linked list size:%d\n", head->value);
    int count = 0;
    DoublyIntNode *curNode = head->next;

    while (curNode != NULL) {
        printf("[%d]=%d ", count++, curNode->value);
        curNode = curNode->next;
    }

    printf("\n");
}


void doublyIntNodeAdd(DoublyIntNode *head, int elem) {
    DoublyIntNode *curNode = head;

    while (curNode->next != NULL) {
        curNode = curNode->next;
    }

    DoublyIntNode *newNode = doublyIntNodeCreate();
    newNode->next = curNode->next;
    newNode->value = elem;

    curNode->next = newNode;
    newNode->prev = curNode;

    head->value++;
}

int doublyIntNodeInsert(DoublyIntNode *head, int index, int elem) {
    if (index < 0 || index > head->value) {
        printf("index is illegal!\n");
        return 0;
    }

    DoublyIntNode *curNode = head;

    for (int i = 0; i < index; i++) {
        curNode = curNode->next;
    }

    DoublyIntNode *newNode = doublyIntNodeCreate();
    newNode->next = curNode->next;
    newNode->prev = curNode;
    newNode->value = elem;
    curNode->next = newNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }

    head->value++;


}

int doublyIntNodeDelete(DoublyIntNode *head, int index) {
    DoublyIntNode *delIndexNode = head;

    if (index >= delIndexNode->value) {
        printf("删除失败");
        return 0;
    }

    for (int i = 0; i < index + 1; i++) {
        delIndexNode = delIndexNode->next;
    }

    if (delIndexNode->next == NULL) {
        delIndexNode->prev->next = NULL;
    } else {

        delIndexNode->prev->next = delIndexNode->next;
        delIndexNode->next->prev = delIndexNode->prev;
    }

    delIndexNode->value = NULL;
    free(delIndexNode);
}

int doublyIntNodeDeleteElem(DoublyIntNode *head, int elem) {
    DoublyIntNode *beforeIndexNode = head;
    int count = 0;

    while (beforeIndexNode->next->value != elem) {
        beforeIndexNode = beforeIndexNode->next;
        count++;

        if (count == head->value) {
            printf("删除失败\n");
            return 0;
        }
    }

    DoublyIntNode *delIndexNode = beforeIndexNode->next;

    if (delIndexNode->next == NULL) {
        delIndexNode->prev->next = NULL;
    } else {

        delIndexNode->prev->next = delIndexNode->next;
        delIndexNode->next->prev = delIndexNode->prev;
    }

    delIndexNode->value = NULL;
    free(delIndexNode);
}

int doublyIntNodeGet(DoublyIntNode *head, int index) {
    DoublyIntNode *curIndexNode = head;

    if (index >= curIndexNode->value) {
        printf("查询失败");
        return 0;
    }

    for (int i = 0; i < index; i++) {
        curIndexNode = curIndexNode->next;
    }

    printf("所察数字是：%d\n", curIndexNode->next->value);
}

int doublyIntNodeUpdate(DoublyIntNode *head, int index, int elem) {
    DoublyIntNode *curIndexNode = head;

    if (index >= curIndexNode->value) {
        printf("更新失败");
        return 0;
    }

    for (int i = 0; i < index; i++) {
        curIndexNode = curIndexNode->next;
    }

    curIndexNode->next->value = elem;
    return 1;
}

void doublyIntNodeRevert(DoublyIntNode *head) {
    DoublyIntNode *curNode = head->next;
    DoublyIntNode *beforeNode = head;
    DoublyIntNode *firstNode = head->next;
    DoublyIntNode *temp;
    int count = head->value;
    if (head->next == NULL || head->value == 1) {
        return;
    }
    while (curNode != NULL) {
        temp = curNode->next;
        curNode->next = beforeNode;
        curNode->prev = temp;
        beforeNode = curNode;
        curNode = temp;
    }
    head->next = beforeNode;
    firstNode->next = NULL;
}


