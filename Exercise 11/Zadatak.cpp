#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>



int numbersFile(std::vector<int> v) {
    // 1. baci iznimku ako ne postoji datoteka,
    char msg[] = "File doesn't exist....";
    char ch;
    std::ifstream myFile;
    try
    {
        myFile.open("numbers.txt");
        if (myFile.fail())
            throw msg;
        myFile >> ch;

    }
    catch (char str[])
    {
        std::cout << str;
    }
    // 2 .napuni vektor brojevima iz datoteke
    int tmp = 0;
    while (myFile >> tmp)
    {
        v.push_back(tmp);
    }
    myFile.close();
    // 3. prebroji sve brojeve vece od 500
    int tmp2 = 0;
    for (auto i : v)
        if (i > 500)
            tmp2++;

    std::cout << "Number of elements greater than 500 is " << tmp2 << std::endl;
    // 4. nadi minimalni i maximalni element
    int min = *min_element(v.begin(), v.end());
    std::cout << "Lowest value = " << min << std::endl;
    int max = *max_element(v.begin(), v.end());
    std::cout << "Highest value = " << max << std::endl;

    // 5. iz vektora izbaci brojeve manje od 300
    v.erase(std::remove_if(
        v.begin(), v.end(),
        [](const int& x) {
            return x < 300;
        }), v.end());
    //6. preostale brojeve sortiraj silazno
    std::sort(v.begin(), v.end(), std::greater<int>());
    return 0;
}
int main() {
    std::vector<int> v;
    numbersFile(v);
}