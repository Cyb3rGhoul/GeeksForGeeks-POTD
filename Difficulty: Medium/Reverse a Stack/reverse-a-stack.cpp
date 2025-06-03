// User function Template for C++

class Solution {
  public:
    void insert(stack<int> &St, int val){
        if(St.empty()){
            St.push(val);
            return;
        }
        
        int t = St.top();
        St.pop();
        insert(St, val);
        St.push(t);
        
    }
    void Reverse(stack<int> &St) {
        if(St.empty()) return;
        
        int val = St.top();
        St.pop();
        Reverse(St);
        insert(St,val);
    }
};