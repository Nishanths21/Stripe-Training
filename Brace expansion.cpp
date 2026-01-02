#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> expand(string s) {
        vector<vector<string>> groups;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '{') {
                int j = i + 1;
                vector<string> group;
                while (j < n && s[j] != '}') {
                    string token;
                    while (j < n && s[j] != ',' && s[j] != '}') {
                        token += s[j++];
                    }
                    group.push_back(token);
                    if (j < n && s[j] == ',') j++;
                }
                sort(group.begin(), group.end());
                groups.push_back(group);
                i = j; 
            } else {
                string token;
                while (i < n && s[i] != '{') {
                    token += s[i++];
                }
                groups.push_back({token});
                i--; 
            }
        }
        
        vector<string> ans;
        dfs(groups, 0, "", ans);
        return ans;
    }

private:
    void dfs(const vector<vector<string>>& groups, int index, string current, vector<string>& ans) {
        if (index == groups.size()) {
            ans.push_back(current);
            return;
        }
        
        for (const string& str : groups[index]) {
            dfs(groups, index + 1, current + str, ans);
        }
    }
};