class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        for(int i=0;i<beginWord.size();i++){
            string s=beginWord;
            for(char c='a' ; c<='z';c++){
                s[i]=c;
                if(st.find(s)!=st.end()){
                    q.push({s,2});
                    st.erase(s);
                }
            }
        }
        while(!q.empty()){
            int steps=q.front().second;
            string s=q.front().first;
            q.pop();
            if(s==endWord) return steps;
            for(int i=0;i<s.size();i++){
                string original=s;
                for(char c='a' ; c<='z';c++){
                    s[i]=c;
                    if(st.find(s)!=st.end()){
                        q.push({s,steps+1});
                        st.erase(s);
                    }
                    s=original;
                }
            }
        }
        return 0;
    }
};