typedef pair<int,int> p;

class Solution {
  public:
  
  vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();

        // Step 1: Binary search to find the closest index to x
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid;
        }
    
        int l = left - 1, r = left;
        vector<int> result;
    
        while (k > 0) {
            if (l >= 0 && (r >= n || abs(arr[l] - x) < abs(arr[r] - x))) {
                if (arr[l] != x) {
                    result.push_back(arr[l]);
                    k--;     }
                l--;
            } else if (r < n) {
                if (arr[r] != x) {
                    result.push_back(arr[r]);
                    k--;     }
                r++;
            } else {
                break;
            }
        }
        return result;
    }
};