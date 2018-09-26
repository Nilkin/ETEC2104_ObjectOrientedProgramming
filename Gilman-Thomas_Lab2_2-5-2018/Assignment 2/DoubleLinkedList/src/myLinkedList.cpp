#include "myLinkedList.h"

myLinkedList::myLinkedList()
{};
myLinkedList::~myLinkedList()
{
    while(head->next != nullptr)
    {
        head = head->next;
    }

    while(head->prev != nullptr)
    {
        head = head->prev;
        delete head->next;
    }
    delete head;
};
myLinkedList::Node::Node()
{};
void myLinkedList::push(struct Node** headRef, int newData) //headRef is the node that is passed in the main.cpp
{
    struct Node* newNode = new Node(); //create node and allocate data
    newNode->data = newData;

    newNode->next = (*headRef);
    newNode->prev = nullptr;

    if((*headRef) != nullptr) //make prev of head node to a new node
        (*headRef)->prev = newNode;

    (*headRef) = newNode;
};
void myLinkedList::insertAfter(struct Node* prevNode, int newData) //headRef is the node that is passed in the main.cpp
{
    if(prevNode == nullptr)
    {
        std::cout<<"the node given cannot be void"<<std::endl;
        return;
    }
    struct Node* newNode = new Node();
    newNode->data = newData;

    newNode->next = prevNode->next; //insert Node between prevNode and nextNode and point to nextNode
    prevNode->next = newNode; //make prevNode next point to newNode
    newNode->prev = prevNode; //newNodes prev is prevNode

    if(newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
};
void myLinkedList::append(struct Node** headRef, int newData) //headRef is the node that is passed in the main.cpp
{
    struct Node* newNode = new Node();
    struct Node *last = *headRef;

    newNode->data = newData;
    newNode->next = nullptr;

    if(*headRef == nullptr)
    {
        newNode->prev = nullptr;
        *headRef = newNode;
        return;
    }
    while(last->next != nullptr)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    return;
};
//overrides Nodes printList
void myLinkedList::printList(struct Node *node) //prints out the data of each node forward through the list
{
    struct Node *last;
    std::cout<<"moving through the list"<<std::endl;
    while(node!=nullptr)
    {
        std::cout<<"Node Data: "<<node->data<<std::endl; //print out node data
        last = node;
        node = node->next; //go to next node while node is not void;
    }
    std::cout<<"Moving backwards through the list"<<std::endl;
    while(last != nullptr)
    {
        std::cout<<"Node Data: "<<last->data<<std::endl;
        last = last->prev;
    }
};
void myLinkedList::Node::printList()
{
    std::cout<<"LIST"<<std::endl;
};

daddyLister::daddyLister()
{};
daddyLister::~daddyLister()
{};
void daddyLister::printList() //prints out the data of each node forward through the list
{
    std::cout<<"TSIL"<<std::endl;
};



