// Time  : O(2^N)
// Space : O(N)
// Where N is the string length
#include<bits/stdc++.h>
using namespace std;

void printHelper(vector<int> &arr, int i, int currSum){
    if(i==-1){
        cout << currSum << endl;
        return;
    };
    
    printHelper(arr, i-1, currSum + arr[i]);
    printHelper(arr, i-1, currSum);
}

void printSubsetSum(vector<int> &arr){
    int size = arr.size();
    printHelper(arr, size-1, 0);
}

int main() 
{
    vector<int> arr = {3,4,5};
    printSubsetSum(arr);
    
    return 0;
}