class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        set<int> st;
        vector<int> res;
        for(int i = 0; i<a.size(); i++){
            st.insert(a[i]);    
        }
        
        
        for(int i = 0; i<b.size(); i++){
            st.insert(b[i]);
        }
        
        for(int num: st){
            res.push_back(num);
        }
        
        return res;
        // return vector with correct order of elements
    }
};