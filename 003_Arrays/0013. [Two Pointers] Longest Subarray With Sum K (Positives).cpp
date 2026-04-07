int longestSubarrayWithSumK(vector<int> a, long long k) {

    int N = a.size();
    int maxLen = 0;

    int i = 0;
    int j = 0;
    long long sum = 0;
    while(j < N){
        sum += a[j];
        while(i<=j && sum>k){
            sum -= a[i];
            i++;
        }
        if(sum == k){
            maxLen = max(maxLen, j-i+1);
        }

        j++;
    }

    return maxLen;
}


// ------------------------------My Solution ------------------------------
// Time ->  O(n)
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Intialize two pointers : 'i=0' for back, 'j=0' for front, 'maxLen=0' and 'sum=0'.
// Using i and j, we have to make a dynamic window, that grows from j and shrink from i.
// Using 'sum' we calculate the running sum of the elements of the window.
// Return maxLen at the end
// (Sliding Window)