
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

string convertToUpper(const string &to_be_converted){
  int lng = to_be_converted.size();
  string to_be_converted2 = to_be_converted;
  
  for (int i =0; i < lng; ++i){
    if (islower(to_be_converted[i])){
      to_be_converted2[i] = toupper(to_be_converted[i]);
    }
  }
  return to_be_converted2;
}

vector <int> characterCounts(const string &countme){
  int lng = countme.size();
  string countme2 = convertToUpper(countme);
  vector <int> answer(26);
  
  for (int j = 0; j < 26; ++j){
    int count = 0;
    
    for (int i = 0; i < lng; i++){
      if (countme2[i] == 'A'+j) count++;
    }
    answer.at(j) = count;
  }
  
  return answer;
}

int main(){
  //string blah = "abcd";
  vector <int> abcd = characterCounts("The quick brown fox jumps over the lazy dog");
  
  for (int i = 0; i < abcd.size(); ++i){
    cout << abcd.at(i) << ' ';
  }
}