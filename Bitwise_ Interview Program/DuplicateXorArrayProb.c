//Type-1
//Given: An array A with all elements occuring twice except for x that occur once.
//To Do: Find the element x O(1) space and O(N) time
//point - XOR of a no with itself gives 0.
#include <iostream>
using namespace std;
void  OneElement(int arr[], int n)
{
    int all = 0;
    for(int i=0; i<n; i++)
    {
        all ^= arr[i];
    }

    cout << "One element ans : " << all << endl;

}
//Type -2
//Given: An array A with all elements occuring twice except for x and y that occur once.
//To Do: Find the x and y in O(1) space and O(N) time



bool hasBitSet(int all, int x) {
	int tem = all & (1<<x);
	return tem!=0;
}

void TwoElement(int arr[], int n){
    int all = 0;
	int ans[2] = {0,0};

	for(int i=0; i<n; i++){
		all ^= arr[i];
	}

	//assert(all != 0);
	int k = 0;
	/*while( hasBitSet(all, k) == 0 ){
            cout<<"k : " <<k<<endl;
            k++;
	}*/

	//partition array into two sets: kth bit on v/s off
	for (int i=0; i<n; i++) {
		ans[hasBitSet(arr[i], k)] ^= arr[i];
	}

	cout << "Two element ans : " <<ans[0] << " " << ans[1] << endl;

}

int main()
{
    //const int N = 1e6;
    //int arr[N];
    int arr[] = {4,1,2,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    //OneElement(arr, n);
    TwoElement(arr, n);
    return 0;
}




