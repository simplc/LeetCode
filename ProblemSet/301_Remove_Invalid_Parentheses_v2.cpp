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
                �������ſ�ƥ���ַ�������Ϊn ��tarLen = n���������Դ˲��� q �������µĴ������ȸ�С�ģ�
                    Ŀǰ q ��ֻ�г���Ϊ  >=n �Ĵ�
            */

            if (tarLen == now.length()) continue;

            for (int i = 0; i < now.length(); ++i) {
                if (!(now[i] == '(' || now[i] == ')')) continue;

                /*
                    ����������ͬ�����Ų���Ҫ����ɾ��һ��
                */
                if (i > 0 && now[i] == now[i - 1]) continue;

                tmp = now;
                tmp.erase(i, 1);

                /*
                    ���ܲ��������ظ�����Ϊ�����ظ����Ѿ������Ĵ�����һ��Set��
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
