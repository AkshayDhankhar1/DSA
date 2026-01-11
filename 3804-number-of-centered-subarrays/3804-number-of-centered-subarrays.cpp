class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            unordered_map<int,int> hash;
            for(int j=i;j<n;j++){
                hash[nums[j]]++;
                sum+=nums[j];
                if(hash.count(sum)){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};