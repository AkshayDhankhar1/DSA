class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        if(digits[n-1]!=9){
            digits[n-1]+=1;
            return digits;
        }
        else {
            // digits[n-1]=0;
            int ind=n-1;
            while(carry==1 && ind>=0){
                if(digits[ind]!=9){
                    digits[ind]+=1;
                    carry=0;
                    return digits;
                }
                else {
                    digits[ind]=0;

                }
                ind--;
            }
            if(ind<0 && carry==1){
                digits.push_back(0);
                digits[0]=1;
                return digits;
            }
            return digits;
        }
    }
};