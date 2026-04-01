class MyQueue {

    stack<int> st;
    stack<int> stHelper;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty()){
            stHelper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!stHelper.empty()){
            st.push(stHelper.top());
            stHelper.pop();
        }
    }
    
    int pop() {
        if(empty()) return -1;

        int val = st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        if(empty()) return -1;
        return st.top(); 
    }
    
    bool empty() {
        if(st.empty()) return true;
        return false;
    }
};
