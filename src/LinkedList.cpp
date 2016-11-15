#include "LinkedList.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <iostream>

LinkedList::LinkedList()
{
    headset = false;
}

void LinkedList::Insert(Node*n){

        //Checks if there is a head to the linked list
		if(!headset){
            head->setBase(n->getBase());
            head->setExp(n->getExp());
            headset = true;
            return;
		}
		//Goes to the end of the list and adds the node
		Node*cur = head;
        while(cur->next)
			cur = cur->next;
        n->next = nullptr;
		cur->next = n;
}

float LinkedList::exponent(float base,float e){
    if(e == 0){
        return 1;
    }
    if(e == 1){
        return base;
    }
    return base * exponent(base,e-1);
}


float LinkedList::print(Node*ptr,float x,std::ofstream &file){
    long double base;
    int exp;
    double powe;
    if(ptr->next){
        //Checks if it's at head to remove the +
        if(ptr == head){
            //If base is positive use a +
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
            //If base is positive and not the head
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
        //calculates term and adds it to sum
        base = ptr->getBase();
        exp = ptr->getExp();
        powe = (base * exponent(x,exp));
        addtoSum(powe);
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
        file << std::fixed << std::setprecision(3) << " = " << getsum();
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
