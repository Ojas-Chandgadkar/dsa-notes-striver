// Time  : O(N^2)
// Space : O(1)

void bubbleSort(int arr[], int N) 
{
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


