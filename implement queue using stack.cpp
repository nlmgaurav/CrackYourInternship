class MyQueue {
public:
   stack<int>s1,s2;
    MyQueue() {
        
    }
    void push(int x) {
        s1.push(x);
    }
    
	// making the dequeue longer as we will have to push elements twice in s1 (in enqueue)
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        if(!s2.empty()) {
            return s2.top();
        }
        else {                                           // if s2 is empty then push elements from s1 to s2
            while(!s1.empty()) {                //  Used this approach coz otherwise we'll have to do this everytime in enqueue
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        if(s2.empty() && s1.empty()) return true;
        return false;
    
   
    }

};