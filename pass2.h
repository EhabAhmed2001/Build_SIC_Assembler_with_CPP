#include <bits/stdc++.h>
using namespace std;

void pass2(map<string, string> labelAndAddress, ofstream &resultFile, string line) {

    string word, label, instruction, operand,opcode;
    int count = 0;
    stringstream str(line);
    while (str >> word) {
        if (word[0] == '%')
            break;
        count++;
    }

    stringstream str1(line);
    if (count == 3) {

        str1 >> label;
        str1 >> instruction;
        str1 >> operand;
    }
    else if (count == 2)
    {
        str1 >> instruction;
        str1 >> operand;
    }
    else
    {
        str1 >> instruction;
        operand = "0000";
    }

    if(count ==3 || count ==2)
    {
        int index = operand.find(",X");
        if(index != -1)
        {
            string pureOperand = "";
            for(int i = 0; i < index ; i++)
                pureOperand+=operand[i];
            opcode = getOpcode(instruction) + labelAndAddress[pureOperand];
            opcode = addTwoHex(opcode,"8000");
        }
        else
            opcode = getOpcode(instruction) + labelAndAddress[operand];

    }
    else
        opcode = getOpcode(instruction) + "0000";


    if(instruction != "END")
        resultFile<< line << "\t\t\t" << opcode <<endl;
    else
        resultFile<< line <<endl;

}