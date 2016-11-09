#include "LinkedList.h"

LinkedList::LinkedList()
{
    //ctor
}

LinkedList::Insert(Node*n){
		Node*cur = head;
        while(cur->next)
			cur = cur->next;
		cur->next = n;
}

float LinkedList::exponent(float base,float e){
    if(e == 0){
        return 1;
    }
    if(e == 0){
        return base;
    }
    return base * exponent(base,e-1);
}

float LinkedList::print(Node*ptr,float x,std::ofstream &file){
    if(ptr->next){
        sum += exponent(x,ptr->exp) + print(ptr->next,x,file);
        file << " " << ptr->getBase() << "x^" << ptr->getExp() << " ";
    }
    else{
        file << " = " << sum;
    }
}

void LinkedList::deleteM(Node*h){
    Node*hold;
    if(!head->next){
        delete head;
        return;
    }
    head = hold;
    head = head->next;
    delete head;
    deleteM(head);
}
LinkedList::~LinkedList()
{
    //dtor
    deleteM(head);

}
