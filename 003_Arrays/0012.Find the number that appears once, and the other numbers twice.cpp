int getSingleElement(vector<int> &arr){
	
	int N = arr.size();
	
	int xorr = 0;
	for(int i=0; i<N; i++){
		xorr = xorr ^ arr[i];
	}

	return xorr;
}


// ------------------------------My Solution ------------------------------
// Time ->  O(n) 
// Space -> O(1) 
// ------------------------------ Approach ------------------------------
// Assume the given array is: [4,1,2,1,2]
// XOR of all elements = 4^1^2^1^2	(XOR is exclusive-or, on bit level : a^a=0, a^b=1)
//      = 4 ^ (1^1) ^ (2^2)
//      = 4 ^ 0 ^ 0 = 4^0 = 4
// Hence, 4 is the single element in the array.