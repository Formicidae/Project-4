#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node(){next = nullptr; isnull = true;};
        Node(long double b, int e, Node*n){base = b;exp = e;next = n;isnull = false;};
        long double base;
        int exp;
        bool isnull;
        Node*next = nullptr;
        long double getBase(){return base;};
        int getExp(){return exp;};
        Node* getNext(){return next;};
        void setBase(long double b){base = b;};
        void setExp(int e){exp = e;};
        void setNext(Node*n){next = n;isnull = false;};
        bool notNull(){return isnull;};


    private:
};

#endif // NODE_H
