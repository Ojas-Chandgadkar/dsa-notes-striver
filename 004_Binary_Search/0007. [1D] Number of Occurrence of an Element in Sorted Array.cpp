int count(vector<int>& arr, int n, int x) {

	int low = 0;
	int high = n-1;
	int mid = low + (high-low)/2;
	int leftmost_x = -1;
	while(low<=high){
		if(arr[mid] == x){
			leftmost_x = mid;
			high = mid-1;
		}
		else if(arr[mid] < x){
			low = mid+1;
		}
		else if(arr[mid] > x){
			high = mid-1;
		}
		mid = low + (high-low)/2;
	}

	low = 0;
	high = n-1;
	mid = low + (high-low)/2;
	int rightmost_x = -1;
	while(low<=high){
		if(arr[mid] == x){
			rightmost_x = mid;
			low = mid+1;
		}
		else if(arr[mid] < x){
			low = mid+1;
		}
		else if(arr[mid] > x){
			high = mid-1;
		}
		mid = low + (high-low)/2;
	}

    

	if(rightmost_x!=-1 && leftmost_x!=-1)
		return rightmost_x - leftmost_x + 1;
	else 
		return 0;
}
