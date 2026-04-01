int linearSearch(int n, int num, vector<int> &arr)
{
    int index = -1;

    for(int i=0; i<n; i++){
        if(arr[i]==num){
            index = i;
            break;
        }
    }

    return index;
}


// ------------------------------My Solution ------------------------------
// Time ->  O(n) 
// Space -> O(1) 
// ------------------------------ Approach ------------------------------
// set index as -1 
// iterate through given arr, if arr[i]==num, update index = i and break loop
// return index