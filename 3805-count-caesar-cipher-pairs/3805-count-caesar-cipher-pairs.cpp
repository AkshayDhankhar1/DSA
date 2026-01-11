class Solution {
public:
string conv(string word){
    int m=word.size();
    string st=word;
    while(st[0]!='a'){
        for(int i=m-1;i>=0;i--){
            if(st[i]=='a'){
                st[i]='z';
            }else{
            st[i]--;
            }
        }
    }
    return st;
}
    long long countPairs(vector<string>& words) {
        long long ans=0;
        int n=words.size();
        unordered_map<string,long long> hash;
        for(int i=0;i<n;i++){
            string st=conv(words[i]);
            if(hash.count(st)){
                ans+=hash[st];
            }
            hash[st]++;
        }
        return ans;
    }
};