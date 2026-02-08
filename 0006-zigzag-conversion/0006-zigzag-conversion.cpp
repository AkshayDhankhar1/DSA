class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        int t=0;
        if(n==1 || numRows==1) return s;
        vector<vector<char>> mat(numRows,vector<char>(n,'_'));
        int i=0;
        int j=0;
        bool down=true;
        while(t<n){
            mat[i][j]=s[t];
            if(down){
                if(i==numRows-1){
                    down=false;
                    i--;
                    j++;
                }
                else{
                  i++;  
                }
            }
            else{
                if(i==0){
                    down=true;
                    i++;
                }
                else{
                    i--;
                    j++;
                }
            }
            t++;
        }
        string ans;
        for(int x=0;x<mat.size();x++){
            for(int y=0;y<mat[0].size();y++){
                if(mat[x][y]!='_'){
                    ans.push_back(mat[x][y]);
                }
            }
        }
        return ans;
    }
};