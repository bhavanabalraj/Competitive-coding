//
// Created by cegbh on 10/12/2019.
//

#include <iostream>
#include "tree.h"
using namespace std;

treeNode* inOrderSuccessorRecursive(treeNode* root, treeNode* key) {

    if (root == NULL)
        return NULL;
    treeNode* temp;
    if (root == key || (temp = inOrderSuccessorRecursive(root->left, key)) ||
        (temp = inOrderSuccessorRecursive(root->right, key)))
    {
        if(temp){
            if(root->left == temp) {
                cout << root->value;
                return NULL;
            }
            return root;
        }
        return NULL;
    }
}

treeNode* leftmost(treeNode* root){
    if(root != NULL && root->left != NULL)
        return leftmost(root->left);
    return root;
}

treeNode* rightmost(treeNode* root){
    if(root != NULL && root->right != NULL)
        return rightmost(root->right);
    return root;
}

void inOrderSuccessor(treeNode* root, treeNode *key){
    if(key->right != NULL) {
        treeNode *success = leftmost(key->right);
        cout << success->value << endl;
    }
    if(key->right == NULL){
        if(key == rightmost(root))
            cout << "No successor" << endl;
        else
            inOrderSuccessorRecursive(root->left,key);
    }
}


int main() {
    treeNode *root = NULL;
    insertTreeNode(&root, 5);
    insertTreeNode(&root, 7);
    insertTreeNode(&root, 9);
    insertTreeNode(&root, 12);
    insertTreeNode(&root, 15);
    printInorder(root);
    inOrderSuccessor(root, root->left);
}
