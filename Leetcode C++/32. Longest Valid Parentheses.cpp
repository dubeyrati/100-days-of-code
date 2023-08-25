class Solution {
public:
    int longestValidParentheses(string s) {
        int ct = 0;
        vector<int> v;
        v.push_back(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]=='(')
            {
                v.push_back(i);
            }
            else
            {
                if (v.size()==1)
                {
                    v[0]=i;
                }
                else
                {
                    v.pop_back();
                    ct = max(ct, i-v[v.size()-1]);
                }
                
                
            }
            
            
        }
        return ct;
    }
};