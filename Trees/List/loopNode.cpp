//
// Created by cegbh on 10/11/2019.
//
#include "list.h"
#include<set>

using namespace std;

bool detectLoop(listNode *head) {
    set<listNode*> s;
    listNode* temp = head;
    while(temp != NULL) {
        if(s.find(temp) != s.end()){
            return true;
        }
        s.emplace(temp);
        temp = temp->next;
    }
    return false;
}

int main() {
    listNode *head = NULL;
    insertNewNode(&head, 5);
    insertNewNode(&head, 7);
    insertNewNode(&head, 9);
    insertNewNode(&head, 12);
    insertNewNode(&head, 25);
    printNode(head);
    /*listNode *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head; */
    cout << detectLoop(head);
    return 0;
}

