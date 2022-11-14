#include <bits/stdc++.h>
#include "opcode.h"
#include "get_first_address.h"
#include "pass1.h"
#include "pass2.h"


// ==========================================================================================
// ==========================================================================================
// ========== DON'T FORGET TO CHANGE FILES PATH ACCORDING TO YOUR FILES IN YOUR PC ==========
// ==========================================================================================
// ==========================================================================================

using namespace std;

const string inputPath = """E:/Lectures/3rd level/system programming/Sic assembler with CPP/IandO/Input.txt""";
const string addressPath = """E:/Lectures/3rd level/system programming/Sic assembler with CPP/IandO/address.txt""";
const string resultPath = """E:/Lectures/3rd level/system programming/Sic assembler with CPP/IandO/result.txt""";
map<string, string> labelAndAddress;
map<string, string>::iterator it;

int main() {
    string address;
    ifstream inputFile(inputPath);      // input file

    ofstream addressFile;   //  address file
    addressFile.open(addressPath, ios::out);

    ofstream resultFile;    //result file
    resultFile.open(resultPath, ios::out);

    string line;

    // get first address
    while(getline(inputFile, line))
        if (line[0] != '%')
        {
            address = getStartingAddress(line, addressFile);
            break;
        }

    // PASS 1
    while (getline(inputFile, line)) {
        if (line[0] != '%')
            address = pass1(line, addressFile, address);
    }
    addressFile.close();
    inputFile.close();

    // ======= read from address file to add label and address in map
    ifstream readFromAddFile(addressPath);
    int c = 0;
    while (getline(readFromAddFile, line)) {
        c = 0;
        string word, label, address;
        stringstream str(line);
        while (str >> word) {
            //     cout << word << "    ";
            c++;
            if (c == 1)
                label = word;
            else if (c == 2)
                address = word;
        }
        //   cout << endl;
        labelAndAddress.insert({label, address});
    }

    //  PASS2
    ifstream inFile(inputPath);      // input file
    while (getline(inFile, line)) {
        pass2(labelAndAddress, resultFile, line);
    }

    resultFile.close();
    ifstream printResultFile(resultPath);      // PRINT RESULT FILE
    while (getline(printResultFile, line)) {
        cout << line << endl;
    }



//  TO CHECK MAP ITEM
//      for(it = labelAndAddress.begin();it!=labelAndAddress.end();it++)
//          cout<<(*it).first<<"\t"<<(*it).second<<endl;


    inFile.close();
    readFromAddFile.close();
    resultFile.close();

    return 0;
}
