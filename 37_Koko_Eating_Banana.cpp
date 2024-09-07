// QUESTION :  Koko Eating Bananas
// QUESTION LINK : https://leetcode.com/problems/koko-eating-bananas/

// PROBLEM STATEMENT :
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.



// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4


// SOLUTION :

#include<bits/stdc++.h>
using namespace std;

// Ye function check karta hai ki Koko sare bananas kha payegi ya nahi
bool canKokoEatAll(vector<int> &piles, int eatingSpeed, int hours)
{
    int timeNeeded = 0;

    for (int &pile : piles)
    {
        // Har pile ke liye, kitna time lagega calculate karo
        timeNeeded += pile / eatingSpeed;
        if (pile % eatingSpeed != 0)
        {
            timeNeeded++;
        }
    }
    // Agar Koko time ke andar kha sakti hai to true, warna false
    return timeNeeded <= hours;
}

int minEatingSpeed(vector<int> &piles, int hours)
{
    // Sabse kam aur sabse zyada speed set karo
    int minSpeed = 1;
    int maxSpeed = *max_element(begin(piles), end(piles));

    // Binary search ka istemal karke optimal speed dhundho
    while (minSpeed < maxSpeed)
    {
        int midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;

        // Agar is speed se Koko kha sakti hai, to speed kam karo
        if (canKokoEatAll(piles, midSpeed, hours))
        {
            maxSpeed = midSpeed;
        }
        // Agar nahi kha sakti, to speed badhao
        else
        {
            minSpeed = midSpeed + 1;
        }
    }
    // Minimum speed jo Koko ko chahiye, woh return karo
    return minSpeed;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    cout << "Input: " << endl;

    for (int &x : piles)
    {
        cout << x << " ";
    }
    cout << endl;

    int h = 8;
    cout << "Hours: " << h << endl;

    cout << "Output: " << endl;
    cout << minEatingSpeed(piles, h);
}