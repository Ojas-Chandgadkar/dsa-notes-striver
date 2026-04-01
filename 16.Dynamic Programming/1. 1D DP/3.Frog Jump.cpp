/*
There is a frog on the '1st' step of an 'N' stairs long staircase. 
The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.
If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

Example : 
    Input : 4 and 10 20 30 10
    Output : 20
    Explanation : 
        The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
        Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
        So, the total energy lost is 20 which is the minimum. 
        Hence, the answer is 20.

Constraints:
    1 <= T <= 10
    1 <= N <= 100000.
    1 <= HEIGHTS[i] <= 1000.

*/

// Memoization : ----------------------------------------------------------------------------------------------
#include <bits/stdc++.h> 

int minEnergy(int n, vector<int> &ht, vector<int> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];

    int left;                                                                       // one step
    int right;                                                                      // two step
    
    left = minEnergy(n-1,ht,dp) + abs(ht[n]-ht[n-1]);
    if(n>=2) right = minEnergy(n-2,ht,dp) + abs(ht[n]-ht[n-2]);
    else right = INT_MAX;

    return dp[n] = min(left, right);    

}

int frogJump(int n, vector<int> &heights)
{
    n = n-1;
    vector<int> dp(n+1, -1);

    return minEnergy(n, heights, dp);
}

// Tabulation : ----------------------------------------------------------------------------------------------
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);

    dp[0] = 0;

    for(int i=1; i<n; i++){
        int oneStep; 
        int twoStep;

        oneStep = dp[i-1] + abs(heights[i-1]-heights[i]);
        if(i>=2) twoStep = dp[i-2] + abs(heights[i-2]-heights[i]);
        else twoStep = INT_MAX;

        dp[i] = min(oneStep, twoStep);
    }

    return dp[n-1];
}

// Tabulation (Space optimized) : ----------------------------------------------------------------------------------------------
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int prev2 = 0;
    int prev1 = (n>=2) ? abs(heights[0]-heights[1]) : -1;

    if(n==1) return prev2;
    else if(n==2) return prev1;

    int res = 0;
    for(int i=2; i<n; i++){
        res = min(prev1+abs(heights[i-1]-heights[i]), prev2+abs(heights[i-2]-heights[i]));
        prev2 = prev1;
        prev1 = res;
    }

    return res;
}