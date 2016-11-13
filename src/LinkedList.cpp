#include "LinkedList.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <iostream>

LinkedList::LinkedList()
{
    //ctor
}

void LinkedList::Insert(Node*n){

		if(!headset){
            std::cout << "First term";
            head->setBase(n->getBase());
            head->setExp(n->getExp());
            std::cout << "\n\t\t\tBase: " << head->getBase() << "\n" << "\t\t\tExp: " << head->getExp() << "\n";
            headset = true;
            return;
		}
		Node*cur = head;
        while(cur->next)
			cur = cur->next;
        n->next = nullptr;
		cur->next = n;
		//std::cout << "\n\t\t\tBase: " << cur->next->getBase() << "\n" << "\t\t\tExp: " << cur->next->getExp() << "\n";

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
/*
void LinkedList::print(std::ofstream &file){
    file << " " << head->getBase() << "x^" << head->getExp() << " ";


}
*/

float LinkedList::print(Node*ptr,float x,std::ofstream &file){
    std::cout << " " << head->getBase() << "x^" << head->getExp() << " ";
    //file << " " << head->next->getBase() << "x^" << head->next->getExp() << " ";
    if(ptr->next){
        std::cout << "Going next";
        file << " " << ptr->getBase() << "x^" << ptr->getExp() << " ";
        std::cout << "printBase: " << ptr->getBase() << "\n" << "printExp: " << ptr->getExp();
        addtoSum(ptr->getBase() * pow(x,ptr->exp));
        std::cout << "\tAdding to sum" << (ptr->getBase() * pow(x,ptr->exp));
        print(ptr->next,x,file);
    }
    else{
        file << " " << ptr->getBase() << "x^" << ptr->getExp() << " ";
        addtoSum(ptr->getBase() * pow(x,ptr->exp));
        std::cout << "\tAdding to sum" << (ptr->getBase() * pow(x,ptr->exp));
        //file.setf(fstream::fixed, fstream::floatfield);
        file << std::fixed;
        //file.precision(3);
        file << " = " << getsum();
        std::cout << "print2Base: " << ptr->getBase() << "\n" << "print2Exp: " << ptr->getExp();
    }
}


void LinkedList::deleteM(Node*h){

    Node*hold;
    if(h->next = nullptr){
        delete head;
        return;
    }
    hold = h;
    h = h->next;
    delete hold;
    deleteM(h);
}

LinkedList::~LinkedList()
{
    //dtor
    //deleteM(head);

}
