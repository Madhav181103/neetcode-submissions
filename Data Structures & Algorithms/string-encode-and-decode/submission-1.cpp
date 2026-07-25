class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded = "";
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            int size = strs[i].size();
            string sz = to_string(size);
            sz += '#';
            encoded += sz;
            for (int j = 0; j < size; j++) {
                encoded += strs[i][j];
            }
        }
        return encoded;
    }

    vector<string> decode(string s) {
         vector<string> ans;
    int i = 0;

    while (i < s.size()) {

        string len = "";
        while (s[i] != '#') {
            len += s[i];
            i++;
        }

        int size = stoi(len);
        i++; 

        string word = "";
        while (size--) {
            word += s[i++];
        }

        ans.push_back(word);
    }

    return ans;
    }
};
