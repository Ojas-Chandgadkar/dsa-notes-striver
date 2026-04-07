int isSorted(int n, vector<int> a) {
    
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1])
            return 0;
    }
    
    return 1;
}


// ------------------------------My Solution ------------------------------
// Time ->  O(n) with single pass
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Compare 'i' and 'i+1' elements of the vector array.
// In any case if(a[i]>a[i+1]), return 0;
// Otherwise return 1
