// Kadane's Algo
long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxSum = 0;

    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];

        if(sum > maxSum){
            maxSum = sum;
        }

        if(sum < 0 ) sum = 0;
    }

    return maxSum;
}


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Intialize 'maxSum=0' and 'sum=0' 
// Iterate over the array, and keep on incrementing the sum
// if(sum > maxSum), update maxSum
// if(sum < 0), set sum=0 
// Return maxSum at the end.
// (Kadane's Algorithm)