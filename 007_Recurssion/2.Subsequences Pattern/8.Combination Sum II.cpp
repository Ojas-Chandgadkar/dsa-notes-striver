/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example :
    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
*/

// OPTIMAL ==============================================================================================================
// Time  : O(2^N * Nlog N)
// Space : O(2^N)
// where N is size of candidates array
class Solution {
public:

    void get_combinations(vector<int>& arr, int i, int &N, vector<int> &path, int target, vector<vector<int>> &res){
        if(target == 0){
            res.push_back(path);
        }
        if(i==N || target<=0) return;

        path.push_back(arr[i]);
        get_combinations(arr, i+1, N, path, target-arr[i], res);
        path.pop_back();

        while(i+1<N && arr[i]==arr[i+1]) i++;
        get_combinations(arr, i+1, N, path, target, res);
    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> path;
        int N = candidates.size();

        sort(candidates.begin(), candidates.end());
        get_combinations(candidates, 0, N, path, target, res);

        return res;
    }
};


// NOT OPTIMAL ==============================================================================================================
class Solution {
public:

    void get_combinations(int i, int &N, vector<int>&arr, int target, vector<int> &path, set<vector<int>> &st){
        if(target==0){
            vector<int> temp = path;
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }
        if(target<0 || i==N) return;

        path.push_back(arr[i]);
        get_combinations(i+1, N, arr, target-arr[i], path, st);
        path.pop_back();

        get_combinations(i+1, N, arr, target, path, st);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int N = candidates.size();
        vector<vector<int>> res;
        vector<int> path;
        set<vector<int>> st;

        get_combinations(0, N, candidates, target, path, st);

        for(auto v : st){
            res.push_back(v);
        }

        return res;
    }
};