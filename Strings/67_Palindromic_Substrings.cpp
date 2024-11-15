#include<iostream>
#include<string>
using namespace std;

bool palindromeString(string str)
{
    int n=str.length();
    for(int i=0;i<n/2;i++)
    {
        if(str[i]!=str[n-i-1])
        {
            return false;
        }
    }
    return true;
}

int findPalindromicSubstrings(string str)
{
    int n=str.length();
    string subStr;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            string subStr=str.substr(i,j-i+1);
            if(palindromeString(subStr))
            {
                cout<<subStr<<endl;
            }
        }
    }
    return 0;
}

int main()
{
    string str="nitin";
    findPalindromicSubstrings(str);
    return 0;
}