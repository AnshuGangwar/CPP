#include<iostream>
using namespace std;
//Power without using multiplication(*) and division(/) operators

int  multiply(int x, int y){

           if(x)
               return (x+multiply(x,y-1));
           else
               return 1;

}
int power(int a,int b)
{
    if(b)
        return multiply(a,power(a,b-1));
    else
        return 1;

}

int main(){
int x=power(1,1);
cout<<"power of the no. is :"<<x;
return 0;
}
