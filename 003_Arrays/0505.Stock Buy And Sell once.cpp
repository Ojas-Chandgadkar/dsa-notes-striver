#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){

    int N = prices.size();

    int maxProfit = 0;
    int minElement = INT_MAX;
    for(int i=0; i<N; i++){
        minElement = min(prices[i], minElement);
        maxProfit = max(maxProfit, prices[i]-minElement);
    } 

    return maxProfit;
}


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Intialize 'maxProft=0' and 'minElement=INT_MAX'
//`For every element check if update on : minElement, maxProfit
// Return maxProfit at end.