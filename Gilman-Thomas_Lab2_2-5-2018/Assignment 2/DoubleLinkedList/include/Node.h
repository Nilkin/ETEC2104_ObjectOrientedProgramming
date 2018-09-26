#ifndef NODE_H
#define NODE_H

template<typename T>;
struct Node
{
    T data;
    struct Node *next;
    struct Node *prev;
};

#endif // NODE_H
