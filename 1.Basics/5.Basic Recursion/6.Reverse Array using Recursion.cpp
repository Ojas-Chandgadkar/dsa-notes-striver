/*
Given an array 'arr' of size 'n'.
Return an array with all the elements placed in reverse order.
*/

void reverse_nums(int i, int j, vector<int> &nums){
    if(i>=j) return;

    nums[i] = nums[i] + nums[j];
    nums[j] = nums[i] - nums[j];
    nums[i] = nums[i] - nums[j];

    reverse_nums(i+1, j-1, nums);
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    reverse_nums(0, n-1, nums);
    return nums;
}
