// OPTIMIZED
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int res = 0;
        int size = nums.size();

        int preSum = 0;
        unordered_map<int, int> preSumMap;
        preSumMap[0] = 1;
        
        for(int i=0; i<size; i++){
            (nums[i]%2==0) ? nums[i] = 0 : nums[i] = 1;
            preSum += nums[i];
            
            if(preSumMap[preSum-k]){
                res += preSumMap[preSum-k];
            }

            preSumMap[preSum]++;
        }

        return res;
    }
};


// OPTIMAL
class Solution {
public:

    int atMost(vector<int> &nums, int k){

        int res = 0;
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

            if(sum <= k) res += j-i+1;
            j++;
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }

        return atMost(nums, k) - atMost(nums, k-1);
    }
};