#include<bits/stdc++.h>
using namespace std;

void printHelper(vector<int> &arr, int start, int end, vector<int> currPath, int target){
    
    if(target == 0){
        for(auto val : currPath) cout << val << " ";
        cout << endl;
        return;
    }
    if(start == end) return;
    if(target < 0) return;
    
    
    
    printHelper(arr, start+1, end, currPath, target);
    
    currPath.push_back(arr[start]);
    target -= arr[start];
    printHelper(arr, start, end, currPath, target);
    currPath.pop_back();                                                                    // backtrack
    target += arr[start];                                                                   // backtrack
  
}

void printTargetSum_withRepeation(vector<int> &arr, int target){
    
    int size = arr.size();
    vector<int> currPath;
    
    printHelper(arr, 0, size, currPath, target);
}

int main(){
  
    int target = 6;
    vector<int> arr = {2,3,4};
    
    printTargetSum_withRepeation(arr, target);
  
    return 0;
}



// This code works only for non-zero positive values in arr.