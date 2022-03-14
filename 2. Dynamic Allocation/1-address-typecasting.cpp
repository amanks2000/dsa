#include<iostream>
using namespace std;

int main()
{
    int i = 65;
    char ch = i; // implicit typecasting
    cout << ch << endl;

    int *p = &i;
    /* char *pc = p; --> Here character pointer is made to point at an integer directly
                         This throws an error as this is not valid */

    char *pc = (char*)p; // explicit typecasting
                         // here pc points at the first byte of the integer pointer p
                         // since character is only 1 byte and integer is 4 bytes
    cout << *p << endl;
    cout << *pc << endl; // the first byte of the integer stores the value and thus
                         // pc points to the integer part given to the variable
                         // This is basically due to system following Little Endian System    cout << *(pc+1) << endl;
    cout << *(pc+2) << endl;
    cout << *(pc+3) << endl;

    cout << p << endl; // output: address --> int pointer
    cout << pc << endl;// output: all character till null --> character pointer
    
    return 0;
}