class Solution {
public:
    int candy(vector<int>& ratings) {
        
        if(ratings.size()==0) return 0;
        if(ratings.size()==1) return 1;
        int sum=0;
        vector<int> lefty(ratings.size(),1);
        vector<int> righty(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                lefty[i]=lefty[i-1]+1;
            }
            else{
               continue;
            }
        }
        for(int i=ratings.size()-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                righty[i-1] = righty[i ] + 1;;
            }
            else{
                continue;
            }
        }
        for(int i=0;i<ratings.size();i++){
            int cnt=0;
            cnt=max(lefty[i],righty[i]);
            sum+=cnt;
        }
        return sum;
    }
};