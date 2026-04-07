// An Armstrong number is a number (with 'k' digits) 
// such that the sum of its digits raised to 'kth' power is equal to the number itself. 
// For example, 371 is an Armstrong number because 3^3 + 7^3 + 1^3 = 371.


bool checkArmstrong(int n){

	int number = n;
	int totalDigits = 0;
	while(n > 0){
		totalDigits++;
		n = n/10;
	}

	n = number;
	int sum = 0;
	while(n > 0){
		sum += pow((n%10), totalDigits);
		n = n/10;

		if(sum > number) break;
	}

	return number == sum;
}
