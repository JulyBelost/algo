// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
private:
    queue<int> data;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
        for(int i = 0; i < data.size() - 1; ++i){
            data.push(data.front());
            data.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = data.front();
        data.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */