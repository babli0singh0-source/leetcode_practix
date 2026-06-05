class MyStack {
    queue<int>q;
    int size=0;
public:
    MyStack() {
    }
    int siz(queue<int>q){
        int x=0;
        while(!q.empty()){
            x++;
            q.pop();
        }
        return x;
    }
    
    void push(int x) {
        int s=q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
        size++;
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        size--;
        return x;
    }
    
    int top() {
        return(q.front());
    }
    
    bool empty() {
        return (size==0);
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
