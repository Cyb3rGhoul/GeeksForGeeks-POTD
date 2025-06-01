class Solution {
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        vector<int> nums;
        unordered_set<int> st;
        
        for(int i = 0; i < mat1.size(); i++) {
            for(int j = 0; j < mat1[0].size(); j++) {
                nums.push_back(mat1[i][j]);
            }
        }
        
        for(int i = 0; i < mat2.size(); i++) {
            for(int j = 0; j < mat2[0].size(); j++) {
                st.insert(mat2[i][j]);
            }
        }
        
        int ctn = 0;
        for(int num : nums) {
            if(st.find(x - num) != st.end()) {
                ctn++;
            }
        }
        return ctn;
    }
};