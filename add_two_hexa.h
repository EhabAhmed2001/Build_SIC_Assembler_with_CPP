#include <bits/stdc++.h>

using namespace std;

int hexToDec(string str)
{
    int y;
    stringstream stream;
    stream << str;
    stream >> hex >> y;
    return y;
}

string decToHex(int num)
{
    stringstream stream;
    stream << hex << num;
    return stream.str();
}

string addTwoHex(string str, string adder)
{
    //Adding hex and hex
        int num1 = hexToDec(str);
        int num2 = hexToDec(adder);
        int sum = num1 + num2;
        return decToHex(sum);

}
