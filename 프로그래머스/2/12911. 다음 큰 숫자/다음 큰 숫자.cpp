int solution(int n) {
    int c = n & -n;
    int r = n + c;
    
    return r | (((r ^ n) >> 2) / c);
}