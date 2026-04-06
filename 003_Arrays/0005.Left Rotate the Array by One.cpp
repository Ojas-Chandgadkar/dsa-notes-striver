#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    
    int temp = arr[0]; 
    for(int i=0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;

    return arr;
}


// ------------------------------My Solution ------------------------------
// Time ->  O(n) with single pass
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Store the first element in 'temp'
// For i=0 to n-1,  'arr[i] = arr[i+1]'
// arr[n-1] = temp 
// At the very end return the shifted   arr

