
// 
// Name:
//


#include <iostream>
#include <cmath>

using namespace std;

// We have setup class framework for you. Please copy the point 
// class you created to this file.

class Point {
    public:

    friend istream& operator>>(istream &input, Point &p ) {
	// Finish me second by adding proper input >> statement
	
	input >> p.x;
	input.ignore(1);
	input >> p.y;
	
	return input;
    }

    friend ostream& operator<<(ostream &output, const Point &p ) {
	// Finish me thrid by adding proper output << statement
	
	output << p.x;
	output << ", ";
	output << p.y;
	
	return output;
    }

    // Please add constructors and other functions here.
    Point();
    Point(int, int);
    
    void SetPoint(int, int);
    int GetX();
    int GetY();

    private:
	int x; int y;

};

Point::Point(){
  x = 0;
  y = 0;
}

void Point::SetPoint(int x1, int y1){
  x = x1;
  y = y1;
}
    
int Point::GetX(){
  return x;
}

int Point::GetY(){
  return y;
}

class Line {
    public:
    
    friend istream& operator>>(istream &input, Line &l ) {
	    int temp1; int temp2; int temp3; int temp4;

	    input >> temp1;
	    input >> temp2;
	    input >> temp3;
	    input >> temp4;
	    
	    l.SetLine(temp1, temp2, temp3, temp4);
	    
	    return input;
    }

    friend ostream& operator<<(ostream &output, const Line &l ) {
	
	    output << l.P1;
	    output << ", ";
	    output << l.P2;
	
	    return output;
    }
    
    Line();
    Line(int, int);
    
    
    void SetLine(int, int, int, int);
    double GetSlope();
    double GetLength();
    double GetY_Intercept();
    bool is_Horizontal();
    bool is_Vertical();
    bool is_Parallel(Line L2);
    bool has_Intercept(Line L2);
    
    private:
    Point P1;
    Point P2;
};

Line::Line(){
  P1.SetPoint(0, 0);
  P2.SetPoint(0, 0);
}

void Line::SetLine(int x1, int y1, int x2, int y2){
  P1.SetPoint(x1, y1);
  P2.SetPoint(x2, y2);
}

double Line::GetSlope(){
  int x1 = P1.GetX();
  int x2 = P2.GetX();
  int y1 = P1.GetY();
  int y2 = P2.GetY();
  
  return static_cast<double>(y2-y1)/static_cast<double>(x2-x1);
}

double Line::GetLength(){
  int x1 = P1.GetX();
  int x2 = P2.GetX();
  int y1 = P1.GetY();
  int y2 = P2.GetY();
  
  int xlength = (x2-x1);
  int ylength = (y2-y1);
  
  return static_cast<double> (pow((xlength*xlength)+(ylength*ylength), 0.5));
}

double Line::GetY_Intercept(){
  double m = GetSlope();
  int x = P2.GetX();
  int y = P2.GetY();
  
  return (y-(m*x));
}

bool Line::is_Horizontal(){
  if(GetSlope() == 0){
    return true;
  }
  return false;
}

bool Line::is_Vertical(){
  if((P1.GetX() - P2.GetX()) == 0){
    return true;
  }
  return false;
}

bool Line::is_Parallel(Line L2){
  if(GetSlope() == L2.GetSlope()){
    return true;
  }
  return false;
}

bool Line::has_Intercept(Line L2){
  double m1 = GetSlope();
  double m2 = L2.GetSlope();
  double b1 = GetY_Intercept();
  double b2 = L2.GetY_Intercept();
  double x = (b2-b1)/(m1-m2);
  
  if ((x<P1.GetX()) && (x>P2.GetX())){
    if ((x<L2.P1.GetX()) && (x>L2.P2.GetX())){
    return true;
    }
    if ((x<L2.P2.GetX()) && (x>L2.P1.GetX())){
    return true;
    }
  }
  if ((x<P2.GetX()) && (x>P1.GetX())){
    if ((x<L2.P1.GetX()) && (x>L2.P2.GetX())){
    return true;
    }
    if ((x<L2.P2.GetX()) && (x>L2.P1.GetX())){
    return true;
    }
  }
  
  return false;
}


int main() {
  Line L1;
  Line L2;
  
  cout << "Sample Input: 0 1 2 3" << endl << endl;
  
  cout << "Enter Line 1 (Please enter it as x1 y1 x2 y2):  "; //Sample input would look like 0 1 2 3
  cin >> L1;
  cout << "Enter Line 2 (Please enter it as x1 y1 x2 y2):  ";
  cin >> L2;
  
  cout << endl;
  
  cout << "Line 1: ";
  cout << L1 << endl;
  cout << "Line 2: ";
  cout << L2 << endl << endl;
  
  cout << "Slope of Line 1: " << L1.GetSlope() << endl;
  cout << "Slope of Line 2: " << L2.GetSlope() << endl << endl;
  
  cout << "Length of Line 1: " << L1.GetLength() << endl;
  cout << "Length of Line 2: " << L2.GetLength() << endl << endl;
  
  cout << "Y Intercept of Line 1: " << L1.GetY_Intercept() << endl;
  cout << "Y Intercept of Line 2: " << L2.GetY_Intercept() << endl << endl;
  
  cout << "Is Line 1 Horizontal?  (1 for Yes, 0 for No):  " << L1.is_Horizontal() << endl;
  cout << "Is Line 2 Horizontal?  (1 for Yes, 0 for No):  " << L2.is_Horizontal() << endl << endl;
  
  cout << "Is Line 1 Vertical?    (1 for Yes, 0 for No):  " << L1.is_Vertical() << endl;
  cout << "Is Line 2 Vertical?    (1 for Yes, 0 for No):  " << L2.is_Vertical() << endl << endl;
  
  cout << "Are The Lines Parallel?  (1 for Yes, 0 for No):  " << L1.is_Parallel(L2) << endl;
  cout << "Do The Lines Intercept?  (1 for Yes, 0 for No):  " << L1.has_Intercept(L2) << endl << endl;
  
  return 0;
}
