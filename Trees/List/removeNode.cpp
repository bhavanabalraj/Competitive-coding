//
// Created by cegbh on 10/11/2019.
//

#include<iostream>
#include "list.h"
using namespace std;

void removeNode(listNode **head, int value){
    if(head == NULL) {
        return;
    }
    listNode *prev, *temp;
    prev = *head;
    temp = *head;
    if(temp->value == value){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp->value != value && temp != NULL) {
        prev=temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
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
    removeNode(&head, 7);
    printNode(head);
    return 0;
}

