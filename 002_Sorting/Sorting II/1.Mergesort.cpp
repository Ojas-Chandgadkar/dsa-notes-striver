// Time  : O(N.LogN)
// Space : O(N)


#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> res;
    int i = low, j=mid+1;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            res.push_back(arr[i]);
            i++;
        }
        else{
            res.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        res.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        res.push_back(arr[j]);
        j++;
    }

    i = low;
    for(auto x : res){
        arr[i] = x;
        i++;
    }
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    vector<int> arr = {19,-3,0,54,19,5};
    int n = arr.size();

    mergeSort(arr, 0, n-1);
    for(auto x : arr) cout << x << " ";
    return 0;
}