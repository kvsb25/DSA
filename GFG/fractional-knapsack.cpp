class Solution {
  public:
    struct Item{
        int value;
        int weight;
    };
    
    static bool compare(Item i1, Item i2){
        double r1 = (double)i1.value/i1.weight;
        double r2 = (double)i2.value/i2.weight;
        return r1 > r2;
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<Item> items;
        
        for(int i = 0; i < val.size(); i++){
            items.push_back({val[i], wt[i]});    
        }
        
        sort(items.begin(), items.end(), compare);
        
        int i = 0;
        double remCap = capacity;
        double ans = 0;
        
        while(i < items.size()){
            Item t = items[i];
            double w = t.weight, v = t.value;
            
            if(remCap > 0){
                if(w > remCap){
                    ans += ((double)remCap/w)*v;
                    remCap -= remCap;
                } else {
                    ans += v;
                    remCap -= w;
                }
            } else {
                return ans;
            }
            
            i++;
        }
        
        return ans;
    }
};
