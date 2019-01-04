

/*
Name: <Todd Herron>
Date: <2/19/2018>
Assignment: <Lab 5>
Description: <fill me in>
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


bool find(int array[], int length, int value){
  for (int i = 0; i < length; i++) {
    if (array[i] == value){
      return true;
    }
  }
  return false;
}

bool isSorted(int array[], int length){
  for (int i = 1; i < length; ++i) {
    if (array[i-1] > array[i]) {
      return false;
    }
  }
  return true;
}
/*
void reverse(vector <int> &reverse_me) {
  int lng;
  lng = reverse_me.size();
  int temp;
  
  for (int i = 0; i < (lng/2); ++i){
    temp = reverse_me.at(i);
    reverse_me.at(i) = reverse_me.at(lng - 1 - i);
    reverse_me.at(lng - 1 - i) = temp;
  }
}

float mean(const vector <float> values) {
  float lng = values.size();
  if (lng == 0){
    return 0;
  }
  float sum = 0;
  for (int i = 0; i < lng; ++i) {
    sum = sum + values.at(i);
  }
  return (sum/lng);
}

float stddev(const vector <float> values) {
  vector <float> variance = values;
  int lng;
  lng = values.size();
  float mn = mean(values);
  for (int i = 0; i < lng; ++i){
    variance.at(i) = variance.at(i) - mn;
    variance.at(i) = variance.at(i) * variance.at(i);
  }
  mn = mean(variance);
  return pow(mn, 0.5);
}

vector<int> removeDups(vector<int> array){
  int lng = array.size();
  vector<int> newvec = array;
  int temp;
  
  for (int i = 0; i < lng; ++i){
    temp = array.at(i);
    for (int j = i+1; 0 < lng; ++i){
      if(temp == array.at(j)){
        newvec.erase(i);
      }
    }
  }
  return newvec;

  // This is just to keep the compiler happy
  return vector<int>();
}

// Strings 
unsigned int countUpperCaseChars(const string &countme){
  int count = 0;
  int lng = countme.size();
  for (int i = 0; i < lng; ++i){
    if (isupper(countme[i])){
      count++;
    }
  }
}

unsigned int numWords(const string &countme){
  int lng = countme.size();
  int count = 0;
  for (int i = 0; i < lng; ++i){
    if (isspace(countme[i])){
      count = count + 1;
    }
  }
  return count+1;
}

string convertToUpper(const string &to_be_converted){
  int lng = to_be_converted.size();
  
  for (int i =0; i < lng; ++i){
    if (islower(to_be_converted[i])){
      to_be_converted[i] = toupper(to_be_converted[i]);
    }
  }
}

string removeSpaces(const string &remove_from_me){
  int lng = remove_from_me.size();
  
  if (isblank(remove_from_me[0])){
    return remove_from_me;
  }
  
  for (int i = 0; i < lng; ++i){
    if (isspace(remove_from_me[i])){
      remove_from_me.erase(i);
    }
  }
}

vector <int> characterCounts(const string &countme){
  return countme;
  
}
*/
template<typename T>
string print(vector<T> vec);

template<typename T>
string print(T array[], int lng);


int main(){
  srand(time(0));   

  cout << "find:" << endl;
  int x1[10] = {1,2,3,5,5,6,7,8,9,0};
 
  cout << "false/0 = " << find(x1, 10, 4) << endl;
  cout << "false/0 = " << find(x1, 10, 99) << endl;
  cout << "true/1 = " << find(x1, 10, 5) << endl;
  cout << "true/1 = " << find(x1, 10, 0) << endl;
  cout << "true/1 = " << find(x1, 10, 1) << endl;
  cout << "true/1 = " << find(x1, 10, 6) << endl;
  cout << endl;
  cout << endl;
  /*
  cout << "reverse:" << endl;
  vector <int> v1 = {1,2,3,4,5};
  reverse(v1);
  cout << "[5,4,3,2,1] = " << print(v1) << endl;
  reverse(v1);
  cout << "[1,2,3,4,5] = " << print(v1) << endl;
  vector <int> v2 = {5};
  cout << "[5] = " << print(v2) << endl;
  vector <int> v3 = {1,2,4,5};
  reverse(v3);
  cout << "[5,4,2,1] = " << print(v3) << endl;
  vector <int> v4(100);
  v4[0]  = 4;
  v4[1]  = 2;
  reverse(v4);
  cout << "0 = " << v4[0] << endl;
  cout << "2 = " << v4[98] << endl;
  cout << "4 = " << v4[99] << endl;
  
  cout << endl << "mean:" << endl;
  vector <float> f1 = {1.2, 2.4, 3.4};
  vector <float> f2 = {5.6, 5.6, 5.6, 5.6, 5.6, 5.6};
  cout << "2.33 = " << mean(f1) << endl;
  cout << "5.6 = " << mean(f2) << endl;
  
  cout << endl << "stddev:" << endl;
  cout << "0.899 = " << stddev(f1) << endl;
  cout << "0 = " << stddev(f2) << endl;
  
  cout << endl << "removedups:" << endl;
  vector<int> v5;
  v5.push_back(1);
  v5.push_back(2);
  v5.push_back(3);
  v5.push_back(3);
  v5.push_back(4);
  v5.push_back(5);
  v5.push_back(1);
  vector<int> v12 = removeDups(v5);
  cout << "[1,2,3,4,5] = " << print(v12) << endl;
  cout << "5 = " << v12.size() << endl;
  vector<int> v6;
  for(int i = 0; i < 100; i++){
    v6.push_back(i%17 + i %7);
  }
  vector<int> v22 = removeDups(v6);
  cout << "22 = " << v22.size() << endl;

  cout << "\nString Functions: " << endl;
  string upper_test = "aaABCdeFG"; 
  cout << "countUpperCase" << endl;
  cout << "5 = " << countUpperCaseChars(upper_test) << endl;
  cout << "5 = " << countUpperCaseChars("AAAAA") << endl;
  cout << "0 = " << countUpperCaseChars("aaaaa") << endl;
  string no_upper_case = "aaaa";
  cout << "0 = " << countUpperCaseChars(no_upper_case) << endl;

  cout << "RemoveSpaces:" << endl;
  string test1 = "aa AB Cd e FG"; 
  string test2 = "aaAB Cd e FG "; 
  string test3 = " rrAB Cd e FG"; 
  string test4 = " rrAB Cd e FG "; 
 
  cout << "aaABCdeFG = " << removeSpaces(test1) << endl;
  cout << "aaABCdeFG = " << removeSpaces(test2) << endl;
  cout << "rrABCdeFG = " << removeSpaces(test3) << endl;
  cout << "rrABCdeFG = " << removeSpaces(test4) << endl;
*/
  return 0;
}

// A sneaky way to allow 1 function to print any typed array, as long as
// the passed array element can be sent to <<.
// The stringstream allows us to 'print' information to a fake output
// stream, and then get the result as a string.  It's a simple way of
// getting a non-string/character into a string.
// Contense of this function will not be tested in this course!

template<typename T>
string print(vector<T> vect) {
  stringstream out;
  out << '[';
  for(int i = 0; i < vect.size(); i++){
    out << vect[i];
    if(i != vect.size()-1)out << ',';
  }
  out << ']';
  return out.str();
}


template<typename T>
string print(T array[], int length){
  stringstream out;
  out << '[';
  for(int i = 0; i < length; i++){
    out << array[i];
    if(i != length-1)out << ',';
  }
  out << ']';
  return out.str();
}


