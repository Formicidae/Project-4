#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <Node.h>
#include <fstream>


class LinkedList
{
    public:
        LinkedList();
        LinkedList(Node*h){head = h;};
        Node*head;
        float sum;
        getSum(){return sum;};
        Node* getHead(){return head;};
        setHead(Node*h){head = h;};
        Insert(Node*n);
        float print(Node* ptr,float x,std::ofstream &file);
        float exponent(float b,float exp);
        void deleteM(Node*h);

        ~LinkedList();

    private:
};

#endif // LINKEDLIST_H
