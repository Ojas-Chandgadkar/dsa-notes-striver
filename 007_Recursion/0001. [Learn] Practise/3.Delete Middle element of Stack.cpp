// Time  : O(N)
// Space : O(N)
// Where N is the stack size 
#include<bits/stdc++.h>
using namespace std;

void Delete_middle(stack<int> &st, int middleAt){
  if(middleAt == 1){
    st.pop();
    return;
  }
  
  int temp = st.top();
  st.pop();
  
  Delete_middle(st, middleAt-1);
  st.push(temp);
}


void printStack(stack<int> &st){
  if(st.empty()) 
    return;
  
  int val = st.top();
  st.pop();
  
  printStack(st);
  cout << val << " ";
  st.push(val);
}

int main(){
  stack<int> st;
  st.push(0);
  st.push(1);
  st.push(2); // middle
  st.push(3);
  st.push(4);
  int middleAt = (st.size())/2 + 1;

  cout << "\nBefore Deleting middle : ";
  printStack(st);
  
  Delete_middle(st, middleAt);
  
  cout << "\nAfter Deleting middle  : ";
  printStack(st);
  
  
  return 0;
}