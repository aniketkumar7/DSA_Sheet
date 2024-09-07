// QUESTION: MAGNETIC FORCE BETWEEN TWO BALLS
// QUESTION LINK : https://leetcode.com/problems/magnetic-force-between-two-balls/

// PROBLEM STATEMENT:
// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.


// EXAMPLE:
// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.


// Algorithm:
// Step 1: Sort the array
// Step 2: Binary Search
// Step 3: Find the maximum magnetic force between any two balls
// Step 4: Return the maximum magnetic force

// SOLUTION:

#include <bits/stdc++.h>
using namespace std;

// Approach :
bool isPossible(vector<int> &position, int m, int mid){
    int balls = 1;
    int lastPosition = position[0];
    for(int i=1; i<position.size(); i++){
        if(position[i] - lastPosition >= mid){
            balls++;
            lastPosition = position[i];
        }
    }
    return balls >= m;
}


int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int n = position.size();
    int low = 1, high = position[n-1] - position[0];
    int ans = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        if(isPossible(position, m, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


int main(){

    vector<int> position = {1,2,3,4,7};
    int m = 3;
    int ans = maxDistance(position, m);
    cout << "The maximum magnetic force between any two balls is: " << ans << endl;

    return 0;
}



