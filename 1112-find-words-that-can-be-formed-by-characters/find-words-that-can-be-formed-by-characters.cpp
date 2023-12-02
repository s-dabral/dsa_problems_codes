class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        vector<int> charCount(26, 0);
        for (char c : chars) {
            charCount[c - 'a']++;
        }
        for (const string& word : words) {
            vector<int> tempCount(charCount);
            bool valid = true;
            for (char c : word) {
                if (tempCount[c - 'a'] > 0) {
                    tempCount[c - 'a']--;
                } else {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result += word.size();
            }
        }
        return result;
    }
};