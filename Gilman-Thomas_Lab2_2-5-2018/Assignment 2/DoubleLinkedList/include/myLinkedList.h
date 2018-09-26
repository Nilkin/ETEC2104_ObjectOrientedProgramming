#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

class myLinkedList
{
    public:
        struct Node
        {
            Node();
            int data;
            struct Node *next, *prev;
            virtual void printList();
        };
        myLinkedList();
        struct Node* head = nullptr;
        virtual ~myLinkedList();
    void push(Node** headRef, int newData);
    void insertAfter(Node* prevNode, int newData);
    void append(Node** headRef, int newData);
    void printList(Node *node);
};

class daddyLister : public myLinkedList::Node
{
    public:
        daddyLister();
        virtual ~daddyLister();
        void printList();
};


#endif // MYLINKEDLIST_H
