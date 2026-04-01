class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int N = nums.size();

        int breakIndex = -1;
        for(int i=N-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                breakIndex = i;
                break;
            }
        }

        if(breakIndex == -1){
            reverse(nums.begin(), nums.end());
            return;
        }   

        for(int i=N-1; i>breakIndex; i--){
            if(nums[i] > nums[breakIndex]){
                swap(nums[i], nums[breakIndex]);
                break;
            }
        }

        reverse(nums.begin() + breakIndex+1, nums.end());
    }
};


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Initialize 'N', which is the size of the vector.
// Intialize 'breakIndex=-1', this is for finding index where the ascending chain breaks starting from end.
// Reverse iterate the vector from N-2 to 0; checking if this chain breaks.
// If all elements are arranged in asending order from last, that means the number is the largest possbile permutation.
//      The next permumtation for such a number is the reverse array, which gives smallest permutation
//      Return the vector.
// If there exists a breakIndex, 
//      Reverse Iterate vector from N-1 to breakIndex+1
//      While traversing find the first index such that : nums[i] > nums[breakIndex]
//      Swap them, and break the loop
// Reverse the vector from 'breakIndex+1' to 'N'
// Finally return the vector.