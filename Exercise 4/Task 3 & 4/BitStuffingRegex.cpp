#include <iostream>
#include <vector>
#include <regex>
#include <iterator>
// bit stuffing and unstuffing program
// bit stuffing : after 5 consecutive 1s, add a 0
// bit unstuffing reverses the process to the original string

std::string bitStuffing(const std::string& str) {
    const std::regex rgx_pattern("1{5}");          // $1 applies to the expression in parentheses
    std::string temp;
    temp.reserve(str.size());
    regex_replace(std::back_insert_iterator<std::string>(temp), str.cbegin(), str.cend(), rgx_pattern, "$&0");
    return temp;
}

std::string bitUnstuffing(const std::string& str) {
    const std::regex rgx_pattern("1{5}0");
    std::string temp;
    temp.reserve(str.size());
    regex_replace(std::back_insert_iterator<std::string>(temp), str.cbegin(), str.cend(), rgx_pattern, "11111");
    return temp;
}
int main()
{
    std::string str;
    std::cout << "Enter a sequence of 1 and 0 : ";
    std::getline(std::cin, str);
    std::string stuffed;
    stuffed = bitStuffing(str);
    std::cout << std::endl << "Stuffed : \t" << stuffed;
    std::string unstuffed;
    unstuffed = bitUnstuffing(stuffed);
    std::cout << std::endl << "Unstuffed : \t" << unstuffed;

}

