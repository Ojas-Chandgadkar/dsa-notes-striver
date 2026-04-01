/*
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).The solution set must not contain duplicate subsets. 
Return the solution in any order.

Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/


class Solution {
public:

    void helper(vector<int> &arr, int i, int &N, vector<int> &path, vector<vector<int>> &res){

        if(i == N){
            res.push_back(path);
            return;
        }

        path.push_back(arr[i]);
        helper(arr, i+1, N, path, res);
        path.pop_back();

        while(i+1<N && arr[i]==arr[i+1]) i++;
        helper(arr, i+1, N, path, res);
    }

    void get_uniqueSubsets(vector<int> &nums, vector<vector<int>> &res){
        
        int N = nums.size();
        vector<int> path;

        helper(nums, 0, N, path, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        get_uniqueSubsets(nums, res);
        return res;
    }
};