class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<int,long long>> number(n,{0,-1});
        sort(meetings.begin(),meetings.end());
        int i=0;
        int m=meetings.size();
        while(i<m){
            int placed=0;
            long long time=number[0].second;
            int ind=0;
            for(int j=0;j<n;j++){
                if(number[j].second<=meetings[i][0]){
                    number[j].first++;
                    number[j].second=meetings[i][1];
                    placed=1;
                    break;
                }
                else{
                    if(number[j].second<time){
                        time=number[j].second;
                        ind=j;
                    }
                }
            }
            if(placed==0){
                number[ind].first++;
                number[ind].second+=meetings[i][1]-meetings[i][0];
            }
            i++;
        }
        int t=number[0].first;
        int ans=0;
        for(int k=0;k<number.size();k++){
            if(t<number[k].first){
                t=number[k].first;
                ans=k;
            }
        }
        return ans;
    }
};