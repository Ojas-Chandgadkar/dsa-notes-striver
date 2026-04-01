class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int N = nums.size();
        int maxOnes = 0;
        
        int temp = 0;
        for(int i=0; i<N; i++){
            if(nums[i]==1){
                temp++;
            }      
            else{
                temp = 0;
            }
            
            maxOnes = max(maxOnes, temp);
        }

        return maxOnes;
    }
};

// ------------------------------My Solution ------------------------------
// Time ->  O(n) 
// Space -> O(1) 
// ------------------------------ Approach ------------------------------
// Intialize 'maxOnes' and 'temp', set both as 0
// 'temp' variable helps to count each conseutive occurrence of 1's
//  maxOnes stores the maximum between (maxOnes, temp)
//  finally return 'maxOnes'.