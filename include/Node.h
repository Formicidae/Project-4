#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(float b, float e, Node*n){base = b;exp = e;next = n;};
        float base;
        float exp;
        Node*next;
        float getBase(){return base;};
        float getExp(){return exp;};
        Node* getNext(){return next;};
        setBase(float b){base = b;};
        setExp(float e){exp = e;};
        setNext(Node*n){next = n;};


    private:
};

#endif // NODE_H
