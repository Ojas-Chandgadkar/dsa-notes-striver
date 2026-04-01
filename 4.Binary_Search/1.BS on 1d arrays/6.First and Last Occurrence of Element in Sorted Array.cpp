pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int low = 0;
    int high = n-1;
    int mid = low + (high-low)/2;

    int firstOccur = -1;
    while(low <= high){
        if(arr[mid] == k){
            firstOccur = mid;  
            high = mid-1;  
        }    
        else if(arr[mid] < k) low=mid+1;
        else high=mid-1;

        mid = low + (high-low)/2;
    }    

    if(firstOccur==-1) return make_pair(-1,-1);
    
    low = 0;
    high = n-1;
    mid = low + (high-low)/2;
    int lastOccur = -1;
    while(low <= high){
        if(arr[mid] == k){
            lastOccur = mid;  
            low = mid+1;  
        }    
        else if(arr[mid] < k) low=mid+1;
        else high=mid-1;

        mid = low + (high-low)/2;
    }    


    return make_pair(firstOccur, lastOccur);
}


// ------------------------------My Solution ------------------------------
// Time -> O(logn) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// 
//