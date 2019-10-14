//
// Created by cegbh on 10/11/2019.
//

#include<iostream>
#include "tree.h"
using namespace std;

void mirrorTree(treeNode* root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    treeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){
    treeNode *root = NULL;
    insertTreeNode(&root, 5);
    insertTreeNode(&root, 7);
    insertTreeNode(&root, 9);
    insertTreeNode(&root, 12);
    insertTreeNode(&root, 15);
    printInorder(root);
    cout << endl;
    mirrorTree(root);
    printInorder(root);
}

