//https://leetcode.com/problems/unique-email-addresses/description/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string email: emails)
        {
            string temp="";
            for(char &c: email)
            {
                if(c=='+'||c=='@')break;
                if(c=='.')
                    continue;
                
                temp+=c;
            }

            
            temp+=email.substr(email.find('@'));
            
            st.insert(temp);
        }
        
        return st.size();
        
    }
};
