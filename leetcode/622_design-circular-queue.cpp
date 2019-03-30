// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
private:
    vector<int> data;
    int head, tail;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(head == -1){
            ++head;
            ++tail;
            data[head] = value;
            return true;
        }
        if(head == (tail + 1) % data.size()){
            return false;
        }
        tail = (tail + 1) % data.size();
        data[tail] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(head == -1){
            return false;
        }
        if(head == tail){
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % data.size();
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        return head == -1 ? head : data[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        return tail == -1 ? tail : data[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return head == (tail + 1) % data.size();
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
