// source: https://leetcode.com/problems/remove-invalid-parentheses
// difficulty: Hard
// author: simplc

/*
Description:
    Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

    Note: The input string may contain letters other than the parentheses ( and ).

Examples:
    "()())()" -> ["()()()", "(())()"]
    "(a)())()" -> ["(a)()()", "(a())()"]
    ")(" -> [""]
*/

/*
    Result: AC
*/

class Solution {
public:

    bool valid(string s){
        int res = 0;
        for (auto ch : s) {
            if (ch == '(') ++res;
            else if (ch == ')') {
                if (res == 0) return false;
                else --res;
            }
        }

        return res == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        if (valid(s)){
            vector<string> res;
            res.push_back(s);
            return res;
        }

        set<string> res;
        /*
            Here is the optimization.
                Avoid the duplicated strings.
        */
        set<string> visited;

        queue<string> q;
        q.push(s);

        string now, tmp;
        int tarLen = -1;

        while (!q.empty()) {
            now = q.front();
            q.pop();

            /*
                假设最优可匹配字符串长度为n （tarLen = n），可以自此不向 q 中增加新的串（长度更小的）
                    目前 q 中只有长度为  >=n 的串
            */

            if (tarLen == now.length()) continue;

            for (int i = 0; i < now.length(); ++i) {
                if (!(now[i] == '(' || now[i] == ')')) continue;

                /*
                    相邻两个相同的括号不需要重新删除一次
                */
                if (i > 0 && now[i] == now[i - 1]) continue;

                tmp = now;
                tmp.erase(i, 1);

                /*
                    可能产生大量重复串，为避免重复将已经检查过的串放入一个Set中
                */
                if (visited.find(tmp) != visited.end()) continue;
                visited.insert(tmp);

                if (valid(tmp)) {
                    if (tarLen == -1) tarLen = tmp.length();
                    res.insert(tmp);
                }

                else q.push(tmp);

            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
