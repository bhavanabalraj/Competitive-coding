//
// Created by cegbh on 10/11/2019.
//

#include<iostream>
#include "tree.h"
using namespace std;

treeNode* getNewNode(int key){
    treeNode* newNode = new treeNode(key);
    return newNode;
}

void insertBST(treeNode* root, int key){

    treeNode *temp = root;
    if(temp->value > key) {
        if(temp->left == NULL)
            temp->left = getNewNode(key);
        insertBST(temp->left, key);
    }
    if(temp->value < key) {
        if(temp->right == NULL)
            temp->right = getNewNode(key);
        insertBST(temp->right, key);
    }
}

int main() {
    treeNode *root = getNewNode(17);
    insertBST(root, 5);
    insertBST(root, 7);
    insertBST(root, 8);
    insertBST(root, 9);
    insertBST(root, 12);
    insertBST(root, 15);
    insertBST(root, 23);
    insertBST(root, 28);
    printInorder(root);
}



