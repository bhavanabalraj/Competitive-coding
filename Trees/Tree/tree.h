//
// Created by cegbh on 10/11/2019.
//

#ifndef TREES_TREE_H
#define TREES_TREE_H

#endif //TREES_TREE_H
#include<iostream>
#include<queue>
using namespace std;

class treeNode{
public:
    int value;
    treeNode *left, *right;
    treeNode(int val) : value(val){
        left = right = NULL;
    }
};

void insertTreeNode(treeNode **root, int value){
    treeNode* newNode = new treeNode(value);
    if(*root == NULL) {
        *root = newNode;
        return;
    }
    queue<treeNode*> q;
    q.push(*root);
    while(!q.empty()){
        treeNode *temp = q.front();
        q.pop();
        if(temp->left == NULL){
            temp->left = newNode;
            return;
        }
        q.push(temp->left);
        if(temp->right == NULL){
            temp->right = newNode;
            return;
        }
        q.push(temp->right);
    }
}

void printInorder(treeNode *root){
    if(!root)
        return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

//int main(){
//    treeNode *root = NULL;
//    insertTreeNode(&root, 5);
//    insertTreeNode(&root, 7);
//    insertTreeNode(&root, 9);
//    printInorder(root);
//}