class MyStack {
private:
    queue<int> qu;
public:
    MyStack() {
    }
    
    void push(int x) {
        int size = qu.size();
        qu.push(x);
        while (size) {
            qu.push(qu.front()); qu.pop();
            size--;
        }
    }
    
    int pop() {
        int x = qu.front(); qu.pop();
        return x;
    }
    
    int top() {
        return qu.front();
    }
    
    bool empty() {
        return qu.empty();
    }
};
