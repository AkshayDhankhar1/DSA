class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int r=height.size()-1,l=0;
        while(l<r){
            area=max(area,min(height[l],height[r])*(r-l));
            if(height[l]>height[r])r--;
            else l++;
        }
        return  area;
        
    }
};