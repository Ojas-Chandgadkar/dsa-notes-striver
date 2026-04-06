

// ======================================================================================
// MIN HEAP 
// ======================================================================================
#include<bits/stdc++.h>
using namespace std;

class MinHeap{
private : 
    vector<int> heap;
    
    int getParent(int i){return (i-1)/2;}
    int getLeftChild(int i){return (2*i)+1;}
    int getRightChild(int i){return (2*i)+2;}
    void heapifyUpwards(int i){
        int parent = getParent(i);
        if(i>0 && heap[i]<heap[parent]){
            swap(heap[i], heap[parent]);
            heapifyUpwards(parent);
        }
    }
    void heapifyDownwards(int i){
        int left = getLeftChild(i);
        int right = getRightChild(i);
        int lastIndex = heap.size();
        int smallest = i;
        
        if(left<lastIndex && heap[left]<heap[i]){
            smallest = left;
        }
        if(right<lastIndex && heap[right]<heap[smallest]){
            smallest = right;
        }
        
        if(smallest!=i){
            swap(heap[i], heap[smallest]);
            heapifyDownwards(smallest);
        }
    }
    
public : 
    int getMin(){                                           // peek
        if(heap.size()<=0) return -1; 
        return heap[0];
    }
    void push(int val){                                     // insert
        heap.push_back(val);
        heapifyUpwards(heap.size()-1);
    }
    void pop(){                                             // delete
        if(heap.size()<=0) return;
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        heapifyDownwards(0);
    }
    void printHeap(){
        for(auto val : heap){cout << val << " ";}
        cout << endl;
    }
};

int main(){
    MinHeap mh;
    
    mh.push(10);
    mh.push(5);
    mh.push(1);
    mh.pop();
    cout << mh.getMin() << endl;
    mh.printHeap();
    
    return 0;
    
}


// ======================================================================================
// MAX HEAP 
// ======================================================================================
#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
private: 
    vector<int> heap;
    
    int getParent(int i){return (i-1)/2;}
    int getLeftChild(int i){return (2*i)+1;}
    int getRightChild(int i){return (2*i)+2;}
    void heapifyUpwards(int i){
        int parent = getParent(i);
        if(i>0 && heap[i]>heap[parent]){
            swap(heap[i], heap[parent]);
            heapifyUpwards(parent);
        }
    }
    void heapifyDownwards(int i){
        int left = getLeftChild(i);
        int right = getRightChild(i);
        int lastIndex = heap.size();
        int largest = i;
        
        if(left<lastIndex && heap[left]>heap[i]){
            largest = left;
        }
        if(right<lastIndex && heap[right]>heap[largest]){
            largest = right;
        }
        
        if(largest!=i){
            swap(heap[i], heap[largest]);
            heapifyDownwards(largest);
        }
    }
    
public : 
    int getMax(){                                           // peek
        if(heap.size()<=0) return -1; 
        return heap[0];
    }
    void push(int val){                                     // insert
        heap.push_back(val);
        heapifyUpwards(heap.size()-1);
    }
    void pop(){                                             // delete
        if(heap.size()<=0) return;
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        heapifyDownwards(0);
    }
    void printHeap(){
        for(auto val : heap){cout << val << " ";}
        cout << endl;
    }
};

int main(){
    MaxHeap mh;
    
    mh.push(10);
    mh.push(5);
    mh.push(1);
    mh.pop();
    cout << mh.getMax() << endl;
    mh.printHeap();
    
    return 0;
    
}

