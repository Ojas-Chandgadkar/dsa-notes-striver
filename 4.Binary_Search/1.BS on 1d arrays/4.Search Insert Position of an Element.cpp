/*
Problem Statement : 
    You are given a sorted array arr of distinct values and a target value x. 
    You need to search for the index of the target value in the array.
    If the value is present in the array, then return its index. 
    Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.
*/

int searchInsert(vector<int>& arr, int m)
{
	int N = arr.size();
	int res = N;

	int low = 0;
	int high = N-1;

	while(low <= high){
		int mid = low + (high-low)/2;

		if(arr[mid] == m){
			return mid;
		}
		else if(arr[mid] < m){
			low = mid+1;
		}
		else if(arr[mid] > m){
			res = mid;
			high = mid-1;
		}
	}

	return res;
}

// ------------------------------My Solution ------------------------------
// Time -> O(logn) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// We have to find insertion index for element 'x' in a sorted 'arr' of unique elements.
// Initialize 'res=N' which will be the index of insertion of element x
// We will use Binary Search.
//      Return 'mid' if element found
//      Use lowerbound, that is find a index such that : arr[index] >= index
// Return 'res' at the end.