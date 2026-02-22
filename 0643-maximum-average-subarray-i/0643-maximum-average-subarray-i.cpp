class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        unordered_map<int,double> hash;
        hash[-1]=0;
        double total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            hash[i]=total;
        }
        double ans=INT_MIN;
        for(int i=0;i<=nums.size()-k;i++){
            ans=max(ans,(hash[i+k-1]-hash[i-1])/k);
        }
        return ans;
    }
};