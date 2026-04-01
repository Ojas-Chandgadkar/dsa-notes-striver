int pop(vector<int> &heap)
{
    if(heap.size()==0) return -1;
    int res = heap[0];

    swap(heap[0], heap[heap.size()-1]);    
    heap.pop_back();

    int N = heap.size();
    int curr = 0;
    while(true){
        int left = (2*curr)+1;
        int right = (2*curr)+2;
        int largest = curr;

        if(left<N && heap[left]>heap[largest]){
            largest = left;
        }
        if(right<N && heap[right]>heap[largest]){
            largest = right;
        }

        if(largest==curr) break;
        else{
            swap(heap[largest], heap[curr]);
            curr = largest;
        }
    }

    return res;
}

// Code Snippet of the push function: 
//
//     void push(vector<int> &heap, int x)
//     {
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position. 
//                  break;
//              }
//          }
//      }