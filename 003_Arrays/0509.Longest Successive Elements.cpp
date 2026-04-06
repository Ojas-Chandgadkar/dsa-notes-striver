// There is an integer array ‘A’ of size ‘N’.
// A sequence is successive when the adjacent elements of the sequence have a difference of 1.

// Input:
// A = [5, 8, 3, 2, 1, 4], N = 6
// Output: 5

// Explanation: 
// The resultant sequence can be 1, 2, 3, 4, 5.    
// The length of the sequence is 5.



int longestSuccessiveElements(vector<int>&a) {

    int N = a.size();
    int maxLength = 1;

    sort(a.begin(), a.end());

    int len = 1;
    for(int i=0; i<N-1; i++){
        if((a[i+1]-a[i]) == 1){
            len++;
            maxLength = max(maxLength, len);
        }
        else{
            len = 1;
        }        
    }

    return maxLength;
}