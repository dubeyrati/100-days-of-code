class Solution {
public:
    string reverseWords(string s) {
        
        int i = 0, j = s.size() - 1;
        while (i <= j && s[i] == ' ') i++;   
        while (j >= i && s[j] == ' ') j--;   
        s = s.substr(i, j - i + 1);         
        
        vector<string> words;                
        stringstream ss(s);                  
        string word;
        while (ss >> word) {                 
            words.push_back(word);          
        }

        string out = "";

        for (int i = words.size() - 1; i > 0; i--) {
            out += words[i] + " ";
        }

        return out + words[0];              
    }
};
