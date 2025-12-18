class Solution {
public:
vector<int> fpse(vector<int>&nums){
    stack<int>st;
    vector<int> ans(nums.size());
    for(int i=0;i<nums.size();i++){
        while(!st.empty()&&nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(st.empty()) ans[i]=-1;
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> fpge(vector<int>&nums){
    stack<int>st;
    vector<int> ans(nums.size());
    for(int i=0;i<nums.size();i++){
        while(!st.empty()&&nums[st.top()]<=nums[i]){
            st.pop();
        }
        if(st.empty()) ans[i]=-1;
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>fnse(vector<int>&nums){
    stack<int> st;
    vector<int> ans(nums.size());
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty()&&nums[st.top()]>nums[i]){
            st.pop();
        }
        if(st.empty()) ans[i]=nums.size();
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>fnge(vector<int>&nums){
    stack<int> st;
    vector<int> ans(nums.size());
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty()&&nums[st.top()]<nums[i]){
            st.pop();
        }
        if(st.empty()) ans[i]=nums.size();
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nge=fnge(nums);
        vector<int> pge=fpge(nums);
        vector<int> nse=fnse(nums);
        vector<int> pse=fpse(nums);
        long long small=0;
        long long large=0;
        for(int i=0;i<nums.size();i++){
            long long ls=i-pse[i];
            long long rs=nse[i]-i;
            long long lg=i-pge[i];
            long long rg=nge[i]-i;
            small+=nums[i]*ls*rs;
            large+=nums[i]*lg*rg;
        }
        return large-small;
    }
};