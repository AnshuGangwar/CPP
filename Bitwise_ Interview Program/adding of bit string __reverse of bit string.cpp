#include <iostream>
#include<stdio.h>
using namespace std;

/*Make them equal sized by adding 0s at the beginning of smaller string.
Sum = a XOR b XOR c
Carry = (a AND b) OR ( b AND c ) OR ( c AND a )
*/

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}



// The main function that adds two-bit sequences and returns the addition
string addBitStrings( string first, string second )
{
    string result;  // To store the sum bits

    // make the lengths same before adding
    int length = makeEqualLength(first, second);

    int carry = 0;  // Initialize carry

    // Add all bits one by one
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';

        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';

        result = (char)sum + result;

        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    // if overflow, then add a leading 1
    if (carry)
        result = '1' + result;

    return result;
}

unsigned int reverseBits(unsigned int num)
{
   // unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;

     for (int i = 0; i <= 8; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((8 - 1) - i);
    }
    return reverse_num;
}
void DectoBin(unsigned int n)
{

    if(n>1)
        DectoBin(n/2);
    cout<<" "<<n%2;

}


// Driver program to test above functions
int main()
{
    string str1 = "1100011";
    string str2 = "10";

    cout << "Sum is " << addBitStrings(str1, str2)<<endl;

    unsigned int x =1;
    cout<<"binary representation  of no."<<endl;
    DectoBin(x);
   int  reverse_num=reverseBits(x);
    cout <<endl<< "reverse of bit of no. is  " <<reverseBits(x);
    cout<<endl<<"binary representation  of rev no."<<endl;
    DectoBin(reverse_num);
    return 0;
}
