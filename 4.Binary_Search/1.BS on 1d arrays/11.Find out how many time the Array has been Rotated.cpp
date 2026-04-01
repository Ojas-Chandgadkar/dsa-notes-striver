int findKRotation(vector<int> &arr){

    int res = 0;                    // index of minimum
    int N = arr.size();
    
    int low = 0;
    int high = N-1;
    int mid;

    int temp = 0;                    // temp minimum index
    while(low <= high){
        mid = low + (high-low)/2;

        if(arr[low] <= arr[mid]){
            temp = (arr[low] < arr[mid])?  low : mid; 
            res = (arr[res] < arr[temp])?  res : temp; 
            low = mid+1;
        }
        else if(arr[mid] <= arr[high]){
            temp = (arr[mid] < arr[high])? mid : high;
            res = (arr[res] < arr[temp])? res : temp;
            high = mid-1;
        }
    }

    return res;

}