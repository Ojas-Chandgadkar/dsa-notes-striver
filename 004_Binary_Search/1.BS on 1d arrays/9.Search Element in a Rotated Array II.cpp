// RotatedArray + mayContainDuplicates

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {

    int N = A.size();

    int low = 0;
    int high = N-1;
    int mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(A[mid]==key) return true;

        else if(A[low]==A[mid] && A[mid]==A[high]){     // duplicates skipper
            low++;
            high--;
            continue;
        }
        else if(A[low]<=A[mid]){
            if(A[low]<=key && key<=A[mid])
                high = mid-1;
            else 
                low = mid+1;
        }
        else if(A[mid]<=A[high]){
            if(A[mid]<=key && key<=A[high])
                low = mid+1;
            else 
                high = mid-1;
        }
    }

    return false;
}
