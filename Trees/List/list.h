//
// Created by cegbh on 10/11/2019.
//

#ifndef TREES_LIST_H
#define TREES_LIST_H

#endif //TREES_LIST_H
#include<iostream>
using namespace std;

class listNode{
public:
    int value;
    listNode *next;
};

void insertNewNode(listNode **head, int value){
    listNode *newNode = new listNode();
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

void printNode(listNode *head){
    listNode *temp = head;
    while(temp!=NULL){
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout<<endl;
}