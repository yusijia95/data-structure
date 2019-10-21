//
// Created by 李熠 on 2019/10/10.
//
#include "circularIntNode.h"

CircularIntNode *circularIntNodeCreate() {
    CircularIntNode *rlt = (CircularIntNode *) malloc(sizeof(CircularIntNode));
    rlt->value = 0;
    rlt->next = NULL;
    return rlt;
}

void circularIntNodeAdd(CircularIntNode *head, int elem) {
    CircularIntNode *newNode = circularIntNodeCreate();
    CircularIntNode *lastNode = head->next;
    if (lastNode == NULL) {
        newNode->next = newNode;
        head->next = newNode;
    } else {
        while (lastNode->next != head->next) {
            lastNode = lastNode->next;
        }
        newNode->next = head->next;
        lastNode->next = newNode;
    }
    newNode->value = elem;
    head->value++;
}

void circularIntNodeDisplay(const CircularIntNode *head) {
    printf("circular node size=%d\n", head->value);
    if (head->next == NULL) {
        return;
    }
    CircularIntNode *curNode = head->next;
    int count = 0;
    while (curNode->next != head->next) {
        printf("[%d]=%d ", count++, curNode->value);
        curNode = curNode->next;
    }
    printf("[%d]=%d", count, curNode->value);
    printf("\n");
}

void circularIntNodeDestroy(CircularIntNode *head) {
    if (head->next == NULL) {
        free(head);
        return;
    }

    CircularIntNode *curNode = head;

    CircularIntNode *temp;
    while (curNode != head->next) {
        temp = curNode->next;
        free(curNode);
        curNode = temp;
    }
}

int circularIntNodeInsert(CircularIntNode *head, int index, int elem) {
    if (index < 0 || index >= head->value) {
        printf("index is illegal!");
        return 0;
    }
    CircularIntNode *newNode = circularIntNodeCreate();
    CircularIntNode *lastNode = head->next;
    CircularIntNode *firstNode = head->next;
    if (index == 0) {
        while (lastNode->next != head->next) {
            lastNode = lastNode->next;
        }
        newNode->next = firstNode;
        newNode->value = elem;
        lastNode->next = newNode;
        head->next = newNode;
        head->value++;
        return 1;
    }

    CircularIntNode *beforeIndexNode = head;
    for (int i = 0; i < index; ++i) {
        beforeIndexNode = beforeIndexNode->next;
    }

    newNode->next = beforeIndexNode->next;
    newNode->value = elem;
    beforeIndexNode->next = newNode;
    head->value++;
    return 1;

}

int circularIntNodeDelete(CircularIntNode *head, int index) {
    if (index < 0 || index >= head->value) {
        printf("index is illegal!");
        return 0;
    }

    CircularIntNode *lastNode = head->next;
    CircularIntNode *firstNode = head->next;
    CircularIntNode *deleteNode = head->next;
    if (index == 0) {
        while (lastNode->next != head->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = deleteNode->next;
        head->next = deleteNode->next;
        head->value--;
        free(deleteNode);
        return 1;
    }

    CircularIntNode *beforeIndexNode = head;
    for (int i = 0; i < index; ++i) {
        beforeIndexNode = beforeIndexNode->next;
    }
    deleteNode = beforeIndexNode->next;
    beforeIndexNode->next = deleteNode->next;
    free(deleteNode);
    head->value--;
    return 1;

}

int circularIntNodeDeleteNode(CircularIntNode *head, CircularIntNode *deleteNode) {

    CircularIntNode *lastNode = head->next;
    CircularIntNode *firstNode = head->next;
    if (firstNode == deleteNode) {
        while (lastNode->next != head->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = deleteNode->next;
        head->next = deleteNode->next;
        head->value--;
        free(deleteNode);
        return 1;
    }

    CircularIntNode *beforeIndexNode = head;
    while (beforeIndexNode->next != deleteNode) {
        beforeIndexNode = beforeIndexNode->next;
    }

    deleteNode = beforeIndexNode->next;
    beforeIndexNode->next = deleteNode->next;
    free(deleteNode);
    head->value--;
    return 1;
}

void circularIntNodeRevert(CircularIntNode *list) {
    if (list->value <= 1) {
        return;
    }

    int count = list->value;
    CircularIntNode *firstNode = list->next;
    CircularIntNode *temp;
    CircularIntNode *curNode = list->next;
    CircularIntNode *beforeNode = list;
    // 最后一次执行完成后，beforeNode是最后一个节点
    // curNode 已经是第一个节点了
    for (int i = 0; i < count; i++) {
        temp = curNode->next;
        curNode->next = beforeNode;
        beforeNode = curNode;
        curNode = temp;
    }
    // 将头指向最后一个节点
    list->next = beforeNode;
    // 将第一个节点也指向最后一个节点，完成反向
    firstNode->next = beforeNode;
}

int circularIntNodeUpdate(CircularIntNode *head, int index, int elem) {
    CircularIntNode *beforeNode = head;
    if (index >= head->value) {
        printf("查询失败");
        return 0;
    }
    for (int i = 0; i < index; i++) {
        beforeNode = beforeNode->next;
    }
    beforeNode->next->value = elem;
}

int circularIntNodeGet(CircularIntNode *head, int index) {
    CircularIntNode *beforeNode = head;
    if (index >= head->value) {
        printf("更新失败");
        return 0;
    }
    for (int i = 0; i < index; i++) {
        beforeNode = beforeNode->next;
    }
    printf("%d\n",beforeNode->next->value);
}