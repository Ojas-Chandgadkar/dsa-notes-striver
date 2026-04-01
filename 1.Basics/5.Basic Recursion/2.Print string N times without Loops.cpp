/*
You are given an integer ‘n’.
Print “Coding Ninjas ” ‘n’ times, without using a loop.


*/

void get_res(int n, vector<string> &res){
	if(n<=0) return;

	res.push_back("Coding Ninjas");
	get_res(n-1, res);
}

vector<string> printNTimes(int n) {
	vector<string> res;
	get_res(n, res);

	return res;
}