class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int m=potions.size();
        int n=spells.size();
        int i=0;
        int j=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int pt=m;
            int low=0;
            int high=m-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(1ll*potions[mid]*spells[i]>=success){
                    pt=mid;
                    high=mid-1;
                }
                else if(1ll*potions[mid]*spells[i]<success){
                    low=mid+1;
                }
            }
            ans.push_back(m-pt);
        }
        return ans;
    }
};