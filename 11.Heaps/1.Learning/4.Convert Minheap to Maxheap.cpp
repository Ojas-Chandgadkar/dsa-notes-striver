
void insert(int val, vector<int> &res){
	res.push_back(val);
	int currIndex = res.size()-1;

	while(currIndex >0){
		int parent = (currIndex-1)/2;
		if(res[currIndex]>res[parent]){
			swap(res[currIndex], res[parent]);
			currIndex = parent;
		}
		else{
			return;
		}
	}
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	vector<int> maxHeap;
	for(int i=0; i<n; i++){
		insert(arr[i], maxHeap);
	}
	return maxHeap;
}





// Ohter way
vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	return arr;

}