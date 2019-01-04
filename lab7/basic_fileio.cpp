// Todd Herron
// Lab 7 Part A

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <istream>
#include <cmath>




vector <int> readfile(){ // Used to read the input file and store it in a vector
    vector <int> vectordata;
    int temp;
    ifstream filedata;
    filedata.open("input.txt");

    while(!filedata.eof()){
        filedata >> temp;
        vectordata.push_back(temp);
    }
    filedata.close();
    cout << "Numbers read in: " << vectordata.size() << endl;
    return vectordata;
}

bool isEven(int num){ // Calculates if number is even and returns ture or false
    if (num % 2 == 0){return true;}
    else{return false;}
}

bool isPrime(int num){ // Calculates if number is prime and returns true or false
    if (num <= 1)  return false;
    if (num <= 3)  return true;

    if (num%2 == 0 || num%3 == 0) return false;

    for (int i=5; i*i<=num; i=i+6)
        if (num%i == 0 || num%(i+2) == 0)
           return false;

    return true;

}

int min(vector <int> data) { // Returns the minimum of a vector
   int minimum = data.at(0);
   for (int i = 1; i < data.size(); ++i){
       if (data.at(i) < minimum){
           minimum = data.at(i);
       }
   }
   return minimum;
}

int max(vector <int> data) { // Returns the maximum of a vector
   int maximum = data.at(0);
   for (int i = 1; i < data.size(); ++i){
       if (data.at(i) > maximum){
           maximum = data.at(i);
       }
   }
   return maximum;
}

int sum(vector <int> data){ // Returns the sum of a vector
    int sum = 0;
    for (int i = 0; i < data.size(); ++i){
        sum += data.at(i);
    }
    return sum;
}

double mean(vector <int> data){ // Returns the mean of a type int vector
    int sum = 0;
    double lng = data.size();
    for (int i = 0; i < data.size(); ++i){
        sum += data.at(i);
    }
    return (sum / lng);
}

double mean_double(vector <double> data){ // Returns the mean of a type double vector
    int sum = 0;
    double lng = data.size();
    for (int i = 0; i < data.size(); ++i){
        sum += data.at(i);
    }
    return (sum / lng);
}

double stddev(vector <int> data){ // Returns the standard deviation of a vector
    double mean1 = mean(data);
    vector <double> data2(data.size());
    for(int i = 0; i < data.size(); ++i){
        data2.at(i) = (pow(abs(static_cast<double>(data.at(i)) - mean1), 2));
    }
    double mean2 = abs(mean_double(data2));
    return pow(mean2, 0.5);
}

int main() {
    vector <int> data = readfile();
    int count = 0; int temp;
    
    ofstream evens; evens.open("evens.txt");
    ofstream odds; odds.open("odds.txt");
    
    for (int i = 0; i < data.size(); ++i){ // stores the even and odd numbers
        temp = isEven(data.at(i));
        
        if (temp == 1){
            count += temp;
            evens << data.at(i)<< endl;
        }
        else{
            odds << data.at(i)<< endl;
        }
    }
    
    evens.close(); odds.close();
    
    temp = 0;
    int primenum = 0;
    
    for (int i = 0; i< data.size(); ++i){ // calculates number of prime numbers
        temp = isPrime(data.at(i));
        if(temp == 1){
            primenum += temp;
        }
    }
    
    int minimum = min(data);
    int maximum = max(data);
    int Sum = sum(data);
    double Mean = mean(data);
    double standdev = stddev(data);
    
    cout << "Even Numbers: " << count << endl;
    cout << "Odd Numbers: " << data.size() - count << endl;
    cout << "Prime Numbers: " << primenum << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Sum: " << Sum << endl;
    cout << "Mean: " << Mean << endl;
    cout << "Standard Deviation: " << standdev << endl;
    
    return 0;
}
