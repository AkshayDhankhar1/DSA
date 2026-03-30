class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1!=n2) return false;
        if(n1==1 && n2==1){
            return s1==s2;
        }
        vector<int> odd1(26,0),even1(26,0),odd2(26,0),even2(26,0);
        for(int i=0;i<n1;i++){
            if(i%2==0){
                even1[s1[i]-'a']++;
            }
            else odd1[s1[i]-'a']++;
        }
        for(int i=0;i<n2;i++){
            if(i%2==0){
                even2[s2[i]-'a']++;
            }
            else odd2[s2[i]-'a']++;
        }
        return (odd1==odd2 && even1==even2);
    }
};