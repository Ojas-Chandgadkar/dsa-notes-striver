class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int N = nums.size();

        int low = 0;
        int mid = 0;
        int high = N-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Initialize 'low=0', 'mid=0' and 'high=N-1'.
// While mid<=high we run a loop, swapping elements
// The in-place sort takes place using these index pointers, in such a way that : 
// 0 to low --> sorted 0
// low to mid --> sorted 1
// mid to high --> unsorted 0,1,2
// high to N --> sorted 2
// (This problem is a variation of the popular Dutch National flag algorithm)