class MyQueue {
public:
    stack<int> s;

    MyQueue() {    
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            return;
        }

        int val = s.top();
        s.pop();
        push(x);
        s.push(val);
        return;
    }
    
    int pop() {
        int val = s.top();
        s.pop();
        return val;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};