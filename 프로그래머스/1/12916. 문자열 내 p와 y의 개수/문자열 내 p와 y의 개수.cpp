#include <string>
using namespace std;

bool solution(string s)
{
    int p_count = 0;
    int y_count = 0;
    
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'p' || s[i] == 'P') {
            p_count += 1;
        }
        
        if (s[i] == 'y' || s[i] == 'Y') {
            y_count += 1;
        }
    }

    return p_count == y_count;
}