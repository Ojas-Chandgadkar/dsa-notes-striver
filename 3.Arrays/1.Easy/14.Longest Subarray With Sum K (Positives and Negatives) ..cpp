#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){

    int N = nums.size();
    map<long long, int> preSumMap;        

    int maxLength = 0;
    int sum = 0;
    for(int i=0; i<N; i++){
        sum += nums[i];
        
        if(sum == k){
            maxLength = max(maxLength, i+1);
        }

        int diff = sum - k;
        if(preSumMap.find(diff) != preSumMap.end()){
            maxLength = max(maxLength, i-preSumMap[diff]);
        }

        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }

    return maxLength;
}

// ------------------------------My Solution ------------------------------
// Time ->  O(n)
// Space -> O(n)
// ------------------------------ Approach ------------------------------
// Intialize a hashmap 'preSumMap', which will store <prefixSum, index>
// Intialize 'maxLength=0' and 'sum=0'
// Now traverse through the array
//      Calulate running sum 
//      if(sum==k), calculate maxLength
//      if(sum-k in preSumMap), calulate maxLength
//      if(sum !in preSumMap, add sum and index.
// Return maxLength at the end.
// (Prefix Sum)
// -------------------------------------------------------------------------



// Total Subarrays with sum K : 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int res = 0;
    vector<int> arr = {3,4,7,2,-3,1,4,2};
    int n = arr.size();
    int t = 7;

    unordered_map<int, int> mp;                 // {sum, count}
    int prefixSum = 0;
    for(int i=0; i<n; i++){
        prefixSum += arr[i];
        (mp.find(prefixSum)==mp.end()) ? mp[prefixSum]=1 : mp[prefixSum]++;

        if(arr[i]==t){
            res++;
        }
        int diff = prefixSum - t;
        if(mp.find(diff)!=mp.end()){
            res += mp[diff];
        }
        
        
    }
    cout << res;
    
    return 0;
}