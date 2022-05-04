class FreqStack {
private:
    unordered_map<int,int> hashmap;
    vector<stack<int>> nested;
    
public:
    FreqStack() {
    }
    
    void push(int val) {
        if (nested.size()<hashmap[val]+1) nested.push_back(stack<int>());
        nested[hashmap[val]].push(val);
        hashmap[val]++;
    }
    
    int pop() {
        int x = nested.back().top();
        nested.back().pop();
        if (nested.back().empty()) nested.pop_back();
        hashmap[x]--;
        return  x;
    }
};
