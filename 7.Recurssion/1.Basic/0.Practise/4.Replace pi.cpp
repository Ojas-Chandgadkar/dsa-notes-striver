// Using recursion, replace all occurences of 'pi' with '3.14' in the string.

#include<bits/stdc++.h>
using namespace std;

string piReplace(string s){
    
    int len = s.size();
    if(len==0 || len==1) return s;
    
    
    if(s[0]=='p' && s[1]=='i'){
        return "3.14" + piReplace(s.substr(2));
    }
    else{
        return s[0] + piReplace(s.substr(1));
    }
}
int main(){
  
  string s = "abcpiabppi";
  
  string res = piReplace(s);
  cout << res;
  
  return 0; 
}