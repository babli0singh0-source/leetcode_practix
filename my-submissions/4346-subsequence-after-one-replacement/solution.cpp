class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> left(n, -1), right(n, -1);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j == m) break;
            left[i] = j++;
        }
        if (left[n - 1] != -1) return true;
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) break;
            right[i] = j--;
        }
        for (int i = 0; i < n; i++) {
            int L = -1;
            if (i > 0) {
                if (left[i - 1] == -1) continue;
                L = left[i - 1];
            }
            int R = m;
            if (i + 1 < n) {
                if (right[i + 1] == -1) continue;
                R = right[i + 1];
            }
            if (L + 1 < R)return true;
        }
        return false;
    }
};
