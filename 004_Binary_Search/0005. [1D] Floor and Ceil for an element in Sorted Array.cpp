//Floor :  for x the largest element in the array which is smaller than or equal to x.
//Ceil :  for x the smallest element in the array greater than or equal to x.

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {

	int floor = -1;
	int ceil = -1;

	int low = 0;
	int high = n-1;
	
	while(low <= high){
		int mid = low + (high-low)/2;

		if(arr[mid] == x){
			return make_pair(arr[mid],arr[mid]);
		}
		else if(arr[mid] < x){
			floor = mid;
			low = mid+1;
		}
		else if(arr[mid] > x){
			ceil = mid;
			high = mid-1;
		}
	}

	if(floor!=-1) floor = arr[floor];
	if(ceil!=-1) ceil = arr[ceil];

	return make_pair(floor, ceil);
}


// ------------------------------My Solution ------------------------------
// Time -> O(logn) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// We have to written values of floor and ceil for an element 'x'.
// If any of it does not exist, we return -1. 
// Intialize 'floor=-1' and 'ceil=-1'
// Since the vector is sorted, we can use Binary Search
// 		if the element if found, we return 'make_pair(x,x)'
//		if(arr[mid] > k), ceil = mid
//		if(arr[mid] < k), floor = mid
// Return make_pair(arr[floor], arr[ceil]), after checking that indexes are not -1.