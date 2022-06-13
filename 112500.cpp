#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <deque>
#include <iomanip>

using namespace std;

int priority(const string &str) {
    if (str == "+" || str == "-") return 1;
    else if (str == "/" || str == "*") return 2;
    else if (str == "sin" || str == "cos" || str == "abs" || str == "sqrt") return 3;
    else if (str == "(" || str == ")") return 0;
}



int main() {
    ifstream inp("input.txt");
    ofstream out("output.txt");
    deque<string> stack, str;
    deque<double> digits;
    string in;
    string temp;
    double digitTemp1 = 0, digitTemp2 = 0;
    inp >> in;

    inp.close();


    for (int i = 0; i < in.size();i++)
    {
        if (isdigit(in[i])){
            do {
                temp.push_back(in[i]), i++;
            } while (isdigit(in[i]));
            i--;
            str.push_back(temp);
            temp.clear();
        }
        else if (isalpha(in[i])) {
            do {
                temp.push_back(in[i]), i++;
            } while (isalpha(in[i]));
            i--;
            if (temp == "sin" || temp == "cos" || temp == "abs" || temp == "sqrt") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    str.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(temp);

            }
            else
                str.push_back(temp);
            temp.clear();
        }
        else {
            temp.push_back(in[i]);
            if (temp == "(") {
                stack.push_back(temp);
            }
            else if (temp == ")") {
                while (stack[stack.size() - 1] != "(") {
                    str.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            } else if (temp == "+") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    str.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(temp);
            } else if (temp == "-") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    str.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(temp);
            } else if (temp == "*") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    str.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(temp);
            } else if (temp == "/") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    str.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(temp);
            }
            temp.clear();

        }
    }
    while (!stack.empty()) {
        str.push_back(stack.back());
        stack.pop_back();
    }

    while (!str.empty()){

        if (isdigit(str.front()[0])) {
            int iter = 0;
            digitTemp1 = 0;
            while (isdigit(str.front()[iter]) && iter < str.front().size()){
                digitTemp1 = digitTemp1 * 10 + (str.front()[iter] - '0');
                iter++;
            }
            digits.push_back(digitTemp1);
            digitTemp1 = 0;
            str.pop_front();
        }
        else if (str.front() == "+"){
            digitTemp1 = digits.back(), digits.pop_back();
            digitTemp2 = digits.back(), digits.pop_back();
            digits.push_back(digitTemp2+digitTemp1);
            str.pop_front();
        }
        else if (str.front() == "-"){
            digitTemp1 = digits.back(), digits.pop_back();
            digitTemp2 = digits.back(), digits.pop_back();
            digits.push_back(digitTemp2-digitTemp1);
            str.pop_front();

        }
        else if (str.front() == "*"){
            digitTemp1 = digits.back(), digits.pop_back();
            digitTemp2 = digits.back(), digits.pop_back();
            digits.push_back(digitTemp2*digitTemp1);
            str.pop_front();

        }
        else if (str.front() == "/"){
            digitTemp1 = digits.back(), digits.pop_back();
            digitTemp2 = digits.back(), digits.pop_back();
            digits.push_back(digitTemp2/digitTemp1);
            str.pop_front();
        }
        else if (str.front() == "sin"){
            digits.back() = sin(digits.back());
            str.pop_front();
        }
        else if (str.front() == "cos"){
            digits.back() = cos(digits.back());
            str.pop_front();
        }
        else if (str.front() == "sqrt"){
            digits.back() = sqrt(digits.back());
            str.pop_front();
        }
        else if (str.front() == "abs"){
            digits.back() = abs(digits.back());
            str.pop_front();
        }
    }

    out << fixed << setprecision(3) << digits.front();

    out.close();
    return 0;
}
