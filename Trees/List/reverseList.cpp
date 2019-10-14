//
// Created by cegbh on 10/11/2019.
//

#include<iostream>
#include "list.h"
using namespace std;

void reverseLinkedList(listNode** head){
    listNode *prev = NULL;
    listNode *curr = *head;
    listNode *nextNode = (*head)->next;
    while(nextNode != NULL){
        curr-> next = prev;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    }
    curr->next = prev;
    *head = curr;
}

listNode* reversek(listNode *head, int k){
    listNode *prev = NULL;
    listNode *curr = head;
    listNode *nextNode = NULL;
    int i = 0;
    while(curr != NULL && i < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            i++;
    }
    if(nextNode != NULL)
        head->next = reversek(nextNode, k);
    return prev;
}

int main() {
    listNode *head = NULL;
    insertNewNode(&head, 5);
    insertNewNode(&head, 7);
    insertNewNode(&head, 9);
    insertNewNode(&head, 12);
    insertNewNode(&head, 25);
    insertNewNode(&head, 16);
    printNode(head);
//    reverseLinkedList(&head);
    listNode* newNode = reversek(head, 2);
    printNode(newNode);

}
