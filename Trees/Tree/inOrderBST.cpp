//
// Created by cegbh on 10/13/2019.
//
#include <iostream>
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

treeNode* leftMost(treeNode* root){
    if(root != NULL && root->left == NULL)
        return root;
    return leftMost(root->left);
}

treeNode* inOrderBSTSuccessor(treeNode* root, treeNode* key){
    if(key->right != NULL){
        return leftMost(key->right);
    }
    treeNode* succ = NULL;
    while(root->value != key->value) {
        if (key->value < root->value) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

int main() {
    treeNode *root = getNewNode(17);
    insertBST(root, 5);
    insertBST(root, 7);
    insertBST(root, 9);
    insertBST(root, 8);
    insertBST(root, 15);
    insertBST(root, 12);
    insertBST(root, 23);
    insertBST(root, 28);
    printInorder(root);
    cout << inOrderBSTSuccessor(root, root->left->right->right->left)->value;
}
