class Solution {
public:
bool isval(string a){
            if(a.size()==0) return false;
            for(char c:a){
                if(!isalnum(c) && c!='_') return false;
            }
            return true;
        }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        vector<string> ans;
        for(int i=0;i<code.size();i++){
            if(businessLine[i]=="electronics"||businessLine[i]=="grocery"||businessLine[i]=="pharmacy" || businessLine[i]=="restaurant"){
                if(businessLine[i]=="electronics") businessLine[i]="0";
                else if(businessLine[i]=="grocery") businessLine[i]="1";
                else if(businessLine[i]=="pharmacy")businessLine[i]="2";
                else businessLine[i]="3";
            }
            else businessLine[i]="7";
        }
        for(int i=0;i<code.size();i++){
            if(!isActive[i]) {
                businessLine[i]="7";
                continue;}
            else{
                if(!isval(code[i])) {
                    businessLine[i]="7";
                    continue;
                }

            }
        }
        vector<pair<pair<string,string>,string>> sol(code.size());
        for(int i=0;i<code.size();i++){
            sol[i].first.first=businessLine[i];
            sol[i].first.second=code[i];
            sol[i].second=isActive[i];
        }
        sort(sol.begin(),sol.end(),[&](const pair<pair<string,string>,string>&a,const pair<pair<string,string>,string>&b){
            if(a.first.first!=b.first.first){
                return a.first.first<b.first.first;
            }
            else return a.first.second<b.first.second;
        });
        for(int i=0;i<code.size();i++){
            if(sol[i].first.first!="7"){
                ans.push_back(sol[i].first.second);
            }
            else break;
        }
        return ans;
        
    }
};