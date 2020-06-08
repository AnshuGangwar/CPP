
#include<map>
#include <bits/stdc++.h>
using namespace std;
//find group of anagram
void groupAnagrams(vector<string>& strs)
{
    map<string, vector<string>> Map;
    vector<vector<string>> ans;
    for (auto it : strs)
    {
        string temp = it;
        sort(begin(temp), end(temp));
        Map[temp].push_back(it);
    }
//pushing values of map[original anagrams] to vector
    for (auto it : Map)
    {
        ans.push_back(it.second);
    }
//for print
    for(auto it: ans)
    {   cout<<"[";
        for(auto it1: it)
        {
            cout<<it1<<" ";
        }
        cout<<"]"<<endl;
    }
}

//remove anagram
void RemoveAnagrams(vector<string>& strs)
{
    set<string> anagrams;
    for (auto it : strs)
    {
        string temp = it;
        sort(begin(temp), end(temp));
        anagrams.insert(temp);
    }

    cout<<"After removing anagram: ";
    for(auto it: strs)
    {
        string temp = it;
        sort(begin(temp), end(temp));
        if(anagrams.find(temp) != anagrams.end())
        {
            cout<<it<<endl;
            anagrams.erase(temp);
        }
    }
}
// find frequeny of anagram and print  word with no anagram
void FrequencyAnagram(vector<string>& strs)
{
    map<string, int> anagrams;
    for (auto it : strs)
    {
        string temp = it;
        sort(begin(temp), end(temp));
        anagrams[temp]++;
    }

    for (auto it : anagrams)
    {
        cout<<it.first<< " : "<<it.second<<endl;
    }

    cout<<"Unique words: "<<endl;

    for(auto it: strs)
    {
        string temp = it;
        sort(begin(temp), end(temp));
        if(anagrams[temp] == 1)//print unique word with 1 frequency
        {
            cout<<it<<endl;
        }
    }

}

int main()
{
    vector<string> strs = {"abc", "abc", "bca", "dog","god", "car"};
    groupAnagrams(strs);
     cout<<"**************\n";
    RemoveAnagrams(strs);
     cout<<"************** \n";
    FrequencyAnagram(strs);

    return 0;

}



