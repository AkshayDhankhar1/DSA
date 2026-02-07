class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0;
        int totalcost=0;
        for(int i=0;i<n;i++){
            totalcost+=cost[i];
            totalgas+=gas[i];
        }
        if(totalcost>totalgas) return -1;
        int ans=0;
        int tank=0;
        for(int i=0;i<n;i++){
            tank+=gas[i];
            tank-=cost[i];
            if(tank<0){
                tank=0;
                ans=i+1;
            }
        }
        return ans;
    }
};