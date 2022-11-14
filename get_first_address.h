#include <bits/stdc++.h>

using namespace std;


string getStartingAddress(string line, ofstream &addressFile) {
    string label, address="";
    stringstream str(line);

    str >> label;
    str >> address;
    str >> address;
//    char c;
//    for (int i = 0  ;   ; i++) {
//        c = line[i];
//        if (c != '\t')
//            label += c;
//        else
//            break;
//    }
//    reverse(line.begin(), line.end());
//    for (int i = 3; i >= 0; i--) {
//        address += line[i];
//    }

    for(int i=0; i< address.size(); i++)
        address[i]=toupper(address[i]);

    addressFile << label << "\t" << address << endl;

    return address;

}