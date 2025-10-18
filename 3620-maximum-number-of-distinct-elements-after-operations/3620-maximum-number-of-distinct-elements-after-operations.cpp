class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort (nums.begin(),nums.end());
        unordered_map<int,int> hash;
        int count=0;
        int last=INT_MIN;
        for (int x: nums){
            int val=max(last+1,x-k);
            if(val<=x+k){
                count++;
                last=val;
            }
        }
        return count;
        
    }
};