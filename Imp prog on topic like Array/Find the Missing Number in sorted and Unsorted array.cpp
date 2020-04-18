#include <iostream>
using namespace std;

// Function to get the missing number  in Unsorted array Normal approach - O(N)
int getMissingNo(int a[], int n)
{

    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}
// Function to get the missing number in Unsorted array Bitwise Xor approach - O(N)
int getMissingNoXor(int a[], int n)
{
    // For xor of all the elements in array
    int x1 = a[0];

    // For xor of all the elements from 1 to n+1
    int x2 = 1;

    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];

    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;

    return (x1 ^ x2);
}
//Function to get the missing number by Binary search approach - O(log N)

int SortedSearch(int arr[], int size)
{
    int a = 0, b = size - 1;
    int mid;
    while ((b - a) > 1) {
        mid = (a + b) / 2;
        if ((arr[a] - a) != (arr[mid] - mid))
            b = mid;
        else if ((arr[b] - b) != (arr[mid] - mid))
            a = mid;
    }
    return (arr[mid] + 1);
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing number in Unsorted array:" <<getMissingNo(arr, n)<<endl;
    cout << "Missing number in Unsorted array:" <<getMissingNoXor(arr, n)<<endl;
    cout << "Missing number in sorted array:" <<SortedSearch(arr, n)<<endl;
}
