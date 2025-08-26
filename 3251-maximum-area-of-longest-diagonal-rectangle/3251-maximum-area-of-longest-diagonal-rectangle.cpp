class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int sqr=0;
        int area=0;
        for(int i=0;i<dimensions.size();i++){
            int sq=dimensions[i][0]*dimensions[i][0]+dimensions[i][1]
*dimensions[i][1];
            int ar=dimensions[i][1]*dimensions[i][0];
            if(sq>sqr){
                sqr=sq;
                area=ar;
            }
            else if(sq==sqr){
                area=max(ar,area);
            }
        }
        return area;
    }
};