/*
You are given an array 'A' of 'N' integers. 
You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. 
Otherwise, return false.

For Example
    'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
    Subset [2, 3] has sum equal to 'K'.
    So our answer is True.
*/

// Time  : O(2^N)
// Space : O(N)
// where N is 
bool helper(vector<int> &a, int i, int N, int target) {
    if (target == 0) {
        return true;
    }
    if (i == N || target < 0) {
        return false;
    }

    // Check if subset sum is present by including or excluding the current element
    return 
    helper(a, i + 1, N, target - a[i]) 
    || helper(a, i + 1, N, target);
}

bool is_present(vector<int> &a, int N, int target) {
    return helper(a, 0, N, target);
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    return is_present(a, n, k);
}
