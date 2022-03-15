/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. 
The objective of the puzzle is to move all disks from source rod to destination rod 
using third rod (say auxiliary).
Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.
*/
#include<iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n==0)
        return;
    else if(n==1)
    {
        // if n = 1 move the disc directly from source to destination
        cout << source << " " << destination << endl; 
        return;
    }
    // firstly we move n-1 disc from source to auxillery pole using destination pole
    towerOfHanoi(n-1,source,destination,auxiliary);

    // then we move the remainig 1 (largest) disc from source to destination directly
    cout << source << " " << destination << endl;

    // then finally we move the n-1 discs from auxillery to destination using the source pole
    towerOfHanoi(n-1,auxiliary,source,destination);
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}