class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowel;
        unordered_map<char,int> cons;
        for(char c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vowel[c]++;
            }
            else{
                cons[c]++;
            }
        }
        int max1=0;
        int max2=0;
        for(auto it : cons){
            if(it.second>max1) max1=it.second;
        }
        for(auto it : vowel){
            if(it.second>max2) max2=it.second;
        }
        return max1+max2;
    }
};