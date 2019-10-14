//
// Created by cegbh on 10/11/2019.
//
#include<iostream>
#include "tree.h"
using namespace std;


int treeHeight(treeNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

int main(){
    treeNode *root = NULL;
    insertTreeNode(&root, 5);
    insertTreeNode(&root, 7);
    insertTreeNode(&root, 9);
    insertTreeNode(&root, 12);
    insertTreeNode(&root, 15);
    printInorder(root);
    cout << treeHeight(root);
}
