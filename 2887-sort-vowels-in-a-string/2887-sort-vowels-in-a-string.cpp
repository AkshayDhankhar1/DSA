class Solution {
public:
    string sortVowels(string s) {
        string st;
        for(char c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ){
                st.push_back(c);
            }
        }
        sort(st.begin(),st.end(),greater<char>());
        string t;
        for(char c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ){
                t.push_back(st.back());
                st.pop_back();
            }
            else{
                t.push_back(c);
            }
        }
        return t;
        
    }
};