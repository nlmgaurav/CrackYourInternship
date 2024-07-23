class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
       q1.push(x);
    }
    
    int pop() {
       while(q1.size()!=1){
           int temp=q1.front();
           q2.push(temp);
           q1.pop();
       }
        int target=q1.front();
        q1.pop();
        swap(q1,q2);
        return target;
    }
    
    int top() {
        while(q1.size()!=1){
            int temp=q1.front();
            q2.push(temp);
            q1.pop();
        }
        int target=q1.front();
        q1.pop();
        q2.push(target);
        swap(q1,q2);
        return target;
        
    }
    
    bool empty() {
        if(q1.size()==0)return true;
        return false;
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