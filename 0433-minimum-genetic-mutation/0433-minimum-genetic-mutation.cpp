class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n=bank.size();
        vector<bool> visited(n,false);
        queue<string> q;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<8;j++){
                if(startGene[j]!=bank[i][j])c++;
            }
            if(c==1){
                q.push(bank[i]);
                visited[i]=true;
            }
        }
        int ans=1;
        while(!q.empty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                string st=q.front();
            q.pop();
            if(st==endGene) return ans;
            for(int i=0;i<n;i++){
                if(visited[i]) continue;
            int c=0;
            for(int j=0;j<8;j++){
                if(st[j]!=bank[i][j])c++;
            }
            if(c==1){
                q.push(bank[i]);
                visited[i]=true;
            }
        }
            }
        ans++;

        }
        return -1;
    }
};