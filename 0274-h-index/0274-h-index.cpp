class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int ind=INT_MIN;
        for(int i=0;i<n;i++){
            if(citations[i]>=n-i){
                ind=max(n-i,ind);
            }
            if(n-i>=citations[i]){
                ind=max(citations[i],ind);
            }
        }
        return ind;
    }
};