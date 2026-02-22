class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long r=1e14;
        long long l=1;
        long long ans=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long bus=0;
            for(int i=0;i<time.size();i++){
                bus+=mid/time[i];
                if(bus>=totalTrips){
                    ans=mid;
                    r=mid-1;
                    break;
                }
            }
            if(bus<totalTrips){
                l=mid+1;
            }
            else {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};