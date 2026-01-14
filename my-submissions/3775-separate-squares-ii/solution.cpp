class Solution {
public:
    struct Event {
        double y, x1, x2;
        int type; // +1 add, -1 remove
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        for (auto &sq : squares) {
            double x = sq[0], y = sq[1], l = sq[2];
            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});
        }

        sort(events.begin(), events.end(),
             [](const Event &a, const Event &b) {
                 return a.y < b.y;
             });

        multiset<pair<double, double>> active;

        auto unionX = [&]() {
            if (active.empty()) return 0.0;
            double res = 0;
            double L = -1e18, R = -1e18;
            for (auto &p : active) {
                if (p.first > R) {
                    res += max(0.0, R - L);
                    L = p.first;
                    R = p.second;
                } else {
                    R = max(R, p.second);
                }
            }
            res += max(0.0, R - L);
            return res;
        };

        double totalArea = 0;
        double prevY = events[0].y;

        // First pass: compute TOTAL UNION AREA
        for (int i = 0; i < events.size(); ) {
            double currY = events[i].y;
            double width = unionX();
            totalArea += width * (currY - prevY);

            while (i < events.size() && events[i].y == currY) {
                if (events[i].type == +1)
                    active.insert({events[i].x1, events[i].x2});
                else
                    active.erase(active.find({events[i].x1, events[i].x2}));
                i++;
            }
            prevY = currY;
        }

        double target = totalArea / 2.0;

        // Second pass: find minimum y
        active.clear();
        double areaSoFar = 0;
        prevY = events[0].y;

        for (int i = 0; i < events.size(); ) {
            double currY = events[i].y;
            double width = unionX();
            double deltaArea = width * (currY - prevY);

            if (areaSoFar + deltaArea >= target && width > 0) {
                return prevY + (target - areaSoFar) / width;
            }

            areaSoFar += deltaArea;

            while (i < events.size() && events[i].y == currY) {
                if (events[i].type == +1)
                    active.insert({events[i].x1, events[i].x2});
                else
                    active.erase(active.find({events[i].x1, events[i].x2}));
                i++;
            }
            prevY = currY;
        }

        return prevY;
    }
};

