// https://leetcode.com/problems/min-stack/

class MinStack {
private:
    vector<int> data;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }

    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        data.pop_back();
    }

    int top() {
        if(data.empty()){
            return -1;
        }
        return data.back();
    }

    int getMin() {
        if(data.empty()){
            return -1;
        }
        int min = data.back();
        for(int i = data.size() - 1; i >= 0; --i){
            if(data[i] < min){
                min = data[i];
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
