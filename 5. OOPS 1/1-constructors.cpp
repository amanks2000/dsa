#include<iostream>
using namespace std;

class Student {
    int roll,age;
    public : 
    Student (int x,int y) // constructor
    {
        roll = x;
        age = y;
    }
    ~Student () // destructor
    {
        cout << "Destructor Called" << endl;
    }
    void display ()
    {
        cout << "Roll : " << roll << "\nAge : " << age << endl;
    }
};

int main()
{
    cout << "Constructor" << endl;
    Student s1(101,20);
    s1.display();

    cout << "\nCopy Constructor" << endl;
    Student s2(s1); // Copy Constructor: gives all the properties of object s1 to object s2
    s2.display();
    return 0;
}