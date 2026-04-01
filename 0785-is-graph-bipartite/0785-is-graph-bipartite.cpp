class Solution {
    private : 
    bool find(int i,vector<vector<int>>& graph,int col,vector<int>& color){
        queue<int> q;
        q.push(i);
        color[i]=col;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<graph[node].size();j++){
                if(color[graph[node][j]]==-1){
                    q.push(graph[node][j]);
                    color[graph[node][j]]=!color[node];
                }
                else if(color[graph[node][j]]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(find(i,graph,0,color)==false) return false;
            }
        }
        return true;
    }
};