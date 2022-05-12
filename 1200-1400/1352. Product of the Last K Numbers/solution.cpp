class ProductOfNumbers {
private:
    vector<int> vec{1};
    
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (num == 0) vec.clear(), vec = {1};
        else vec.push_back(vec.back()*num);
    }
    
    int getProduct(int k) {
        if (k >= vec.size()) return 0;
        return vec.back()/vec[vec.size()-1-k];
    }
};
