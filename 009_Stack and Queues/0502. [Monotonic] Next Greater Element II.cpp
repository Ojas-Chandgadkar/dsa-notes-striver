// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
// return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, 
// which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

// Example 1:
// Input: nums = [1,2,1]
// Output: [2,-1,2]




// Using Stack :
vector<int> nextGreaterElements(vector<int>& nums) {

    int size = nums.size();
    vector<int> nextGreat(size);
    stack<int> st;

    for(int i=2*size-1; i>=0; i--){
        int curr = nums[i%size];
        while(!st.empty() && curr>=st.top()){
            st.pop();
        }
        if(i<size){
            (st.empty()) ? nextGreat[i%size]=-1 : nextGreat[i%size]=st.top();
        }
        st.push(curr);
    }

    return nextGreat;
}



//Using Brute Force : 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> nextGreater;
        int size = nums.size();
        
        for(int i=0; i<size; i++){
            int nxtAvailable = false;
            for(int j=(i+1)%size; j!=i; (j+1)%size){
                if(nums[j] > nums[i]){
                    nextGreater.push_back(nums[j]);
                    nxtAvailable = true;
                    break;
                }
            }
            if(!nxtAvailable) nextGreater.push_back(-1);
        }

        return nextGreater;
    }
};