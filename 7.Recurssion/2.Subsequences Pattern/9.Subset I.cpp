/*
You are given an array 'nums' of ‘n’ integers.
The given array has unique elements.
Return all subset sums of 'nums' in a non-decreasing order.


For example
    Input: 'nums' = [1,2]
    Output: [0,1,2,3].
*/


void get_subsetSum(vector<int> &arr, int i, int &N, int sum , vector<int> &res){
	if(i==N){
		res.push_back(sum);
		return;
	}
	
	get_subsetSum(arr, i+1, N, sum, res);
	get_subsetSum(arr, i+1, N, sum+arr[i], res);

}

vector<int> subsetSum(vector<int> &num){

	vector<int> res;
	int N = num.size();

	get_subsetSum(num, 0, N, 0, res);

	sort(res.begin(), res.end());
	return res;	
}