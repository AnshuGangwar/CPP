#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int A[]= {1,23,344,5,6,7};
    int key,n = 6 ;
    cout << "Enter the key value" << endl;
    cin >> key;
    for(int i=0; i< n; i++)
    {
        if (key==A[i])
        {
            cout << "key matched " << endl;
            exit(0);
        }
    }
    cout << "key not  matched " << endl;
    return 0;
}
