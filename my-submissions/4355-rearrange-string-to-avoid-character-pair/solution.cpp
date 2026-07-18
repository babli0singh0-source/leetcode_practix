class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string others = "";
        string ys = "";
        string xs = "";

        for (char c : s) {
            if (c == y)ys += c;
            else if (c == x)xs += c;
            else others += c;
        }

        return others + ys + xs;
    }
};
