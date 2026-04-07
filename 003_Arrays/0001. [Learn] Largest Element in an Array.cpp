#include<bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {

    // Write your code here.
    int max = arr[0];
    
    int i = 1;
    while(i<n){
        if(arr[i] > max){
            max = arr[i];
        }
        i++;
    }

    return max;
}


// ------------------------------My Solution ------------------------------
// Time -> O(n)
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Consider,  int max = arr[0], compare max with all the remaining 1 to size-1 elements.
// And update 'max' value if(arr[i] > max).
// At the end return 'max' value.
