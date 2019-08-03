// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
private:
    stack<int> push_data;
    stack<int> pop_data;
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        push_data.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(pop_data.empty()){
            while(!push_data.empty()){
                pop_data.push(push_data.top());
                push_data.pop();
            }
        }
        int x = pop_data.top();
        pop_data.pop();
        return x;

    }

    /** Get the front element. */
    int peek() {
        if(pop_data.empty()){
            while(!push_data.empty()){
                pop_data.push(push_data.top());
                push_data.pop();
            }
        }
        return pop_data.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return push_data.empty() && pop_data.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */