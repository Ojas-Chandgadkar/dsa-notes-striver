// Time  : O(N^2)
// Space : O(1)

void insertionSort(vector<int> arr, int n){
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j+1]<arr[j]) swap(arr[j+1],arr[j]);
            else break;
        }
    }
    printArr(arr, n);
}



