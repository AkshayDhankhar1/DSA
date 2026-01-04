class Solution {
public:
int ispossi(int n){
    int count=0;
    int sum=0;
    if(n==1) return 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            
            if(i*i==n) {sum+=i;count++;}
            else{
                count+=2;
                sum+=i;
                sum+=n/i;
            }
        }
    }

    if(count==4) return sum;
    return 0;
}
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int t=ispossi(nums[i]);
            if(t!=0) ans+=t;
        }
        return ans;
    }
};