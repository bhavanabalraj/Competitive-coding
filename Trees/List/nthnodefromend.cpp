//
// Created by cegbh on 10/11/2019.
//
#include<iostream>
#include "list.h"
using namespace std;

listNode* nthNodeFromEnd(listNode* head, int n){
    listNode* tempHead = head;
    listNode* nthNode = head;
    int i = 0;
    while(i<n-1){
        if(nthNode == NULL)
            return NULL;
        nthNode = nthNode->next;
        i++;
    }
    while(nthNode->next != NULL){
        nthNode = nthNode->next;
        tempHead = tempHead->next;
    }
    return tempHead;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    listNode *head = NULL;
    insertNewNode(&head, 5);
    insertNewNode(&head, 7);
    insertNewNode(&head, 9);
    insertNewNode(&head, 12);
    insertNewNode(&head, 25);
    printNode(head);
    listNode* output = nthNodeFromEnd(head, 1);
    cout << output->value;
    return 0;
}
