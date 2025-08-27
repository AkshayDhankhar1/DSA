class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int x1 = grid.size();
        int x2 = -1;
        int y2 = -1;
        int y1 = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                    x1 = min(x1, i);
                }
            }
        }
        if(x2==-1) return 0;
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};