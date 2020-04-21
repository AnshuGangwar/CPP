#include <iostream>
#include<stdio.h>
using namespace std;
//#define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
void memory_represent(char *value, int n)
{
    for (int i = 0; i < n; i++)
        printf("%x", value[i]);
    // cout<<value[i];
}
unsigned int LitToBigEndian(unsigned int x)
{
    return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}


//2 nibble in a byte
int swapNibbles(int x)
{
    return ( (x & 0x0F) << 4 | (x & 0xF0) >> 4 );
}
//check if machine is little Endian or Big Endian
void checkEndian()
{
    uint32_t i=1;//0x0001--->1 store at lowest memory address in case of Little Endian
    char* c =(char*)&i;//type cast to char pointer bcz it point to 1 byte and & operation gives the value of msb
    if(*c)
        cout<<"little endian"<<endl;
    else
        cout<< "big endian"<<endl;
}
int main()
{
    unsigned int x = 0x9876543210;
    checkEndian();

    cout << "The little endian value is: ";
    memory_represent((char*)&x, sizeof(x));

    int y = LitToBigEndian(x);
    cout <<endl<< "The Big endian value after conversion is: ";
    memory_represent((char*)&y, sizeof(y));
return 0;
}
