class Solution {
public:
    int romanToInt(string s) {
        int cnt=0;
        unordered_map<char,int>  hash;
        hash['I']=1;
        hash['V']=5;
        hash['X']=10;
        hash['L']=50;
        hash['C']=100;
        hash['D']=500;
        hash['M']=1000;
        cnt+=hash[s[0]];
        for(int i=1;i<s.size();i++){
            if(hash[s[i-1]]<hash[s[i]]) {cnt+=hash[s[i]];
            cnt-=2*hash[s[i-1]];}
            else cnt+=hash[s[i]];
        }
        return cnt;
    }
};
