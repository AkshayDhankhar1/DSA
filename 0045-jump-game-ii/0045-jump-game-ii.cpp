class Solution {
public:
    int jump(vector<int>& nums) {
        int r=0;
        int jmp=0;
        int l=0;
        while(r<nums.size()-1){
            int cnt=0;
            for(int i=l;i<=r;i++){
                cnt=max(cnt,i+nums[i]);
            }
            l=r+1;
            r=cnt;
            jmp++;
        }
        return jmp;
        
    }
};