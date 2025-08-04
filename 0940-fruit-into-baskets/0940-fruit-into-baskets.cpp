class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int pmax=0;
        int l=0;
        int r=0;
        unordered_map<int,int> hash;
        while(r<fruits.size()){
            hash[fruits[r]]++;
            while(hash.size()>2){
                hash[fruits[l]]--;
                if(hash[fruits[l]]==0){
                    hash.erase(fruits[l]);
                }
                l++;
            }
            pmax=max(pmax,r-l+1);
            r++;
        }
        return pmax;
        
    }
};