//
// Created by cegbh on 10/12/2019.
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

treeNode* LCABST(treeNode* root, int key_1, int key_2){
    if(root == NULL)
        return NULL;
    if((key_1 <= root->value && key_2 >= root->value) || (key_2 <= root->value && key_1 >= root->value))
        return root;
    if(key_1 < root->value && key_2 < root->value)
        return LCABST(root->left, key_1, key_2);
    return LCABST(root->right, key_1, key_2);
}

int main() {
    treeNode *root = getNewNode(17);
    insertBST(root, 5);
    insertBST(root, 12);
    insertBST(root, 7);
    insertBST(root, 9);
    insertBST(root, 8);
    insertBST(root, 15);
    insertBST(root, 23);
    insertBST(root, 28);
    printInorder(root);
    cout << endl;
    cout << (LCABST(root, 15, 7))->value << endl;

}
