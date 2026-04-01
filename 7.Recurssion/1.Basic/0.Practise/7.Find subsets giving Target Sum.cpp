// Time  : O(2^N)
// Space : O(N)
// Where N is the stack size 
#include<bits/stdc++.h>
using namespace std;

void printHelper(vector<int> &arr, int start, int end, int currSum, vector<int> currPath, int target){
    
    if(currSum == target){
          for(auto val : currPath) cout << val << " ";
          cout << endl;
          return;
    }
    if(start==end){
        return;
    }
    if(currSum > target) return;
    
    printHelper(arr, start+1, end, currSum, currPath, target);
    
    currSum += arr[start];
    currPath.push_back(arr[start]);
    printHelper(arr, start+1, end, currSum, currPath, target);
}

void subsetTargetSum(vector<int> &arr, int target){
    int size = arr.size();
    vector<int> currPath;
    
    printHelper(arr, 0, size, 0, currPath, target);
}
int main(){
    
    int target = 12;
    vector<int> arr = {3,6,4,5,6,12};
    
    subsetTargetSum(arr, target);
  
    return 0;
}