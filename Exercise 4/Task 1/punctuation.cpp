#include <iostream>
#include <vector>
#include <regex>
#include <iterator>

// A program that removes spaces before punctuation marks and adds spaces after punctuation marks if missing
std::string fixPunctuation(const std::string& str) {
    const std::regex rgx_pattern("\\s*([.,;-?!:])\\s*");          // $1 applies to the expression in parentheses
    std::string temp;
    temp.reserve(str.size());
    regex_replace(std::back_insert_iterator<std::string>(temp), str.cbegin(), str.cend(), rgx_pattern, "$1 ");
    return temp;
}
int main()
{
    std::string str;
    std::cout << "Enter a string : ";
    std::getline(std::cin, str);
    str = fixPunctuation(str);
    std::cout << std::endl << str;
}

