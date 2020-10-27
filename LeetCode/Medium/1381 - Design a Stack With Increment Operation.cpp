class CustomStack {
    int max_size;
    vector <int> st;
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
        st.reserve(max_size);
    }
    
    void push(int x) {
        if(st.size() == max_size) return;
        st.emplace_back(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int t = st.back();
        st.pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        for(int i = 0 ; i < min((int) st.size(), k) ; ++i){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */