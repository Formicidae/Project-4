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
    string infileName = "poly.txt";
    ifstream infile(infileName);
    string outfileName = "answers.txt";
    ofstream outfile (outfileName);
    Node*head = new Node(0,0,nullptr);
    Node*old = head;

    while(infile.good()){
        char line[256];
        char*linePtr = line;
        infile.getline(line,256);
        float Fof = atof(line + 2);
        //cout << "F : " <<   Fof << endl;
        linePtr = strstr(line,"=") + 1;

        string stringK = " 5.9x^11 + x^3 - 3x^10 + 3";
        stringK = linePtr;

//        getline()

        stringK += 'N';
        int sign = 1;
        if(stringK[1] == '-'){
            sign = -1;
            stringK = stringK.substr(2);
            cout << endl << stringK << endl;
        }


        int nextsign = sign;
        LinkedList llist;
        while(stringK.length() > 1){

            sign = nextsign;
            string term1 = "";
            float exp = 0;
            int i = 0;
            while(stringK[i] != '+' && stringK[i] != '-' && stringK[i] != 'N'){
                i++;
            }
            //cout << stringK << endl;
            //cout << "I: " << i << endl;
            term1 = stringK.substr(0,i);
            if(stringK[i] == '-'){
                nextsign = -1;
            }
            else{
                nextsign = 1;
            }
            stringK = stringK.substr(i+1);
            //cout << "\t\t\tTern ="<< term1 <<  endl;
            float fl = 0;
            fl = atof(term1.c_str());
            //cout << "Float " << fl << endl;
            if(!term1.find('x')){
                //constant

                //break;
            }
            if(term1[1] == 'x'){
                //base is 1
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
                //cout << "xp :" << xp << endl;
                exp = atof(xp.c_str());
            }
            Node*tmp;
            old = new Node(sign * fl,exp,tmp);
            cout << "Ready to insert";
            llist.Insert(old);
             cout << endl << "\nBase is:" << old->getBase() << "\nExp :" << old->getExp() << endl;

            old = tmp;
            cout << endl << "Sign is:" << sign << "\nBase is:" << fl << "\nExp :" << exp << endl;

        }
        cout << "Is head right: " << llist.getHead()->getBase()<< "\n";
        llist.print(llist.getHead(),Fof,outfile);
        //llist.print(outfile);
        outfile << '\n';

    }
    return 0;
}
