class Solution {
public:
bool noti(int n){
    if(n==0) return false;
    while(n > 0){
        if(n%10 ==0 ){
            return false;
        }
        n=n/10; 
    }
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(noti(i) && noti(n-i)) {
                ans={i,n-i};
                break;
                }
        }
        return ans;
    }
};