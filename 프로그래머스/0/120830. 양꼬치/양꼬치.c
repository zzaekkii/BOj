#define max(a, b) (((a) > (b)) ? (a) : (b))

#define MEAT 12000
#define DRINK 2000
#define DRINK_FREE 10

int solution(int n, int k) {
    k = max(0, k - n / DRINK_FREE);
    return MEAT * n + DRINK * k;
}