class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else if (st.empty() && (c == ']' || c == '}' || c == ')'))
                return false;
            else if (c == ']' || c == '}' || c == ')') {
                if (c == ']' && st.top() != '[')
                    return false;
                else if (c == '}' && st.top() != '{')
                    return false;
                else if (c == ')' && st.top() != '(')
                    return false;
                else
                    st.pop();
            }
        }
        if(st.empty())return true;
        else return false;
    }
};
