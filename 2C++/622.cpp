#include <vector>
using namespace std;
class MyCircularQueue {
private:
    int fullSize;      // ??¥Ó???ªº³Ì¤j®e¶q
    int length;
    int front;         // front«ü¦V?«e?‰`¤¸¯Àªº¦ì¸m, ?¦³´N-1
    int rear;          // rear«ü¦V?«e?§À¤¸¯Àªº¦ì¸m, ?¦³´N-1
    int* queue;
public:
    MyCircularQueue(int k) {
        this->queue = new int[k];
        this->front = -1;
        this->rear  = -1;
        this->length = 0;
        this->fullSize = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        this->rear = (this->rear + 1) % this->fullSize;
        if (this->front == -1) this->front++;
        this->queue[this->rear] = value;
        this->length++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        this->front = (this->front + 1) % this->fullSize;
        this->length--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        else  {
            return this->queue[this->front];
        }
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        else {
            return this->queue[this->rear];
        }
    }
    
    bool isEmpty() {
        return this->length == 0;
    }
    
    bool isFull() {
        return (this->length == this->fullSize);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */