class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hash;
        for(char c: s){
            hash[c]++;
        }
        vector<pair<char,int>> arr(hash.begin(),hash.end());
        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        string st="";
        for(auto it: arr){
            st.append(it.second,it.first);
        }
        
        return st;
    }
};