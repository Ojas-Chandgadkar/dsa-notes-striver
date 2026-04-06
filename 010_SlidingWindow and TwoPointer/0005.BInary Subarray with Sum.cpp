// Optimized 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int res = 0;
        int size = nums.size();
        unordered_map<int,int> preSumMap;

        preSumMap[0] = 1;

        int preSum = 0;
        for(int i=0; i<size; i++){
            preSum += nums[i];

            if(preSumMap[preSum-goal]){
                res += preSumMap[preSum-goal];
            }
            
            preSumMap[preSum]++;
        }


        return res;
    }
};

// Otimal : 
class Solution {
public:

    int atMost(vector<int> &nums, int k){
        
        int result   = 0;

        int size = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        while(j<size){
            sum += nums[j];
            
            while(sum>k && i<=j){
                sum -= nums[i];
                i++;
            }
            if(sum <= k){
                result += j-i+1;
            }
            j++;
        }

        return result;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};


// This problem can be solved by 3 methods generally.

// 1. Brute-Force -> Using nested loop -> T.C = O(n^2) ; S.C = O(1)
// 2. Optimised -> Using hash map -> T.C = O(n) ; S.C = O(n)
// 2. Optimal -> Using sliding window -> T.C = O(n) ; S.C =O(1)
