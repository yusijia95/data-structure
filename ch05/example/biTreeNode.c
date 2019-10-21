#include "biTreeNode.h"

void printBiTreeElement(BiTreeElement elem) {
    printf("%s ", elem);
}

/**
 * 创建树
 * @return 树根节点指针
 */
BiTreeNodeAddr biTreeCreate(BiTreeElement elem) {
    BiTreeNodeAddr rlt = (BiTreeNodeAddr) malloc(sizeof(BiTreeNode));
    rlt->element = elem;
    rlt->left = NULL;
    rlt->right = NULL;
    return rlt;
}

int biTreePutLeaf(BiTreeNodeAddr nodeAddr, BiTreeElement leftElem, BiTreeElement rightElem) {
    if (leftElem != NULL) {
        if (nodeAddr->left == NULL) {
            nodeAddr->left = biTreeCreate(leftElem);
        } else {
            nodeAddr->left->element = leftElem;
        }
    }

    if (rightElem != NULL) {
        if (nodeAddr->right == NULL) {
            nodeAddr->right = biTreeCreate(rightElem);
        } else {
            nodeAddr->right->element = rightElem;
        }
    }

    return 1;
}


void biTreePreOrder(BiTreeNodeAddr nodeAddr) {
    if (nodeAddr == NULL) {
        return;
    }
    printBiTreeElement(nodeAddr->element);
    biTreePreOrder(nodeAddr->left);
    biTreePreOrder(nodeAddr->right);
}

void biTreeInOrder(BiTreeNodeAddr nodeAddr) {
    if (nodeAddr == NULL) {
        return;
    }
    biTreeInOrder(nodeAddr->left);
    printBiTreeElement(nodeAddr->element);
    biTreeInOrder(nodeAddr->right);
}

void biTreePostOrder(BiTreeNodeAddr nodeAddr) {
    if (nodeAddr == NULL) {
        return;
    }
    biTreePostOrder(nodeAddr->left);
    biTreePostOrder(nodeAddr->right);
    printBiTreeElement(nodeAddr->element);
}

void biTreeLeaf(BiTreeNodeAddr nodeAddr) {
    if (nodeAddr == NULL) {
        return;
    }
    if (nodeAddr->left == NULL && nodeAddr->right == NULL) {
        printBiTreeElement(nodeAddr->element);
    }
    biTreeLeaf(nodeAddr->left);
    biTreeLeaf(nodeAddr->right);
}

int biTreeGetLeafNum(BiTreeNodeAddr nodeAddr) {
    int count = 0;
    if (nodeAddr == NULL) {
        return count;
    }
    if (nodeAddr->left == NULL && nodeAddr->right == NULL) {
        count++;
    }
    count += biTreeGetLeafNum(nodeAddr->left);
    count += biTreeGetLeafNum(nodeAddr->right);
    return count;
}

int biTreeGetHeight(BiTreeNodeAddr nodeAddr) {
    int deep = 0;
    if (nodeAddr != NULL) {
        int leftdeep = biTreeGetHeight(nodeAddr->left);
        int rightdeep = biTreeGetHeight(nodeAddr->right);
        deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
//        deep = leftdeep + 1;
    }
    return deep;
}


