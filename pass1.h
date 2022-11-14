#include <bits/stdc++.h>
#include "add_two_hexa.h"
using namespace std;

string pass1(string line, ofstream &addressFile,string address) {
    string word, label,instruction,reserve ;
    int no = 0;
    string noInHex ;
    int count = 0;
    stringstream str1(line);
    while(str1 >> word)
    {
        if(word[0]=='%')
            break;
        count ++;
    }

    stringstream str(line);
    if(count == 3)
    {
        str>> label;
        str>> instruction;

        if (instruction =="RESW")
        {
            str >> reserve;
            no = 3 * stoi (reserve);
        }
        else if (instruction =="RESB")
        {
            str >> reserve;
            no = 1 * stoi (reserve);
        }
        else if (instruction =="BYTE")
        {
            str >> reserve;
            if(reserve[0]=='X')
            {
                no = (reserve.size()-3)/2;
            }
            else
            {
                no = reserve.size()-3;
            }

        }
        else
        {
            no = 3;
        }

        for(int i=0; i< address.size(); i++)
            address[i]=toupper(address[i]);

        addressFile<<label <<"\t"<<address<<endl;
    }

    else
    {
        str>> instruction;
        if(instruction != "END")
        {
            no = 3;
        }
    }

    noInHex = decToHex(no);
    address = addTwoHex(address, noInHex);

    return address;
}

