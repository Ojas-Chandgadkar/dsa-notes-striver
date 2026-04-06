// Same no of +ve and -ve elements, alernaively arrange them starting from +ve.
// Without changing the original order.

vector<int> alternateNumbers(vector<int>&a) {
    
    int N  = a.size();
    vector<int> res(N);
    
    int posIndex = 0;
    int negIndex = 1;
    for(int i=0; i<N; i++){
        if(a[i]>0){
            res[posIndex] = a[i];
            posIndex += 2;
        }
        else if(a[i]<0){
            res[negIndex] = a[i];
            negIndex += 2;
        }
    }

    return res;
}


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(n)
// ------------------------------ Approach ------------------------------
// Initialize 'vector<int> res(N)' to store the final result.
// Initialize 'posIndex=0' and 'negIndex=1', this are index keepers for res.
// Check every element of a, if +ve add to posIndex, else negIndex. 
// Whichever index was used increment it by 2
// Return res at end.