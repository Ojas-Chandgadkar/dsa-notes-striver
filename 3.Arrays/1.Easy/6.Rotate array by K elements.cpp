vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    
    k = k%n;
    vector<int> temp(k);

    int i = 0;
    while(i<k){
        temp[i] = arr[i];
        i++;
    }
    i=0;
    while(k<n){
        arr[i] = arr[k];
        i++;
        k++;
    }
    int t = 0;
    while(i<n){
        arr[i] = temp[t];
        i++;
        t++;
    }

    return arr;
}


// ------------------------------My Solution ------------------------------
// Time ->  O(n) 
// Space -> O(k) 
// ------------------------------ Approach ------------------------------
// Intialize a 'vector<int> temp(k)' to store the first elements of arr from 0 to k
// Then from k to n, place elements to starting of arr.
// Then from 0 to k, copy back elements to end of arr from arr.
// Finally return the arr.