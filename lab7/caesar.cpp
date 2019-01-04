// Place your information here

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<char> readfile(){ // Used to read the input file and store it in a vector
    vector<char> vectordata;
    char temp;
    ifstream filedata;
    filedata.open("caesarinput.txt");
    
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

int numshifter(){
    string key;
    int num;
    int sum = 0;
    
    cout << endl << "Key: ";
    getline(cin, key);
    
    for (int i = 0; i < key.size(); ++i){
        sum += key.at(i);
    }
    
    num = (sum%23)+3;
    
    return num;
}

vector <char> writefile(vector <char> data, int shiftnum){
    vector <char> encrypted_data(data.size());
    ofstream filedata;
    filedata.open("caesaroutput.txt");
    cout << "New: ";

    for(int i = 0; i < data.size(); ++i){
        if(isalpha(data.at(i))){
            if(islower(data.at(i))){
                if((data.at(i) + shiftnum) > 122){
                    filedata << char (data.at(i) + shiftnum - 26);
                    encrypted_data.push_back(data.at(i) + shiftnum - 26);
                    cout << char (data.at(i) + shiftnum - 26);
                }
                else{
                    filedata << char (data.at(i) + shiftnum);
                    encrypted_data.push_back(data.at(i) + shiftnum);
                    cout << char (data.at(i) + shiftnum);
                }
            }
            else{
                if((data.at(i) + shiftnum) > 90){
                    filedata << char (data.at(i) + shiftnum - 26);
                    encrypted_data.push_back(data.at(i) + shiftnum - 26);
                    cout << char (data.at(i) + shiftnum - 26);
                }
                else{
                    filedata << char (data.at(i) + shiftnum);
                    encrypted_data.push_back(data.at(i) + shiftnum);
                    cout << char (data.at(i) + shiftnum);
                }
            }
        }
        else {filedata << data.at(i); cout << char (data.at(i)); encrypted_data.push_back(data.at(i));}
    }
    filedata.close();
    return encrypted_data;
}

void decrypt(vector <char> data, int shiftnum){
    ofstream filedata;
    filedata.open("caesar_decypted_output.txt");
    cout << endl << "Decrypted: ";

    for(int i = 0; i < data.size(); ++i){
        if(isalpha(data.at(i))){
            if(islower(data.at(i))){
                if((data.at(i) - shiftnum) < 97){
                    filedata << char (data.at(i) - shiftnum + 26);
                    cout << char (data.at(i) - shiftnum + 26);
                }
                else{
                    filedata << char (data.at(i) - shiftnum);
                    cout << char (data.at(i) - shiftnum);
                }
            }
            else{
                if((data.at(i) + shiftnum) > 65){
                    filedata << char (data.at(i) - shiftnum + 26);
                    cout << char (data.at(i) - shiftnum + 26);
                }
                else{
                    filedata << char (data.at(i) - shiftnum);
                    cout << char (data.at(i) - shiftnum);
                }
            }
        }
        else {
            filedata << data.at(i);
            cout << char (data.at(i));
        }
    }
    filedata.close();
}

int main() {
    
    vector <char> data = readfile();
    int shiftnum = numshifter();
    vector <char> encrypted_data = writefile(data, shiftnum);
    decrypt(encrypted_data, shiftnum);
    
  return 0;
}

