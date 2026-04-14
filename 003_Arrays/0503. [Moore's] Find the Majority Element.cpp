// If any element appears more than n / 2 times, it is the majority element

int majorityElement(vector<int> v) {
	
	int N = v.size();

	int count = 0;
	int element = -1;
	for(int i=0; i<N; i++){
		if(count==0){
			element = v[i];
			count++;
		}
		else if(v[i]==element){
			count++;
		}
		else if(v[i]!=element){
			count--;
		}
	}

	return element;
}


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// We will keep track of the occurrences of the majority element and minority elements dynamically.
// Intiialize 'count=0' and 'element=-1', these variables are dynamic.
// if(count==0), then store the a[i]=element and count++
// else if(a[i]==element), then count++.
// else if(a[i]!=element), then count--.
// (Moore’s Voting Algorithm)