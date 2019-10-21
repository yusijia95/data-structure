//
// Created by 李熠 on 2019/10/10.
//
#include "circularIntNode.h"

int main(void) {
    CircularIntNode *node = circularIntNodeCreate();
    circularIntNodeAdd(node, 1);
//    circularIntNodeAdd(node, 2);
//    circularIntNodeAdd(node, 3);
//    circularIntNodeAdd(node, 4);
//    circularIntNodeAdd(node, 5);
    circularIntNodeDisplay(node);
//    circularIntNodeInsert(node, 2, 25);
//    circularIntNodeInsert(node, 0, 100);
//    circularIntNodeDisplay(node);
//    circularIntNodeDelete(node,5);
//    circularIntNodeUpdate(node,2,10);
//    circularIntNodeGet(node,4);
//    circularIntNodeDeleteNode(node, node->next->next->next->next);
    circularIntNodeDisplay(node);


    circularIntNodeDestroy(node);
    node = NULL;

}
