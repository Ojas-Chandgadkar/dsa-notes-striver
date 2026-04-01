#include <limits.h>
#include <stdio.h>

bool heapChecker(int nums[], int i, int n)
{
    // Base case
    if (i >= (n - 1) / 2)
        return true;

    if (nums[i] >= nums[2 * i + 1] && nums[i] >= nums[2 * i + 2] &&
        heapChecker(nums, 2 * i + 1, n) && heapChecker(nums, 2 * i + 2, n))
        return true;

    return false;
}

int main()
{
    int nums[] = {80, 13, 9, 5, 11, 1};
    int n = sizeof(nums) / sizeof(int) - 1;
    if (heapChecker(nums, 0, n)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
    return 0;
}
