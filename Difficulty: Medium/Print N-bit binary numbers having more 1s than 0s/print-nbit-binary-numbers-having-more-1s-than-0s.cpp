// User function template for C++
class Solution {
  public:
  
    void solve(string op,int o, int z, int n, vector<string> &res){
        if(n==0){
            res.push_back(op);
            return;
        }
        
        
        string op1 = op;
        op1.push_back('1');
        solve(op1,o+1,z,n-1,res);
        
        
        
        if(o>z) {
            string op2 = op;
            op2.push_back('0');
            solve(op2,o,z+1,n-1,res);
            
        }
        
    }
    vector<string> NBitBinary(int n) {
        // Your code goes here
        vector<string> res;
        
        solve("",0,0,n,res);
        
        return res;
    }
};