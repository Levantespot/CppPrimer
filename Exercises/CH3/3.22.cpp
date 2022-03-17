#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::string;
using std::cout; using std::cin; using std::endl;

int main() {
    vector<string> text;

    for (string line; getline(cin, line); text.push_back(line));

    // for (auto iter_p1 = text[0].begin(); iter_p1 != text[0].end(); ++iter_p1) {
    //     *iter_p1 = toupper(*iter_p1);
    // }

    for (auto &ref_p1 : text[0]) {
        ref_p1 = toupper(ref_p1);
    }

    for (auto line : text) {
        cout << line << endl;
    }
    cout << endl;
    return 0;
}