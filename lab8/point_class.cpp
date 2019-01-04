
// 
// Name: Todd Herron
//


#include <iostream>

using namespace std;

// We have setup class framework for you.
// Please add cin/cout overload first and at the same time add the coordinates
//
// See github example as specified in the assignment handout for examples
//

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

int main() {
  Point P1;
  
  cout << "Enter P1: ";
  cin >> P1;

  cout << "P1: ";
  cout << P1;
  cout << endl;
  
  return 0;
}
