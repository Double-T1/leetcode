//solution 3 is the only acceptable one, even though the other two also passes on complexity basis
//the premise of iterator reuqires no storage of acutal data

//solution 1
//time: O(n) at construction, O(1) for other operations
//space: O(n)
class NestedIterator {
private:
    vector<int> list; 
    int i=0;
    
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        return list[i++];
    }
    
    bool hasNext() {
        return i<list.size();
    }
private:
    void helper(vector<NestedInteger> &nestedList) {
        for (int j=0; j<nestedList.size(); j++) {
            if (nestedList[j].isInteger()) {
                list.push_back(nestedList[j].getInteger());
            } else {
                helper(nestedList[j].getList());
            }
        }
    }
};

//solution 2
//time: O(m) for initial construction, and O(k) for other operations, m*k = n
//space: O(m)
//m being the first layer size of the nested list
class NestedIterator {
private:
    stack<NestedInteger*> st;     
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        unpack(nestedList);
    }
    
    int next() {
        int x = st.top()->getInteger(); st.pop();
        return x;
    }
    
    bool hasNext() {
        while (!st.empty() && !st.top()->isInteger()) {
            auto ptr = st.top(); st.pop();
            unpack(ptr->getList());
        }
        return !st.empty();
    }
    
private:
    void unpack(vector<NestedInteger> &nestedList) {
        for (int i= nestedList.size()-1; i>=0; i--) {
            st.push(&nestedList[i]);
        }
    }
};

//solution 3
//space: O(h)
class NestedIterator {
public:
    typedef vector<NestedInteger>::iterator it;
    
private:
    stack<it> begins, ends;     
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }
    
    int next() {
        return begins.top()++->getInteger();
    }
    
    bool hasNext() {
        while (!begins.empty()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else if (begins.top()->isInteger()) {
                return true;
            } else {
                auto& nestedList = begins.top()++->getList();
                begins.push(nestedList.begin());
                ends.push(nestedList.end());
            }
        }
        return false;
    }
};
