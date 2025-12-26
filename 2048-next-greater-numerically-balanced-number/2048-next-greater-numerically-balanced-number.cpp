class Solution {
public:
    int nextBeautifulNumber(int n) {
        int ans=0;
        for(int i=n+1;;i++){
            string st=to_string(i);
            vector<int> inst(10,0);
            for(char c:st){
                inst[c-'0'] ++;
            }
            int broke=0;
            for(int i=0;i<inst.size();i++){
                if(inst[i]!=0&&inst[i]!=i){
                    broke=1;
                    break;
                }
            }
            if(broke==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};