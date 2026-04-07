// Compare the numbers and print the relation.

// Print “smaller”, “greater” or “equal” when ‘a’ is smaller than ‘b’, greater than ‘b’, or equal to ‘b’ respectively.



string compareIfElse(int a, int b) {

	if(a==b) return "equal";
	else if(a < b) return "smaller";
	else if(a > b) return "greater";
}
