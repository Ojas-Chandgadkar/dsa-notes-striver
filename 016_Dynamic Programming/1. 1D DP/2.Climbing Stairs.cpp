/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?

Example 1:
    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
Example 2:
    Input: n = 3
    Output: 3

Constraints:
    1 <= n <= 45
*/



// Plain Recursion : ----------------------------------------------------------
class Solution {
public:

    void helper(int i, int &noOfWays){
        if(i == 0) noOfWays++;
        if(i<=0) return;

        helper(i-1, noOfWays);
        helper(i-2, noOfWays);
    }   
    int climbStairs(int n) {
        
        int noOfWays = 0;

        helper(n, noOfWays);
        return noOfWays;
    }
};


// Memoization (Recursion) : ----------------------------------------------------------
class Solution {
public:

    int noOfWays(int n, vector<int> &dp){
        if(n==1 || n==2) return n;
        
        if(dp[n]!=-1) return dp[n]; 
        return noOfWays(n-1, dp) + noOfWays(n-2, dp);

    }
    int climbStairs(int n) {

        vector<int> dp(n+1, -1);
        return noOfWays(n, dp);
    }
};


// Tabulation (Iterative) : ----------------------------------------------------------
class Solution {
public:

    int climbStairs(int n) {
        
        if(n==1) return 1;
        
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;                                                     
        
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};


// Tabulation (using less space): ----------------------------------------------------------
class Solution {
public:
    int climbStairs(int n) {
        int prev1=1,prev2=2;
        int ans=0;
        if(n<=3) return n;
        for(int i=3;i<=n;i++)
        {
            ans=prev1+prev2;
            prev1=prev2;
            prev2=ans;
        } 
        return ans;
    }
};
