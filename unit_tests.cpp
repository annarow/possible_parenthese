#include "gtest/gtest.h"
#include "possible_parentheses.h"

void showResult(std::list<std::string> & result) {
    for (std::list<std::string>::iterator i = result.begin(); i!=result.end(); ++i) {
        printf("%s\n", (*i).c_str());
    }
};

TEST(test_recursive, 1) {
    std::list<std::string> result;
    possibleParenthesis(1, result);
    std::list<std::string> test;
    test.push_back("{}");
    ASSERT_TRUE(equality(test, result));
}

TEST(test_recursive, 2) {
    std::list<std::string> result;
    possibleParenthesis(2, result);
    std::list<std::string> test;
    test.push_back("{}{}");
    test.push_back("{{}}");
    ASSERT_TRUE(equality(test, result));
}

TEST(test_recursive, 3) {
    std::list<std::string> result;
    possibleParenthesis(3, result);
    std::list<std::string> test;
    test.push_back("{}{}{}");
    test.push_back("{}{{}}");
    test.push_back("{{}}{}");
    test.push_back("{{}{}}");
    test.push_back("{{{}}}");
    ASSERT_TRUE(equality(test, result));
}

TEST(test_recursive, 0){
    std::list<std::string> result;
    possibleParenthesis(0, result);
    std::list<std::string> test;
    ASSERT_TRUE(equality(test, result));
}
// and more
