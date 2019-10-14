//
// Created by cegbh on 10/11/2019.
//
#include<iostream>
#include<vector>
#include "tree.h"
using namespace std;

void printRootToLeaf(treeNode* root, std::vector<treeNode*> &v){
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){
        vector<treeNode*>::iterator it;
        for(it = v.begin(); it != v.end(); ++it){
            cout << (*it)->value << " ";
        }
        cout << root->value << endl;
        return;
    }
    v.emplace_back(root);
    printRootToLeaf(root->left,v);
    printRootToLeaf(root->right, v);
    v.pop_back();
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
    std::vector<treeNode*> v;
    printRootToLeaf(root, v);
}



