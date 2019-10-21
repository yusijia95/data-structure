#include "singlyIntNode.h"

int main(void) {
    SinglyIntNode *node = singlyIntNodeCreate();
    singlyIntNodeAdd(node, 1);
    singlyIntNodeAdd(node, 2);
    singlyIntNodeAdd(node, 3);
    singlyIntNodeAdd(node, 4);
    singlyIntNodeAdd(node, 5);
//    singlyIntNodeDisplay(node);
//    singlyIntNodeInsert(node, 2, 25);
    singlyIntNodeDisplay(node);
    // singlyIntNodeInsert(node, 4, 100);
    // singlyIntNodeDelete(node,4);
    // singlyIntNodeDeleteElem(node,2);
    // singlyIntNodeUpdate(node,4,2);
    //singlyIntNodeGet(node,4);
    singlyIntNodeRevert(node);
    singlyIntNodeDisplay(node);

    singlyIntNodeDestroy(node);
    node = NULL;

}


