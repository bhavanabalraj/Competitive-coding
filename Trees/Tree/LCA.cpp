//
// Created by cegbh on 10/12/2019.
//

#include<iostream>
#include "tree.h"
using namespace std;

bool findNode(treeNode* root, int key){
    if(root == NULL)
        return false;
    if(root->value == key)
        return true;
    return (findNode(root->left, key) || findNode(root->right, key));
}

treeNode* LCA(treeNode* root, int key_1, int key_2){
    if(root == NULL)
        return NULL;
    if(findNode(root->left, key_1) && findNode(root->right, key_2))
        return root;
    treeNode* lca_left = LCA(root->left, key_1, key_2);
    return lca_left ? lca_left : LCA(root->right, key_1, key_2);
}

treeNode* LCASimple(treeNode* root, int key_1, int key_2){
    if(root == NULL)
        return NULL;
    if(root->value == key_1 || root->value == key_2)
        return root;
    treeNode* left_lca = LCASimple(root->left, key_1, key_2);
    treeNode* right_lca = LCASimple(root->right, key_1, key_2);
    if(left_lca && right_lca)
        return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main(){
    treeNode *root = NULL;
    insertTreeNode(&root, 5);
    insertTreeNode(&root, 7);
    insertTreeNode(&root, 9);
    insertTreeNode(&root, 12);
    insertTreeNode(&root, 15);
    printInorder(root);
    cout << findNode(root,15);
    cout << endl;
    treeNode* lca = LCA(root, 7, 15);
    cout << lca->value << endl;
    lca = LCASimple(root, 5, 15);
    cout << lca->value << endl;
}

