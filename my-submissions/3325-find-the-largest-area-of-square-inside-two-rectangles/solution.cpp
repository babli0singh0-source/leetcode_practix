class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;

        for (int i = 0; i < n; ++i) {
            int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
            int x2 = topRight[i][0], y2 = topRight[i][1];

            for (int j = i + 1; j < n; ++j) {
                int p1 = bottomLeft[j][0], q1 = bottomLeft[j][1];
                int p2 = topRight[j][0], q2 = topRight[j][1];

                // Compute intersection of rectangles i and j
                int ix1 = max(x1, p1);
                int iy1 = max(y1, q1);
                int ix2 = min(x2, p2);
                int iy2 = min(y2, q2);

                // Check if intersection is valid
                if (ix2 > ix1 && iy2 > iy1) {
                    int side = min(ix2 - ix1, iy2 - iy1);
                    maxArea = max(maxArea, 1LL * side * side);
                }
            }
        }

        return maxArea; // 0 if no intersection exists
    }
};
