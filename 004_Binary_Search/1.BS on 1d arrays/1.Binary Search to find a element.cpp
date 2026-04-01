int search(vector<int> &nums, int target) {
    
    int N = nums.size();

    int low = 0;
    int high = N-1;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            low = mid+1;
        }
        else if(nums[mid] > target){
            high = mid-1;
        }
    }
    
    return -1;
}


// ------------------------------My Solution ------------------------------
// Time -> O(logn) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Intialize 'low=0' and 'high=N-1' to keep track of the indexes.
// While low <= high, infitailize mid = (low+high)/2, note that this can cause overflow if numbers are large. 
//      Return 'mid' if target found.
//      else search if right or left size based on conditon.
// Return '-1' at end if target is not found.