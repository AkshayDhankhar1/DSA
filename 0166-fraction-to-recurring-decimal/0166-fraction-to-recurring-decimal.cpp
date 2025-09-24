class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        if(numerator==0) return "0";
        if(((long long)numerator<0) ^((long long) denominator<0)) ans+="-";
        long long n=llabs((long long )numerator);
        long long d=llabs((long long )denominator);
        ans+=to_string(n/d);
        long long rem= n%d; 
        if(rem==0) return ans;
        ans+=".";
        unordered_map<long long, int> hash;
        while(rem!=0){
            if(hash.count(rem)){
                ans.insert(hash[rem],"(");
                ans+=")";
                break;
            }
            hash[rem]=ans.size();
            rem*=10;
            ans+=to_string(rem/d);
            rem %= d;
        }
        return ans;

    }
};