#include "doublyIntNode.h"

int main(void) {
    DoublyIntNode *node = doublyIntNodeCreate();
    doublyIntNodeAdd(node, 1);
    doublyIntNodeAdd(node, 2);
    doublyIntNodeAdd(node, 3);
    doublyIntNodeAdd(node, 4);
    doublyIntNodeAdd(node, 5);
    doublyIntNodeDisplay(node);
     doublyIntNodeInsert(node, 5, 25);
    // doublyIntNodeDelete(node, 4);
    // doublyIntNodeDeleteElem(node, 4);
    // doublyIntNodeUpdate(node,4,1);
    // doublyIntNodeGet(node, 1);
//    doublyIntNodeRevert(node);
    doublyIntNodeDisplay(node);
//
//
    doublyIntNodeDestroy(node);

}