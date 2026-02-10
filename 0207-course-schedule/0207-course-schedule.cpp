class Solution {
    private: 
    bool dfs(vector<vector<int>> &nums,vector<bool> &visited,vector<bool> &pathvisited, int node){
        visited[node]=true;
        pathvisited[node]=true;
        for(int it: nums[node]){
            if(!visited[it] && dfs(nums,visited,pathvisited,it)) return true;
            else if(pathvisited[it]) return true;
        }


        pathvisited[node]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nums(numCourses);
        int n=prerequisites.size();
        if(n<=1) return true;
        for(int i=0;i<n;i++){
            nums[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> pathvisited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]&& dfs(nums,visited,pathvisited,i)) return false;
        }
        return true;
    }
};