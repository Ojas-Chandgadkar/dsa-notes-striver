// You’re given a data type. Print its size in bytes.


int dataTypes(string type) {
	
	if(type == "Integer") return sizeof(int);
	else if(type == "Long") return sizeof(long);
	else if(type == "Float") return sizeof(float);
	else if(type == "Double") return sizeof(double);
	else if(type == "Character") return sizeof(char);

	return 0;
}

