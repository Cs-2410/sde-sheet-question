class MyStack {
public:
        queue<int> q1;
        
    MyStack() {
       while(!q1.empty())
               q1.pop();
            
    }
    
    void push(int x) {
       q1.push(x);
               for(int i = 0; i < q1.size()-1; i++){
                       int num = q1.front();
                       q1.pop();
                       q1.push(num);
               }
    }
    
    int pop() {
       if(q1.empty())return -1;
        
        int x=q1.front();
        q1.pop();
        
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
    return q1.empty();
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