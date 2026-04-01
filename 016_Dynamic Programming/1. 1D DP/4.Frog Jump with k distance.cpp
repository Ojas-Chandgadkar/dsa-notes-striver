/*
There is an array of heights corresponding to 'n' stones. You have to reach from stone 1 to stone ‘n’.
From stone 'i', it is possible to reach stones 'i'+1, ‘i’+2… ‘i’+'k' , and the cost incurred will be | Height[i]-Height[j] |, where 'j' is the landing stone.
Return the minimum possible total cost incurred in reaching the stone ‘n’.

Example:
    For 'n' = 3 , 'k' = 1, height = {2, 5, 2}.
    Answer is 6.

Constraints:
    1 <= n <= 10^4
    1 <= k <= 100
    1 <= height[i] <= 10^4
    Time Limit: 1 sec
*/

// Plain recursion : ======================================================================================================================
int minCost(int n, int &k, vector<int> &height){
    
    if(n==0) return 0;

    int lowest = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n-i>=0) lowest = min(lowest, minCost(n-i,k,height) + abs(height[n-i]-height[n]));
        else break;
    }
    
    return lowest;
}

int minimizeCost(int n, int k, vector<int> &height){
    
    return minCost(n-1, k, height);
}


// Memoization : ======================================================================================================================
int minCost(int n, int &k, vector<int> &height, vector<int> &dp){
    
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];

    int lowest = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n-i>=0) lowest = min(lowest, minCost(n-i,k,height, dp) + abs(height[n-i]-height[n]));
        else break;
    }
    
    return dp[n] = lowest;
}

int minimizeCost(int n, int k, vector<int> &height){
    
    vector<int> dp(n, -1);
    return minCost(n-1, k, height, dp);
}


// Tabulation : ======================================================================================================================
int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(i+j>=n) break;
            dp[i+j] = min(dp[i+j], dp[i]+abs(height[i]-height[i+j]));
        }
    }

    return dp[n-1];
}