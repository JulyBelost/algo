#include <iostream>
#include <stack>
#include <string>

using namespace std;

char a[2][3] = {{'(', '[', '{'}, {')', ']', '}'}};

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int getErrorPosition(stack <Bracket> & brackets, string s) {
    for (int pos = 0; pos < s.length(); ++pos) {
        char c = s[pos];

        for(int i = 0; i < 3; ++i){
            if (c == a[0][i]) {
                brackets.push(Bracket(c, pos));
            }
            if (c == a[1][i]) {
                if(!brackets.empty() && brackets.top().Matchc(c) ) {
                    brackets.pop();
                } else {
                    return pos + 1;
                }
            }
        }
    }

    int ans = -1;

    while(!brackets.empty()) {
            Bracket br = brackets.top();
            ans = br.position;
            brackets.pop();
    }

    return ans + 1;
}

int main() {
    string text;
    getline(cin, text);

    stack <Bracket> opening_brackets_stack;
    int result = getErrorPosition(opening_brackets_stack, text);

    if(result) {
        cout << result << "\n";
    } else {
        cout << "Success\n";
    }
    return 0;
}
