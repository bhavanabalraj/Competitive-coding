//
// Created by cegbh on 10/12/2019.
//

#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include "tree.h"
using namespace std;

void countPaths(treeNode* root, int sum, int curr_sum, int *count){
    if(root == NULL)
        return;
    curr_sum += root->value;
    if(sum == curr_sum)
        (*count)++;
    countPaths(root->left, sum, curr_sum, count);
    countPaths(root->right, sum, curr_sum, count);
}
void printVector(vector<treeNode*> v){
    vector<treeNode*>::iterator it = v.begin();
    while(it != v.end()){
        cout << (*it)->value << " ";
        ++it;
    }
    cout << endl;
}
void printList(list<treeNode*> v){
    std::list<treeNode*>::iterator it = v.begin();
    while(it != v.end()){
        cout << (*it)->value << " ";
        ++it;
    }
    cout << endl;
}

int levelOrder(treeNode* root, int sum) {

//    ------------ VECTOR ITERATION INVALIDATION ---------------
//    vector<treeNode*> v;
//    v.emplace_back(root);
//    vector<treeNode*>::iterator it = v.begin();
//    while(it != v.end()){
//        cout << (*it)->left << " " << root->left << endl;
//        cout << (*it)->left->value << " " << (*it)->right->value<< endl;
//        //treeNode ** left = &(*it)->left;
//        cout << *it << endl;
//        if((*it)->left != NULL)
//            v.emplace_back((*it)->left);
//        printVector(v);
//        cout << *it << endl;
//
//        if((*it)->right != NULL)
//            v.emplace_back((*it)->right);
//        ++it;
//        printVector(v);
//    }

//    queue<treeNode*> q;
//    vector<treeNode*> v;
//    q.push(root);
//    while(!q.empty()){
//        treeNode *temp = q.front();
//        q.pop();
//        if(temp->left)
//            q.push(temp->left);
//        if(temp->right)
//            q.push(temp->right);
//        v.emplace_back(temp);
//    }
//    printVector(v);

      std::list<treeNode*> l;
      l.push_back(root);
      std::list<treeNode*>::iterator it = l.begin();
      while(it != l.end()){
          if((*it)->left)
              l.push_back((*it)->left);
          if((*it)->right)
              l.push_back((*it)->right);
          ++it;
      }
      printList(l);
      int pathCount = 0;
      it = l.begin();
      while(it != l.end()){
        cout << (*it)->value << " ";
         countPaths(*it, sum, 0, &pathCount);
           ++it;
      }
      return pathCount;
}

int main(){
    treeNode *root = NULL;
    insertTreeNode(&root, 7);
    insertTreeNode(&root, 5);
    insertTreeNode(&root, 10);
    insertTreeNode(&root, 3);
    insertTreeNode(&root, 6);
    insertTreeNode(&root, 8);
    insertTreeNode(&root, 13);
    printInorder(root);
    cout << endl;
    cout << levelOrder(root, 18);
}
