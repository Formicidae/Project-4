#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node(){next = nullptr; isnull = true;};
        Node(float b, int e, Node*n){base = b;exp = e;next = n;isnull = false;};
        float base;
        int exp;
        bool isnull;
        Node*next = nullptr;
        float getBase(){return base;};
        int getExp(){return exp;};
        Node* getNext(){return next;};
        void setBase(float b){base = b;};
        void setExp(int e){exp = e;};
        void setNext(Node*n){next = n;isnull = false;};
        bool notNull(){return isnull;};


    private:
};

#endif // NODE_H
