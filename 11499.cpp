#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
    vector<string> stack;
    string in;
    string temp;

    inp >> in;

    inp.close();


    for (int i = 0; i < in.size();i++)
    {
        if (isdigit(in[i])){
            while (isdigit(in[i])){
                out << in[i];
                i++;
            }
            i--;
            out << " ";
        }
        else if (isalpha(in[i]) || in[i] == '_') {

            do {
                temp.push_back(in[i]), i++;
            }while(isalpha(in[i]) || isdigit(in[i]) || in[i] == '_');
            i--;
            if(temp == "sin" || temp == "cos" || temp == "abs" || temp == "sqrt") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    out << stack.back() << " ";
                    stack.pop_back();
                }
                stack.push_back(temp);

            }
            else
                out << temp << " ";
            temp.clear();
        }
        else {
            temp.push_back(in[i]);
            if (temp == "(") {
                stack.push_back(temp);
            }
            else if (temp == ")") {
                while (stack[stack.size() - 1] != "(") {
                    out << stack.back() << " ";
                    stack.pop_back();
                }
                stack.pop_back();
            } else if (temp == "+") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    out << stack.back() << " ";
                    stack.pop_back();
                }
                stack.push_back(temp);
            } else if (temp == "-") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    out << stack.back() << " ";
                    stack.pop_back();
                }
                stack.push_back(temp);
            } else if (temp == "*") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    out << stack.back() << " ";
                    stack.pop_back();
                }
                stack.push_back(temp);
            } else if (temp == "/") {
                while (!stack.empty() && priority(temp) <= priority(stack.back())) {
                    out << stack.back() << " ";
                    stack.pop_back();
                }
                stack.push_back(temp);
            }
            temp.clear();

        }
    }

    while(!stack.empty()) {
        out << stack[stack.size() - 1] << " ";
        stack.pop_back();
    }

    out.close();
    return 0;
}
