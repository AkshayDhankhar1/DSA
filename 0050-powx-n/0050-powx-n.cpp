class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        double half;
        if(N<0){
            x=1/x;
            N=-N;
        }
        if(N == 0) return 1;
        if(N%2 == 0) {
            half = myPow(x*x,N/2);
            
        }
        if(N%2 == 1){
            N--;
            half=x*myPow(x,N);
            
        }
        return half;
        
    }
};