#include<iostream>
#include <string.h>

using namespace std;
//void Reversestring(string& str[])
void Reversestring(char str[]){
   //int n = str.length();
   int n = strlen(str);
    for(int i=0;i<n/2;i++)
       swap(str[i],str[n-i-1]);


}
int main(){
char str[] ="anshu";
   //string str = "mynameisanshu";
    Reversestring(str);
    cout<<str;
}

