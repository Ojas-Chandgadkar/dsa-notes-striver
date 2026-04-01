/*
Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


Example :
    Input: array = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
                7 is a candidate, and 7 = 7.
                These are the only two combinations.
*/


// Time  : O(2^target)
// Space : O(target)
// where N is target
class Solution {
public:

    void dfs(vector<int> &arr, int i, int &N, vector<int> &path, int target, vector<vector<int>> &res){

        if(target == 0){
            res.push_back(path);
            return;
        }
        if(i==N || target<0) return;

        path.push_back(arr[i]);
        dfs(arr, i, N, path, target-arr[i], res);
        path.pop_back();

        dfs(arr, i+1, N, path, target, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        int N = candidates.size();
        vector<int> path;

        dfs(candidates, 0, N, path, target, res);

        return res;
    }
};



// Time complexity : O(2^T) , where T is target value