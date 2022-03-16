#include <iostream>
using namespace std;
int partition(int arr[], int start, int end)
{
    int less_count = 0;
    int key = arr[start];

    for (int i = start+1; i <= end; i++)
    {
        if (arr[i] <= key)
            less_count++;
    }

    int pivot_index = start+less_count;
    int temp = arr[pivot_index];
    arr[pivot_index] = arr[start];
    arr[start] = temp;
    int i = start, j = end;
    while (i <= pivot_index && j >= pivot_index)
    {
        while(arr[i]<=key)
		{
			i++;
		}
		while(arr[j]>key)
		{
			j--;
		}
		if(i<pivot_index && j>pivot_index)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
    }
    return pivot_index;
}
void quickSort(int input[], int start, int end)
{
    if (start >= end)
        return;
    int p_index = partition(input, start, end);
    quickSort(input, start, p_index - 1);
    quickSort(input, p_index + 1, end);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}