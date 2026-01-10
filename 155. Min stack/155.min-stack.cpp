class MinStack {
public:
    stack<int> ms;
    stack<int> s;

    MinStack() {
    }
    
    void push(int val) {
        if(ms.empty() || val<=ms.top()){
            ms.push(val);
        }
        s.push(val);
        return;
    }
    
    void pop() {
        if(ms.top() == s.top()){
            ms.pop();
        }
        s.pop();
        return;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

// maintain two stacks
// ons stores all the elements
// one stores current minimum element 