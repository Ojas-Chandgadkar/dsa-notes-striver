// Given a number, find sum of its even and odd digits.
// Print both the sums.


#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int sumEven = 0;
	int sumOdd = 0;

	
	while(n!=0){
		int digit = n%10;
		n /= 10;
		
		if(digit%2==0) sumEven += digit;
		else sumOdd += digit;
	}	

	cout << sumEven << " " << sumOdd;
}
