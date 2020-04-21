
#include<iostream>
using namespace std;

// A utility function to count set bits  in a number x
unsigned int countSetBitsUtil(unsigned int x)
{
    if (x <= 0)
        return 0;
    return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
}

// Returns count of set bits present in all numbers from 1 to n
unsigned int countSetBits(unsigned int n)
{
    int bitCount = 0; // initialize the result

    for (int i = 1; i <= n; i++)
        bitCount += countSetBitsUtil(i);

    return bitCount;
}

int main()
{
    int n = 4;
    cout<<"Total set bit count is:"<<countSetBits(n);
    return 0;
}
