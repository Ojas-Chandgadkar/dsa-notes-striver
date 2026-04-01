// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
// If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.


// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]



// BRUTE FORCE : ==========================================================================================
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nextGreater;

        int size1 = nums1.size();
        int size2 = nums2.size();
        for(int i=0; i<size1; i++){
            for(int j=0; j<size2; j++){
                if(nums1[i]==nums2[j]){
                    while(j<size2 && nums2[j]<=nums1[i]) j++;
                    if(j<size2) nextGreater.push_back(nums2[j]);
                    else nextGreater.push_back(-1);
                    break;
                }
            }
        }

        return nextGreater;
    }
};


// Using Stack : ==========================================================================================
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nextGreater;
        int size1 = nums1.size();
        int size2 = nums2.size();

        unordered_map<int, int> umap;                            // <element, nextGreater>
        stack<int> st;                                           // monotonic stack

        umap[nums2[size2-1]] = -1;
        st.push(nums2[size2-1]);
        for(int i=size2-2; i>=0; i--){
            int curr = nums2[i];            
            
            if(curr < st.top()){
                umap[curr] = st.top();
                st.push(curr);
            }   
            else if(curr>st.top()){
                while(!st.empty() && curr>st.top()){
                    st.pop();
                }
                (st.empty()) ? umap[curr]=-1 : umap[curr]=st.top(); 
                st.push(curr);
            }

        }
        for(int i=0; i<size1; i++){
            nextGreater.push_back(umap[nums1[i]]);
        }

        return nextGreater;
    }

