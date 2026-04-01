void selectionSort(vector<int>&arr) {
    
    int N = arr.size();

    for(int i=0; i<N-1; i++){
        int min = i;
        for(int j=i+1; j<N; j++){
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}