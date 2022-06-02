// prog20_1
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <iterator>
#include <set>
#include <map>

int main() {
    std::fstream in("text.txt");
    std::string s;
    std::map<std::string, unsigned> counter;

    while (!in.eof()) {
        in >> s;

        ++counter[s];
    }

    for (const auto& [word, count] : counter)
        std::cout << word << '\t' << count << '\n';

    in.close();
}
// prog20_2
#include <iostream>
#include <iterator>
#include <set>

int main() {

    std::set<double> nums = { 1, 2, 3, 4, 5, 6 };
    std::set<double> tmp;

    while (nums.size() != 1) {
        for (auto it = nums.cbegin(); it != nums.cend(); it++) {
            if (std::next(it) != nums.cend())
                tmp.insert(*it + *std::next(it));
        }

        nums = tmp;

        tmp.clear();
    }

    for (auto i : nums)
        std::cout << i << '\n';
}