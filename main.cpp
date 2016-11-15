//Edward Bates emb160030 section 002
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <Node.h>
#include <LinkedList.h>


using namespace std;

int main()
{
    //Opens input and output file
    string infileName = "poly.txt";
    ifstream infile(infileName);
    string outfileName = "answers.txt";
    ofstream outfile (outfileName);
    Node*head = new Node(0,0,nullptr);
    Node*old = head;

    //Loops through each line
    while(infile.good()){
        char line[256];
        char*linePtr = line;
        infile.getline(line,256);
        //extracts the x value
        long double Fof = atof(line + 2);
        linePtr = strstr(line,"=") + 1;

        string stringK;
        stringK = linePtr;

        //adds end of string char
        stringK += 'N';
        //Checks for sign
        int sign = 1;
        if(stringK[1] == '-'){
            sign = -1;
            stringK = stringK.substr(2);
        }


        int nextsign = sign;
        LinkedList llist;

        //Looks for terms by finding + or -
        while(stringK.length() > 1){
            bool liketerm = false;
            sign = nextsign;
            string term1 = "";
            int exp = 0;
            int i = 0;
            while(stringK[i] != '+' && stringK[i] != '-' && stringK[i] != 'N'){
                i++;
            }

            term1 = stringK.substr(0,i);
            if(stringK[i] == '-'){
                nextsign = -1;
            }
            else{
                nextsign = 1;
            }
            stringK = stringK.substr(i+1);
            long double fl = 0;
            //extracts base
            fl = atof(term1.c_str());
            //Looks for edge cases such as constants
            if(!term1.find('x')){

                //break;
            }
            //If there is no number before the x
            if(term1[1] == 'x'){
                fl = 1;
            }
            term1 += 'N';
            i = 0;
            while(term1[i] != 'x' && term1[i] != 'N'){
                i++;
            }
            if(term1[i+1] != '^'){
                //exponent 1
                if(term1[i] == 'x'){
                    exp = 1;
                }
                else{
                    exp = 0;
                }
            }
            else{
                string xp = term1.substr(i+2);
                //extracts exponent
                exp = atoi(xp.c_str());
            }
            Node*cur = llist.getHead();
            //Looks for like terms
            //Checks first term in linked list
            if(llist.getHead()->getExp() == exp){
                    llist.getHead()->setBase((sign * fl ) + llist.getHead()->base);
                    liketerm = true;
                }
            while(cur->next){
                if(cur->getExp() == exp){
                    cur->setBase((sign * fl ) + cur->base);
                    liketerm = true;
                    break;
                }
                cur = cur->next;
            }
            if(!liketerm && (fl != 0 || exp != 0)){
                Node*tmp;
                //Creates a new node and inserts it
                old = new Node(sign * fl,exp,tmp);
                llist.Insert(old);
                old = tmp;
        }

        }
        //Prints the linked list
        outfile << "f(" << Fof << ") =";
        llist.SortD(llist.head);
        llist.print(llist.getHead(),Fof,outfile);
        outfile << '\n';
    }
    return 0;
}
