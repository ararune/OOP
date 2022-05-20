#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;


typedef string cont;
typedef cont::const_iterator iter;

void fixPunctuation(cont& sentence) {
    for (iter i = sentence.begin(); i != sentence.end(); ++i) {
        if (*i == ' ' && (*(i + 1) == ',') || *(i + 1) == '.') {
            sentence.erase(i);
        }
        if (*i == ',' && *(i + 1) != ' ') {
            sentence.insert(i + 1, ' ');
        }
    }
}

int main() {
    const sentence = "I would ,if at all possible , like to print this sentence correctly .";
    fixPunctuation(sentence);
    cout << sentence << endl;

}
