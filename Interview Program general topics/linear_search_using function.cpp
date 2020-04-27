
#include<iostream>
using namespace std;
void Search(int A[],int n,int key)
{
    for(int i=0; i<n; i++)
    {
        if(key==A[i])
        {
            cout<<"Element found at: "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found "<<endl;
}

int main()
{
    int A[]= {2,4,5,7,10,9,13};
    int n,k;
    cout<<"Enter an Element to be Searched:";
    cin>>k;
    n=sizeof(A)/sizeof(A[0]);
    cout<<"size of n: "<< n<<endl;
    Search(A,n,k);
    return 0;
}
