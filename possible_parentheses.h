#include <list>
#include <iostream>
#include <vector>

# define MAX_SIZE 100
// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n


void _possibleParenthesis(int pos, int n, int open, int close, std::list<std::string> & result)
{
    static char str[MAX_SIZE];

    if(close == n) {
        //add to array
        result.push_back(str);
        //printf("%s\n", str);

        return;
    }

    if(open > close) {
        str[pos] = '}';
        _possibleParenthesis(pos+1, n, open, close+1, result);
    }

    if(open < n) {
        str[pos] = '{';
        _possibleParenthesis(pos+1, n, open+1, close, result);
    }
}

void possibleParenthesis(int n, std::list<std::string> & result)
{
    if(n > 0){
        _possibleParenthesis(0, n, 0, 0, result);
    }
    else{
        return;
    }
    // homework
}

bool equality(std::list<std::string> & checker, std::list<std::string> & answer) {
    if (checker.size() != answer.size()) {
        return false;
    }
    while (checker.empty() == false) {

        if (checker.front() == answer.front()) {
            // Pop top of both stacks
            checker.pop_front();
            answer.pop_front();
        }
        else {
            return false;
        }
    }
    return true;
}
