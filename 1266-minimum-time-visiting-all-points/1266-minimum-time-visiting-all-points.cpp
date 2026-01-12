class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sec=0;
        for(int i=0;i<points.size()-1;i++){
            int dx=abs(points[i][0]-points[i+1][0]);
            int dy=abs(points[i][1]-points[i+1][1]);
            sec+=max(dx,dy);
        }
        return sec;
    }
};