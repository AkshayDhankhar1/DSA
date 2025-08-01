class Solution {
public:
int mod=1e9+7;
long long power(long long x,long long n){
    if(n==0) return 1;
    long long half= power(x,n/2)%mod;
    long long result= (half*half)%mod;
    if(n%2==1){
        result=(x*result)%mod;
    }
    return  result;
}
    int countGoodNumbers(long long n) {
        long long result;
        if(n%2==0){
            result=((power(5,n/2)%mod )*(power(4,n/2)%mod))%mod; 
        } 
        if(n%2==1){
            result=((power(5,n/2 +1)%mod )*(power(4,n/2)%mod))%mod;
        }
        return (int) result;
    }
};