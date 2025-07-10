class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n == 0) return 0;
        
        unordered_map<int, int> freq; // Track frequency of each element
        int l = 0, r = 0;
        int maxLen = 0;
        
        while (r < n) {
            // Add current element to window
            freq[arr[r]]++;
            
            // If more than 2 distinct elements, shrink window
            while (freq.size() > 2) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) {
                    freq.erase(arr[l]);
                }
                l++;
            }
            
            // Update maximum length
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        
        return maxLen;
        
    }
};