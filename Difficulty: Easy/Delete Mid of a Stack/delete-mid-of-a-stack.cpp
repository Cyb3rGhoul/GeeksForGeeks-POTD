class Solution {
  public:
    // Function to delete middle element of a stack.
    
    void solve(stack<int>& s,int k){
        if(s.size()==1 || k==1){
            s.pop();
            return;
        }
        int val = s.top();
        s.pop();
        solve(s,k-1);
        s.push(val);
    }
    void deleteMid(stack<int>& s) {
        // code here..
        if(s.size()==0) return;
        int k = (s.size()/2) + 1;

        solve(s,k);
    }
};