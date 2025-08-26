class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int last=intervals[0][1];
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<last){
                cnt++;
            }
            else last=intervals[i][1];
        }
        return cnt;
        
    }
};