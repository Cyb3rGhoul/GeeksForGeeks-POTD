class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int num = *max_element(arr.begin(),arr.end());
        return num;
        
    }
};
