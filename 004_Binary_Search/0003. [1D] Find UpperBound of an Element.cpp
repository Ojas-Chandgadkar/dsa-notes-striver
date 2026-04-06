// Upperbound for element x is the smallest arr[index] such that : arr[index] > x.
// If it does not exists return 'Size of array'

int upperBound(vector<int> &arr, int x, int n){

	int ans = n;

	int low = 0;
	int high = n-1;
		
	while(low <= high){
		int mid = low + (high-low)/2;

		if(arr[mid] == x){
			low = mid+1;
		}
		else if(arr[mid] < x){
			low = mid+1;
		}
		else if(arr[mid] > x){
			ans = mid;
			high = mid-1;
		}
	}

	return ans;
}


// ------------------------------My Solution ------------------------------
// Time -> O(logn) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// We have to return the index of the element which is just greater than 'x' element.
// If such element does not exist return 'n', which is size of the vector.
// Initialze 'ans=n'
// Implement binary search such that,
// 		if(arr[mid]==x) mid = mid+1
//		keep on updating 'ans' for every (arr[mid] > x)
// Return 'ans' at the end.