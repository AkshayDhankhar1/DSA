class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1!=n2) return false;
        if(n1==1 && n2==1){
            return s1==s2;
        }
        string odd1="";
        string odd2="";
        for(int i=0;i<n1;i++){
            if(i%2==1){
                odd1+=s1[i];
            }
        }
        for(int i=0;i<n2;i++){
            if(i%2==1){
                odd2+=s2[i];
            }
        }
        sort(odd1.begin(),odd1.end());
        sort(odd2.begin(),odd2.end());
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1!=s2) return false;
        if(odd1==odd2) return true;
        return false;
    }
};