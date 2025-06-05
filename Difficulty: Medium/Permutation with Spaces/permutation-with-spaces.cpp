class Solution {
  public:
    vector<string> res;
    
    void solve(string s, string op){
        if(s.length()==0){
            res.push_back(op);
            return;
        }
        string op1 = op;
        string op2 = op;
        
        op1.push_back(' ');
        op1.push_back(s[0]);
        op2.push_back(s[0]);
        s.erase(s.begin()+0);
        
        solve(s,op1);
        solve(s,op2);
        
    }

    vector<string> permutation(string s) {
        // Code Here
        string op = "";
        op.push_back(s[0]);
        
        s.erase(s.begin()+0);
        
        solve(s,op);
        
        return res;
    }
};