class Solution {
public:
    vector<int> half;
    long long K;

    long long comb(long long n, long long r) {
        r = min(r, n - r);
        long long res = 1;
        for (long long i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res > K) return K + 1;
        }
        return res;
    }

    long long countWays(int rem) {
        long long ways = 1;
        for (int i = 0; i < 26; i++) {
            if (half[i] == 0) continue;
            ways *= comb(rem, half[i]);
            if (ways > K) return K + 1;
            rem -= half[i];
        }
        return ways;
    }

    string smallestPalindrome(string s, long long k) {
        K = k;
        vector<int> freq(26, 0);
        half.assign(26, 0);

        string mid = "";
        for (char c : s) freq[c - 'a']++;

        int len = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)mid.push_back('a' + i);
            half[i] = freq[i] / 2;
            len += half[i];
        }

        string left = "";
        long long rank = 1;
        for (int pos = 0; pos < len; pos++) {
            bool found = false;
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;
                half[c]--;
                long long ways = countWays(len - pos - 1);
                if (rank + ways > K) {
                    left.push_back('a' + c);
                    found = true;
                    break;
                }
                rank += ways;
                half[c]++;
            }
            if (!found) return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
