#include<iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n==0)
    {
        if(k==0){
            output[0][0] = 0;
            return 1;
        }
        else 
            return 0;
    }
    int smallOutput1 = subsetSumToK(input+1,n-1,output,k);
    int smallOutput2 = subsetSumToK(input+1,n-1,output+smallOutput1,k-input[0]);
    int smallOutput = smallOutput1 + smallOutput2;
    for(int i=smallOutput1; i<smallOutput; i++){
        for(int j=output[i][0];j>0;j--){
            output[i][j+1]=output[i][j];
        }
        output[i][1] = input[0];
        output[i][0]++;
    }
    return smallOutput;
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}