#include <bits/stdc++.h>

using namespace std;
string getOpcode(string str)
{
    map<string,string> opcode;
    opcode["ADD"] = "18";
    opcode["AND"] = "40";
    opcode["COMP"] = "28";
    opcode["DIV"] = "24";
    opcode["J"] = "3C";
    opcode["JEQ"] = "30";
    opcode["JGT"] = "34";
    opcode["JLT"] = "38";
    opcode["JSUB"] = "48";
    opcode["LDA"] = "00";
    opcode["LDCH"] = "50";
    opcode["LDL"] = "08";
    opcode["LDX"] = "04";
    opcode["MUL"] = "20";
    opcode["OR"] = "44";
    opcode["RD"] = "D8";
    opcode["RSUB"] = "4C";
    opcode["STA"] = "0C";
    opcode["STCH"] = "54";
    opcode["STL"] = "14";
    opcode["STX"] = "10";
    opcode["SUB"] = "1C";
    opcode["TD"] = "E0";
    opcode["TIX"] = "2C";
    opcode["WD"] = "DC";


    if(opcode.find(str) == opcode.end())
        return "\t";

    return opcode[str];
}