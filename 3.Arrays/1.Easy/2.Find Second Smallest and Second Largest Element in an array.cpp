vector<int> getSecondOrderElements(int n, vector<int> a) {

    int max = INT_MIN;
    int secMax = INT_MIN - 100;

    int min = INT_MAX - 100;
    int secMin = INT_MAX;

    vector<int> res(2, -1);
    
    for(int i=0; i<n; i++){
        if(a[i]>max){
            secMax = max;
            max = a[i];
        }
        else if(a[i]>secMax && secMax<max)
            secMax = a[i];
            
        if(a[i]<min){
            secMin = min;
            min = a[i];
        }
        else if(a[i]<secMin && secMin>min)
            secMin = a[i];
    }
    res[0] = secMax;
    res[1] = secMin;

    return res;

}



// ------------------------------My Solution ------------------------------
// Time ->  O(n) with single pass
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Find the 'max' and 'min' of the vector array.
// Simultaneously find 'secMax' and 'secMin' 
// Store the values in vector, and finally return it.
