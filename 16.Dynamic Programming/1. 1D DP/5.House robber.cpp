/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is 
that adjacent houses have security systems connected and it will automatically contact the police if 
two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.

Example 2:
    Input: nums = [2,7,9,3,1]
    Output: 12
    Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
    Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 400

*/


// Plain recursion : ======================================================================================================================
class Solution {
public:
    int maxRob(int i, vector<int> &nums){
        if(i==0) return nums[0];
        else if(i<0) return 0;

        int pick = nums[i] + maxRob(i-2, nums);
        int notPick = 0 + maxRob(i-1, nums);

        return max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return maxRob(n-1, nums);
    }
};


// Memoization : ======================================================================================================================
class Solution {
public:
    int maxRob(int i, vector<int> &nums, vector<int> &dp){
        if(i==0) return nums[0];
        else if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i];

        int pick = nums[i] + maxRob(i-2, nums, dp);
        int notPick = 0 + maxRob(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return maxRob(n-1, nums, dp);
    }
};


// Tabulation : ======================================================================================================================
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n);

        dp[0] = nums[0];

        for(int i=1; i<n; i++){
            int pick = (i>1) ? nums[i]+dp[i-2] : nums[i];
            int notPick = dp[i-1];

            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    }
};

// Tabulation (Space optimization) : ======================================================================================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        int prev = nums[0];   
        int prev2 = 0;
    
        for (int i = 1; i < n; i++) {
            int pick = (i>1)? nums[i]+prev2 : nums[i];
            int nonPick = 0 + prev;  
            
            int cur_i = max(pick, nonPick); 
            prev2 = prev;  
            prev = cur_i; 
        }
    
    return prev;  

    }
};