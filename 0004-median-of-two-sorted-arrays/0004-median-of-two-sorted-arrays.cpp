class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num(nums1.begin(),nums1.end());
        num.insert(num.end(),nums2.begin(),nums2.end());
        sort(num.begin(),num.end());
        int n=num.size();
        if(n%2==1){
            return (double)(num[n/2]);
        }
        double a=num[n/2];
        double b=num[(n/2)-1];
        return (a+b)/2;
    }
};