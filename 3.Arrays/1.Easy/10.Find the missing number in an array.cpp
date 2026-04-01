int missingNumber(vector<int>&a, int N) {

    int Sum2 = (N*(N+1))/2;
    int Sum1 = 0;
    
    for(int i=0; i<N-1; i++){
        Sum1 += a[i];
    }

    return Sum2-Sum1;
}

// ------------------------------My Solution ------------------------------
// Time ->  O(n) 
// Space -> O(1) 
// ------------------------------ Approach ------------------------------
// We have given an array with range 1 to N, but with one element missing, So the size is N-1.
// We know that sum of first 'n' numbers is '(N+(N+1))/2.
// So we can get the missing number by :
//      Sum_of_Complete_array - Sum_of_missing_number_arr