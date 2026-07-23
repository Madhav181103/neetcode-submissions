class Solution {
public:
    string minWindow(string s, string t) {
         if (s.size() < t.size()) return "";

        int m = s.size();
        int n = t.size();
        if (m < n)
            return "";
        string ans = "";
        vector<int> need(256, 0);
        for (char c : t) {
            need[c]++;
        }
        vector<int>window(256,0);
        int minlen=INT_MAX;
        int matched=0;
        int l=0;
        int start=0;
        int left=0;
        for(int right = 0 ;right<s.size();right++){
        window[s[right]]++;
        if(window[s[right]]<=need[s[right]])matched++;

        while(matched==t.size()){
            if(right-left+1<minlen){
                minlen=right-left+1;
                start=left;
            }
            window[s[left]]--;
            if(window[s[left]]<need[s[left]])matched--;
            left++;
        }
        }
        if (minlen == INT_MAX) return "";
        return s.substr(start,minlen);
    }
};
