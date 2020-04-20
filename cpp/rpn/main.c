#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

class calculator
{
public:
    int calcFormula(string formula);
    string toRpn(string formula);
};

// 逆ポーランド記法の数式から解を求める
int calculator::calcFormula (string formula)
{
    stack<int> stack;
    int result;
    for (int i = 0; i < formula.size(); i++)
    {
        char f = formula[i];

        if (isdigit(f))
        {
            stack.push(f - '0');
        }
        else if (f == '=')
        {
            result = stack.top();
            stack.pop();
            break;
        }
        else
        {
            int op1 = stack.top();
            stack.pop();
            int op2 = stack.top();
            stack.pop();

            if (f == '+')      stack.push(op2 + op1);
            else if (f == '-') stack.push(op2 - op1);
            else if (f == '*') stack.push(op2 * op1);
            else if (f == '/')
            {
                if (op1 == 0)
                {
                    cerr << "Divided 0" << endl;
                    exit(EXIT_FAILURE);
                }
                stack.push(op2 / op1);
            }
        }
    }
    return result;
}

// 通常の数式から逆ポーランド記法の数式への変換
string calculator::toRpn(string formula)
{
    string buffer = "";
    stack<int> stack;

    for (int i = 0; i < formula.size(); i++)
    {
        char f = formula[i];

        // 数字の場合
        if (isdigit(f))
        {
            buffer += f;

        }
        // 閉じ括弧の場合
        else if (f == ')')
        {
            while (true) {
                if (stack.top() == '(')
                {
                    stack.pop();
                    break;
                }
                else if (stack.top() == ')')
                {
                    stack.pop();
                }
                else
                {
                    buffer += stack.top();
                    stack.pop();
                }
            }
        }
        // 括弧の場合
        else if (f == '(')
        {
            stack.push(f);
        }
        // 等価演算子の場合
        else if (f == '=')
        {
            while (true)
            {
                if (stack.empty()) break;
                buffer += stack.top();
                stack.pop();
            }
            buffer += f;
            break;
        }
        // 演算子(スタックが空)の場合
        else if (stack.empty())
        {
            stack.push(f);
        }
        // スタックの一番上の演算子よりも手元にある演算子の優先順位が低い場合
        else if ((stack.top() == '*' || stack.top() == '/') && (f == '+' || f == '-'))
        {
            buffer += stack.top();
            stack.pop();
            stack.push(f);
        }
        // スタックの一番上の演算子と手元にある演算子の優先順位が同じ場合
        else if (((stack.top() == '*' || stack.top() == '/') && (f == '*' || f == '/')) || ((stack.top() == '+' || stack.top() == '-') && (f == '+' || f == '-')))
        {
            buffer += stack.top();
            stack.pop();
            stack.push(f);
        }
        // その他
        else
        {
            stack.push(f);
        }
    }
    return buffer;
}

string trim (string str)
{
    string buffer = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ') continue;
        buffer += str[i];
    }
    return buffer;
}

int main ()
{
    cout << ">>>> hello!" << endl;
    while (true) {
        string formula;
        cout << "Input: ";
        getline(cin, formula);

        if (formula == "bye")
        {
            cout << ">>>> bye!" << endl;
            exit(EXIT_SUCCESS);
        }

        calculator* c = new calculator();

        formula = trim(formula);
        formula = c->toRpn(formula);
        cout << "Output: " << c->calcFormula(formula) << endl;;
    }
}