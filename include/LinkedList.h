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
        long double sum = 0;
        bool headset = false;
        getSum(){return sum;};
        Node* getHead(){return head;};
        void setHead(Node*h){head = h;};
        void Insert(Node*n);
        long double print(Node* ptr,long double x,std::ofstream &file);
        long double exponent(long double b,long double exp);
        void deleteM(Node*h);
        void addtoSum(long double f){sum += f;};
        long double getsum(){return sum;};
        void SortD(Node*&head);

        ~LinkedList();

    private:
};

#endif // LINKEDLIST_H
