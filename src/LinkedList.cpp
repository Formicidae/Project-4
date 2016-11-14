#include "LinkedList.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <iostream>

LinkedList::LinkedList()
{
    //ctor
    headset = false;
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


float LinkedList::print(Node*ptr,float x,std::ofstream &file){
    std::cout << " " << head->getBase() << "x^" << head->getExp() << " ";
    long double base;
    int exp;
    long double powe;
    //file << " " << head->next->getBase() << "x^" << head->next->getExp() << " ";
    if(ptr->next){
        std::cout << "Going next";
        if(ptr == head){
            if(ptr->getBase() >= 0){
                if(ptr->getExp() == 0){
                    file << " " << ptr->getBase();
                }
                else if(ptr->getExp() == 1){
                    file << " " << ptr->getBase() << "x";
                }
                else{
                    file << " " << ptr->getBase() << "x^" << ptr->getExp();
                }
            }
            else{
                if(ptr->getExp() == 0){
                    file << " -" << (-1 * ptr->getBase());
                }
                else if(ptr->getExp() == 1){
                    file << " -" << (-1 * ptr->getBase()) << "x";
                }
                else{
                    file << " -" << (-1 * ptr->getBase()) << "x^" << ptr->getExp();
                }
            }
        }
        else{
            if(ptr->getBase() >= 0){
                if(ptr->getExp() == 0){
                    file << " + " << ptr->getBase();
                }
                else if(ptr->getExp() == 1){
                    file << " + " << ptr->getBase() << "x";
                }
                else{
                    file << " + " << ptr->getBase() << "x^" << ptr->getExp();
                }
            }
            else{
                if(ptr->getExp() == 0){
                    file << " - " << (-1 * ptr->getBase());
                }
                else if(ptr->getExp() == 1){
                    file << " - " << (-1 * ptr->getBase()) << "x";
                }
                else{
                    file << " - " << (-1 * ptr->getBase()) << "x^" << ptr->getExp();
                }
            }
        }
        std::cout << "printBase: " << ptr->getBase() << "\n" << "printExp: " << ptr->getExp();
        base = ptr->getBase();
        exp = ptr->getExp();
        powe = (base * pow(x,exp));
        addtoSum(powe);
        std::cout << "\tAdding to sum" << (ptr->getBase() * pow(x,ptr->exp));
        print(ptr->next,x,file);
    }
    else{
        if(ptr == head){
            if(ptr->getBase() >= 0){
                if(ptr->getExp() == 0){
                    file << " " << ptr->getBase();
                }
                else if(ptr->getExp() == 1){
                    file << " " << ptr->getBase() << "x";
                }
                else{
                    file << " " << ptr->getBase() << "x^" << ptr->getExp();
                }
            }
            else{
                if(ptr->getExp() == 0){
                    file << " -" << (-1 * ptr->getBase());
                }
                else if(ptr->getExp() == 1){
                    file << " -" << (-1 * ptr->getBase()) << "x";
                }
                else{
                    file << " -" << (-1 * ptr->getBase()) << "x^" << ptr->getExp();
                }
            }
        }
        else{
            if(ptr->getBase() >= 0){
                if(ptr->getExp() == 0){
                    file << " + " << ptr->getBase();
                }
                else if(ptr->getExp() == 1){
                    file << " + " << ptr->getBase() << "x";
                }
                else{
                    file << " + " << ptr->getBase() << "x^" << ptr->getExp();
                }
            }
            else{
                if(ptr->getExp() == 0){
                    file << " - " << (-1 * ptr->getBase());
                }
                else if(ptr->getExp() == 1){
                    file << " - " << (-1 * ptr->getBase()) << "x";
                }
                else{
                    file << " - " << (-1 * ptr->getBase()) << "x^" << ptr->getExp();
                }
            }
        }
        base = ptr->getBase();
        exp = ptr->getExp();
        powe = base * pow(x,exp);
        addtoSum(powe);
        std::cout << "\tAdding to sum" << (ptr->getBase() * pow(x,ptr->exp));
        file << std::fixed << std::setprecision(3) << " = " << getsum();
        std::cout << "print2Base: " << ptr->getBase() << "\n" << "print2Exp: " << ptr->getExp();
    }
}

void LinkedList::SortD(Node*&head){
    Node * prev;
    Node*cur;
    Node*after;
    bool swapped;

    cur = head;
    swapped = true;
    //Continues while values have been swapped
    while(swapped){
        swapped = false;
        cur = head;
        prev = nullptr;
        //loops until end of list
        while(cur->next != nullptr){
            after = cur->next;
            //If values are out of order they are swapped
            if(cur->exp < cur->next->exp){
                if(prev == nullptr){
                    head = after;
                    cur->next = after->next;
                    after->next = cur;
                }
                else{
                prev->next = cur->next;
                cur->next = after->next;
                after->next = cur;
                }
                swapped = true;

            }
            prev = cur;
            cur = after;
        }
    }
}


void LinkedList::deleteM(Node*h){
    Node*hold;
    if(h->next == nullptr){
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
    deleteM(head);
}
