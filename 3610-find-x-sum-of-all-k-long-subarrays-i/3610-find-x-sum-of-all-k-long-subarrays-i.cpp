class Solution {
public:
int xsum(vector<int> num,int x){
    int sum=0;
    unordered_map<int,int> hash;
    for(int c:num){
        hash[c]++;
    }
    vector<pair<int,int>> frq(hash.begin(),hash.end());
    sort(frq.begin(),frq.end(),[](pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second) return a.first>b.first;
        return a.second>b.second;
    });
    if(frq.size()<x){
        for(int i=0;i<frq.size();i++){
            sum+=frq[i].first*frq[i].second;
        }
    }
    else{
        for(int i=0;i<x;i++){
        sum+=frq[i].first*frq[i].second;
    }
    }
    return sum;

}   
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        for(int i=0;i<nums.size()-k+1;i++){
            vector<int> num(nums.begin()+i,nums.begin()+i+k);
            ans.push_back(xsum(num,x));
        }
        return ans;
    }
};