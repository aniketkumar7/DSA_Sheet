#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int LongestSubstring(string s){
    unordered_map<char, int> mp;
    int maxLength = 0;
    int start = 0; // starting index of the current window

    // sliding window
    for(int i=0; i < s.length(); i++){
        // Check if character is already in the string
        if(mp.find(s[i]) != mp.end()){
            // move the start to the right
            start = mp[s[i]] + 1;
        }
        // update the last index
        mp[s[i]] = i;
        // update the max length
        maxLength = max(maxLength, i - start + 1);
    }
    return maxLength;
}

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Length of the longest substring: " << endl;
    cout << LongestSubstring(s) << endl;
    return 0;
}