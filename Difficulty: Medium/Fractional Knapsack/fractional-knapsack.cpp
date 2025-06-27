// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(pair<double,double> &p1, pair<double,double> &p2){
    return (p1.first/p1.second) > (p2.first/p2.second);
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        vector<pair<double,double>> vec;
        
        for(int i = 0; i<val.size(); i++){
            vec.push_back({val[i],wt[i]});
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        double total = 0;
        
        for(int i = 0; i<vec.size(); i++){
            if(capacity >= vec[i].second){
                total += vec[i].first;
                capacity -= vec[i].second;
            }else{
                double value = vec[i].first;
                double weight = vec[i].second;
                
                double ratio = value / weight;
                total += (capacity * ratio);
                break;
            }
            
        }
        
        return total;
        
    }
};
