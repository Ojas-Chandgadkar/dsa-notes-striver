
// Given a binary array nums and an integer k, 
// return the maximum number of consecutive 1's in the array 
// if you can flip at most k 0's.

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int maxOnes = 0;
        int n = nums.size();

        int i = 0;
        int j = 0;
        int zerosFlipped = 0;
        while(j<n){
            if(nums[j] == 1){
                j++;
            }
            else if(nums[j]==0 && zerosFlipped<k){
                j++;
                zerosFlipped++;
            }
            else if(nums[j]==0 && zerosFlipped==k){
                while(nums[i]!=0 && i<n){
                    i++;
                }
                i++;
                zerosFlipped--;
            }

            maxOnes = max(maxOnes, j-i);
        }

        return maxOnes;
        
    }
};