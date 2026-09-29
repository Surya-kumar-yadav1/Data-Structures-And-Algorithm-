/*
Problem: 1807. Evaluate the Bracket Pairs of a String
Difficulty: Medium
Topic: Hash Table, String
Approach:
- Use an unordered map `d` to pre-store the key-value pairs from the `knowledge` list for O(1) lookups.
- Iterate through the string `s` and append non-bracket characters directly to the result.
- When an opening parenthesis `(` is encountered, find the matching closing parenthesis `)` to extract the key substring.
- Check if the key exists in the map: if found, append its corresponding value; otherwise, append `?`.
- Advance the loop index to the position of the closing parenthesis to skip processing the key characters again.
Time Complexity: O(n + m), where n is the length of string s and m is the total number of characters across all key-value pairs in knowledge.
Space Complexity: O(m) to store the dictionary map of knowledge pairs.
*/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> d;
        for (auto& k : knowledge)
            d[k[0]] = k[1];

        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                int j = s.find(")", i + 1);
                auto t = s.substr(i + 1, j - i - 1);
                res += d.count(t) ? d[t] : "?";
                i = j;
            } else
                res += s[i];
        }

        return res;
    }
};
