#include "seqlist.h"

SeqList *seqListCreate() {
    SeqList *seqListAddr = (SeqList *) malloc(sizeof(SeqList));
    seqListAddr->head = (int *) calloc(CAPACITY_STEP_SIZE, sizeof(int));
    seqListAddr->length = 0;
    seqListAddr->capacity = CAPACITY_STEP_SIZE;
    return seqListAddr;
}

void seqListDestroy(SeqList *list) {
    int *p = list->head;
    free(list);
    free(p);
}

void seqListAdd(SeqList *list, int elem) {
    if (list->length == list->capacity) {
        list->head = (int *) realloc(list->head, (list->capacity + CAPACITY_STEP_SIZE) * sizeof(int));
        list->capacity += CAPACITY_STEP_SIZE;
    }

    list->head[list->length] = elem;
    list->length++;
}

// SeqList seqListCreateDirect() {
//     SeqList seqList;
//     seqList.head = (int *) calloc(CAPACITY_STEP_SIZE, sizeof(int));
//     seqList.length = 0;
//     seqList.capacity = CAPACITY_STEP_SIZE;
//     printf("inside = %p\n", &seqList);
//     return seqList;
// }

void seqListDisplay(const SeqList *seqList) {
    for (int i = 0; i < seqList->length; i++) {
        printf("[%d]=%d\n", i, seqList->head[i]);
    }
}

int seqListDelete(SeqList *list, int index) {
    if (index <= list->length) {
        list->head[index] = NULL;
        for(int i=index;i<list->length;i++){
            list->head[i]=list->head[i+1];
        }
        list->length--;
        return 1;
    } else {
        printf("删除失败");
        return 0;
    }

}

int seqListDeleteElem(SeqList *list, int elem) {
    int count = 0;

    while (list->head[count] != elem) {
        count++;

        if (count == list->length) {
            printf("删除失败\n");
            return 0;
        }
    }

    if (count == list->length - 1) {
        list->head[count] = NULL;
    } else {
        for (int i = count; i < list->length; i++) {

            list->head[i] = list->head[i + 1];
        }
    }

    list->length--;
    return 1;
}

void seqListRevert(SeqList *list) {
    int count = 0;

    while (list->head[count]) {
        count++;
    }

    printf("%d\n", count);

    for (int i = 0; i < count / 2; i++) {
        int temp = list->head[i];
        list->head[i] = list->head[count - i - 1];
        list->head[count - i - 1] = temp;
    }
}

int seqListInsert(SeqList *list, int index, int elem) {
    if (list->length == list->capacity) {
        list->head = (int *) realloc(list->head, (list->capacity + CAPACITY_STEP_SIZE) * sizeof(int));
        list->capacity += CAPACITY_STEP_SIZE;
    }

    if (index <= list->capacity) {
        for (int i = list->length - 1; i >= index; i--) {
            list->head[i + 1] = list->head[i];
        }

        list->head[index] = elem;

    } else {
        printf("插入失败");
    }
}

int seqListUpdate(SeqList *list, int index, int elem) {
    if (index <= list->capacity) {

        list->head[index] = elem;

    } else {
        printf("更新失败");
    }
}

int seqListGet(SeqList *list, int index) {
    if (index <= list->capacity) {
        return list->head[index];
//        printf("查询数字为%d\n", list->head[index]);

    } else {
        printf("查询失败");
    }
}

