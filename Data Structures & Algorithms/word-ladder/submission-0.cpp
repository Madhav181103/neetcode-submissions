class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return 0;

        if (beginWord == endWord)
            return 1;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int j = 0; j < size; j++) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level;

                for (int i = 0; i < word.size(); i++) {
                    char c = word[i];

                    for (char x = 'a'; x <= 'z'; x++) {
                        if (x == c)
                            continue;

                        word[i] = x;

                        if (st.count(word)) {
                            st.erase(word);
                            q.push(word);
                        }
                    }

                    word[i] = c;
                }
            }

            level++;
        }

        return 0;
    }
};