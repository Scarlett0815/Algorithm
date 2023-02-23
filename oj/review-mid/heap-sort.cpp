#include <iostream>

using namespace std;

int heap_size;
int n;

void MaxHeapify(int heap[], int root){
    int largest = root;
    if (2 * root + 1 <= heap_size - 1 && heap[largest] < heap[root * 2 + 1]){
        largest = 2 * root + 1;
    }
    if (2 * root + 2 <= heap_size - 1 && heap[largest] < heap[root * 2 + 2]){
        largest = 2 * root + 2;
    }
    if (largest != root){
        int temp;
        temp = heap[largest];
        heap[largest] = heap[root];
        heap[root] = temp;
        MaxHeapify(heap, largest);
    }
    return;
}

void BuildHeap(int heap[]){
    for (int i = (heap_size + 1) / 2 - 1;i >= 0;i --){
        MaxHeapify(heap, i);
    }
    return;
}

void HeapSort(int heap[]){
    BuildHeap(heap);
    for (int i = n - 1;i > 0;i --){
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        heap_size --;
        MaxHeapify(heap, 0);
    }
    return;
}

int main(){
    cin >> n;
    heap_size = n;
    int heap[n];
    for (int i = 0;i < n;i ++){
        cin >> heap[i];
    }
    HeapSort(heap);
    for (int i = 0;i < n;i ++){
        cout << heap[i] << ' ';
    }
    cout << endl;
}