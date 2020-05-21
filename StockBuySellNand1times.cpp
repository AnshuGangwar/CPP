#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//peak valley approach unlimited buy sell
int maxProfit(vector<int> prices) {

        int n = prices.size();
        int diff = 0;
        for(int i=1;i<n;++i)
        {
            if(prices[i] > prices[i-1])
                diff += prices[i]-prices[i-1];
        }
        return diff;
    }

//buy and sell one time only
int maxProfitOneTime(vector<int> prices){
    int maxprofit=0;
    int min = INT_MAX;
    for(int i =0;i<prices.size();i++)
    {
        if(prices[i]<min){min=prices[i];}
        else if((prices[i]-min)>maxprofit){maxprofit=prices[i]-min;}
    }
    return maxprofit;
}

int main(){
    vector<int> prices {7,3,22,4,1,18};
cout<<maxProfit(prices)<<endl;
cout<<maxProfitOneTime(prices)<<endl;
}
