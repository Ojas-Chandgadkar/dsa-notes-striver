int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();

	int low = 0;
	int high = n-1;
	int mid;

	if(n==1) return arr[0];
	else if(arr[0]!=arr[1]) return arr[0];
	else if(arr[n-2]!=arr[n-1]) return arr[n-1];
	while(low <= high){
		mid = low + (high-low)/2;

		if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
			return arr[mid];
		}
		
		else if(arr[mid]==arr[mid+1]){
			if(mid%2==0) low=mid+1;
			else high=mid-1;
		}
 		else if(arr[mid]==arr[mid-1]){
			if((mid-1)%2==0) low=mid+1;
			else high=mid-1;
		}
	}
}