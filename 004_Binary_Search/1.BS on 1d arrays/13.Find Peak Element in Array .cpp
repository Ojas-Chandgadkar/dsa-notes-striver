int findPeakElement(vector<int> &arr) {

    int n = arr.size();
    int low = 1;
    int high = n-2;
    int mid;

    if(n==0) return 1;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    while(low<=high){
        mid = low + (high-low)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){             // at peak
            return mid;
        }
        else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]){        // on dereasing slope
            high = mid-1;
        }
        else{
            low = mid+1;                                            // on increasing slope
        }
    }
    
    return -1;
}
