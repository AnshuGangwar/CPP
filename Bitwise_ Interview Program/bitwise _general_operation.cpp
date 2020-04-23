#include <iostream>

using namespace std;
//Iterative  time O(log n),Space-O(1)
/*void decToBinArray(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0)
    {// storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
// printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}*/
bool checkeven(int n){
    return (!(n&1));
}
//Detect if two integers have opposite signs
bool oppositesign(int x,int y)
{
    return (!((x^y)>>31));
}
unsigned int CountsetBits(unsigned int n)
{
    int count =0;
    while(n)
    {
        n=n&n-1;
        count++;
    }

    return count;

}
//recursive time O(log n),Space-O(log n)
void DectoBin(unsigned int n)
{

    if(n>1)
        DectoBin(n/2);
    cout<<" "<<n%2;

}
//setting a Bit
int setBit(int num,int pos )
{
    return num|(1u<<pos);
}

int clearBit(int num,int pos )
{
    return num&(~(1u<<pos));
}

int ToggleBit(int num,int pos )
{
    return num^(1u<<pos);
}

bool GetBitStatus(int num,int pos)
{
    return num & (1<<pos);
}

bool isPowerOfTwo (int num )
{
    return num && (!(num&(num-1))); //in case of 0, otherwise  (num&(num-1) will work
}

int findPosofOnlySetBit(unsigned n)
{
    if (!isPowerOfTwo(n))
        return -1;  //no has more than on set position
    unsigned count = 0;
    // One by one move the only set bit to right till it reaches end
    while (n)
    {
        n = n >> 1;
        // increment count of shifts
        ++count;
    }
    return count;
}
//2 nibble in a byte
int swapNibbles(int x)
{
    return ( (x & 0x0F) << 4 | (x & 0xF0) >> 4 );
}


int main()
{
    unsigned int count;
    int n;
    cin>>n;
    cout<<"binary representation  of no."<<endl;
    DectoBin(n);
    cout<<endl<< "after swap nibble "<<swapNibbles(n);
    n=swapNibbles(n);
    cout<<endl<<"binary representation after swapping nibble  of no."<<endl;
    DectoBin(n);
    //decToBinArray(n);
    count=CountsetBits(n);
    cout<<endl<<"count of  set bits:"<<count<<endl;

    int pos;
    cout << "enter the position you want to set  :" << endl;
    cin>>pos;
    n= setBit(n, pos);
    cout <<endl<< "after setting bit :"<<n << endl;

    cout<<"binary representation  of no."<<endl;
    DectoBin(n);

    n=clearBit(n,pos );
    cout << endl<<"after clearing bit :"<<n<< endl;
    cout<<"binary representation  of no."<<endl;
    DectoBin(n);

    n=ToggleBit(n,pos );
    cout << endl<<"after toggling the particular bit :"<<n<< endl;
    cout<<"binary representation  of no."<<endl;
    DectoBin(n);

    int bit ;
    cout<<endl<<"enter the position of bit you want status"<<endl;
    cin>>pos;
    bit = GetBitStatus(n, pos);
    cout << bit << endl;

    cout<<endl<<" Enter the no to check if it's power of two"<<endl;
    int num;
    cin>>num;
    isPowerOfTwo(num)? cout<<"Yes\n": cout<<"No\n";
    cout<<"binary representation  of no."<<endl;
    DectoBin(num);

    count =findPosofOnlySetBit(num);
    cout<<endl<<"position of  only set bit from lsb:"<<count;

    int n,x,y;
    cout<<"enter the no you want to check:"<<endl;
    cin>>n;
    checkeven(n)?cout<<"even":cout<<"odd"<<endl;

    cout<<endl<<"enter two no. to check sign"<<endl;
    cin>>x>>y;

    oppositesign(x,y)?cout<<"yes":cout<<"no";



    return 0;
}
