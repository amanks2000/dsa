#include<iostream>
using namespace std;

// Syntax to create a generic variable Template
template <typename T> 

class Pair 
{
    T x;
    T y;

    public :

    void setX (T x) {
        this -> x = x;
    }

    void setY (T y) {
        this -> y = y;
    }

    T getX () {
        return x;
    }

    T getY () {
        return y;
    }
};

int main()
{
    Pair<int> p1; // syntax to use the generic class variables as int
    p1.setX(10);
    p1.setY(100);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2; // syntax to use the generic class variables as double
    p2.setX(1.2);
    p2.setY(.23);
    cout << p2.getX() << " " << p2.getY() << endl;
    return 0;
}