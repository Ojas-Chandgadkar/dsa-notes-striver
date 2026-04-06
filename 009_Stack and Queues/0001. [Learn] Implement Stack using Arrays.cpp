// Stack class.
class Stack {

private : 
    int *arr;
    int size;
    int topm;
    
    
public:

    Stack(int capacity) {
        this->size = capacity;
        arr = new int[size];
        topm = -1;
    }

    void push(int num) {
        if(!isFull()){
            topm++;
            arr[topm] = num;
        }
    }

    int pop() {
        if(!isEmpty()){
            int popped = arr[topm];
            topm--;
            return popped;
        }
        return -1;
    }
    
    int top() {
        if(!isEmpty()) return arr[topm];
        return -1;
    }
    
    bool isEmpty() {
        return topm == -1;
    }

    bool isFull() {
        return topm == size - 1;
    }
    
};
