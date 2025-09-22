class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> hash;
        int max=0;
        for(int i: nums){
            hash[i]++;
            if(hash[i]>max){
                max=hash[i];
            }
        }
        int ans=0;
        for(auto it: hash){
            if (it.second==max) ans+=it.second;
        }
        return ans;

    }
};