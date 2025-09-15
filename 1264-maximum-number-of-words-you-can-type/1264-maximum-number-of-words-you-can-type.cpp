class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>broken(brokenLetters.begin(),brokenLetters.end());
        bool isbroken=false;
        int count=0;
        for(int i=0;i<text.size();i++){
            if(text[i]!=' '){
                if(broken.find(text[i])!=broken.end()){
                    isbroken=true;
                }
            }
            if(text[i]==' '|| i==text.size()-1){
                if(!isbroken) count++;
                isbroken=false;
            }

        }
        return count;
    }
};