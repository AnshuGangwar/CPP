#include<iostream>
#include<math.h>
using namespace std;

//Power without using multiplication(*) and division(/) operators

int  multiply(int x, int y){

           if(y)
               return (x+multiply(x,y-1));
           else
               return 0;

}
int power(int a,int b)
{

    if(b)
        return multiply(a,power(a,b-1));
    else
        return 1;

}

int main(){
sint x=power(5,2);
//int x=pow(58,13);
cout<<"power of the no. is :"<<x;
return 0;
}
