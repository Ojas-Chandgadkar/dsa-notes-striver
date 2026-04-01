// Time  : O(N.LogN)
// Space : O(1)


#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;                          // to get last element less than pivot
    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pivotIndx = partition(arr, low, high);
        quickSort(arr, low, pivotIndx-1);
        quickSort(arr, pivotIndx+1, high);
    }
}

int main(){
    vector<int> arr = {19,-3,0,54,19,5};
    int n = arr.size();

    quickSort(arr, 0, n-1);
    for(auto x : arr) cout << x << " ";
    return 0;
}