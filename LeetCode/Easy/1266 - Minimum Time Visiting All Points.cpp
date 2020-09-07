class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int t = 0;
        for(int i = 0 ; i < points.size() - 1 ; ++i){
            int cx = points[i][0];
            int cy = points[i][1];
            int nx = points[i + 1][0];
            int ny = points[i + 1][1];
            int dx = abs(cx - nx);
            int dy = abs(cy - ny);
            int m = min(dx, dy);
            t += dx + dy - m;
        }
        return t;
    }
};