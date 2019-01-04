// Place your information here

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char> readfile(){ // Used to read the input file and store it in a vector
    vector<char> vectordata;
    char temp;
    ifstream filedata;
    filedata.open("alphainput.txt");
    
    cout << "Original: ";
    
    while(!filedata.eof()){
        filedata >> noskipws >> temp;
        vectordata.push_back(temp);
    }
    vectordata.pop_back();
    for (int i = 0; i < vectordata.size(); ++i){
        cout << vectordata.at(i);
    }
    filedata.close();
    return vectordata;
}

int main() {
    vector <char> data = readfile();
    
    ofstream filedata;
    filedata.open("alphaoutput.txt");
    cout << endl << "New: ";

    for(int i = 0; i < data.size(); ++i){
        if(isalpha(data.at(i))){
            if((data.at(i) > 64) & (data.at(i) < 78)){
                filedata << char (data.at(i) + 13);
                cout << char (data.at(i) + 13);
            }
            if((data.at(i) > 77) & (data.at(i) < 91)){
                filedata << char (data.at(i) - 13);
                cout << char (data.at(i) - 13);
            }
            if((data.at(i) > 96) & (data.at(i) < 110)){
                filedata << char (data.at(i) + 13);
                cout << char (data.at(i) + 13);
            }
            if((data.at(i) > 109) & (data.at(i) < 123)){
                filedata << char (data.at(i) - 13);
                cout << char (data.at(i) - 13);
            }
        }
        else {filedata << data.at(i); cout << char (data.at(i));}
    }
    filedata.close();
  return 0;
}

