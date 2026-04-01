// Time  : O(2^N)
// Space : O(N)
// where N is nums size
class Solution {
public:

    void helper(int i, int N, vector<int> &nums, vector<int> &path, vector<vector<int>> &powerSet){

        if(i == N){
            powerSet.push_back(path);
            return;
        }

        helper(i+1, N, nums, path, powerSet);                   

        path.push_back(nums[i]);
        helper(i+1, N, nums, path, powerSet);
        path.pop_back();
    }

    vector<vector<int>> get_powerSet(vector<int> &nums){

        vector<vector<int>> powerSet;
        vector<int> path;
        int N = nums.size();

        helper(0, N, nums, path, powerSet);
        return powerSet;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return get_powerSet(nums);
    }
};

