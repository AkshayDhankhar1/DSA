class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==0) return 0;
        int past=1;
        int past2=1;
        int cur=0;
        for(int i=2;i<=n;i++){
            cur=past+past2;
            past2=past;
            past=cur;
        }        
        return past;
    }
};