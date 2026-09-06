#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);

    int num;
    ss >> num;

    int minNum = num;
    int maxNum = num;

    while (ss >> num) {
        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }

    return to_string(minNum) + " " + to_string(maxNum);
}