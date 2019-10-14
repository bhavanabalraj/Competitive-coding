//
// Created by cegbh on 10/12/2019.
//

#include<iostream>
#include<stack>
#include "tree.h"
using namespace std;

void spiralTraversal(treeNode *root){
    stack<treeNode*> s1, s2;
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){
        cout << root->value << " ";
        return;
    }
    s1.push(root);
    while((!s1.empty())||(!s2.empty())){
        while(!s1.empty()) {
            treeNode *temp = s1.top();
            cout << temp->value << " ";
            if(temp->right != NULL)
                s2.push(temp->right);
            if(temp->left != NULL)
                s2.push(temp->left);
            s1.pop();
        }
        while(!s2.empty()) {
            treeNode *temp = s2.top();
            cout << temp->value << " ";
            if(temp->left != NULL)
                s1.push(temp->left);
            if(temp->right != NULL)
                s1.push(temp->right);
            s2.pop();
        }
    }
}

int main(){
    treeNode *root = NULL;
    insertTreeNode(&root, 5);
    insertTreeNode(&root, 7);
    insertTreeNode(&root, 9);
    insertTreeNode(&root, 12);
    insertTreeNode(&root, 15);
    insertTreeNode(&root, 23);
    insertTreeNode(&root, 28);
    printInorder(root);
    cout << endl;
    spiralTraversal(root);
}




