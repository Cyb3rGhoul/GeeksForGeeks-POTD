
class Solution {
public:
    int solve(string& s, int k) {
        int l = 0, r = 0, ctn = 0;
        unordered_map<char, int> mp;
        int n = s.length();
        while (r < n) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            ctn += (r - l + 1);
            r++;
        }
        return ctn;
    }

    int countSubstr(string& s, int k) {
        if (k == 0) return 0;
        return solve(s, k) - solve(s, k - 1);
    }
};