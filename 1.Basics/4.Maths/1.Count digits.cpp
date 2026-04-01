// You are given a number ’n’.
// Find the number of digits of ‘n’ that evenly divide ‘n’.
// Example : 
//     Input: ‘n’ = 336
//     Output: 3
//     Explanation:
//     336 is divisible by both ‘3’ and ‘6’. Since ‘3’ occurs twice it is counted two times.



int countDigits(int n){

	int count = 0;
	
	int num = n;
	while(n > 0){
		int digit = n%10;
		n = n/10;

		if(digit!=0 && num%digit == 0) count++;
	}	

	return count;
}