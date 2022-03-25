// Vectors are similar to Dynamic arrays, its just that Vectors are included in c++ library

#include<iostream>
#include<vector>
using namespace std;

int main()
{ 
    // Statically creating a vector :
    vector<int> v; // Vector is a type of template whose type needs to be specified

    // Dynamically creating a vector :
    vector<int> *vp = new vector<int>();

    // To insert an element in the vector we use push_back() function :
    v.push_back(10); // Inserts element in first position
    v.push_back(20); // Inserts element behind the first element and so on..
    v.push_back(30);
    
    // We can treat the vectors like arrays :
    v[3] = 40; // Inserting values like arrays (Not Recommended)

    cout << v[0] << endl; // Output -> 10
    cout << v[1] << endl; // Output -> 20
    cout << v[2] << endl; // Output -> 30
    cout << v[3] << endl; // Output -> 40

    /*
    Note: We will use [] of arrays in vectors only to get the value at the index or to update
    a value in vector, we will NOT use [] to insert new elements, we will only use push_back()
    function.
    */

   cout << "Size of vector: " << v.size() << endl; // size() function returns size of vector
   // The above function returns size as 3 in place of 4 because we do not insert the element
   // at position 3 using push_back() function.

    cout << v.at(2) << endl; // at() function gets the value at the specified index
    cout << v.at(3) << endl; // It is safer to use as it throws error if index is out of bound
    return 0;
}