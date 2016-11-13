#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <Node.h>
#include <fstream>


class LinkedList
{
    public:
        LinkedList();
        LinkedList(Node*h){head = h;};
        Node*head = new Node();
        float sum = 0;
        bool headset = false;
        getSum(){return sum;};
        Node* getHead(){return head;};
        void setHead(Node*h){head = h;};
        void Insert(Node*n);
        //void print(std::ofstream &file);
        float print(Node* ptr,float x,std::ofstream &file);
        float exponent(float b,float exp);
        void deleteM(Node*h);
        void addtoSum(float f){sum += f;};
        float getsum(){return sum;};

        ~LinkedList();

    private:
};

#endif // LINKEDLIST_H
