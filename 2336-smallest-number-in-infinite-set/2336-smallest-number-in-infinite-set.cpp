class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int smallest=1;
    unordered_set<int> added;
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if(!pq.empty())
        {
            int ans=pq.top();
            pq.pop();
            added.erase(ans);
            return ans;
        }
        return smallest++;
        
    }
    
    void addBack(int num) {
        if(num < smallest && added.find(num) == added.end())
        {
            pq.push(num);
            added.insert(num);
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */