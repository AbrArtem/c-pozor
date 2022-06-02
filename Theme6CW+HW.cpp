//prog6_1

#include <stdio.h>
#include <inttypes.h>

int main() {

    uint8_t n;
    scanf_s("n= %hhd", &n);

    uint64_t m = 1UL << n;
    printf("2^%hhu = %" PRIu64 "\n", n, m);
}
//prog6_2

#include <stdio.h>

int main() {
    int n;
    unsigned k;

    scanf_s("%d", &n);
    scanf_s("%u", &k);

    int res = n | (1 << k);
    printf("r=%d", res);
}
//prog6_3

#include <stdio.h>
#include <inttypes.h>

int main() {
    uint64_t m;
    unsigned j;

    scanf_s("%" PRIu64"", &m);
    scanf_s("%u", &j);

    uint64_t res1 = m & ~(1 << 3);

    printf("r=%" PRIu64 ", %" PRIx64, res1, res1);
}
// prog6_4

#include <stdio.h>
#include <inttypes.h>


int main() {
    uint32_t m1;
    scanf_s("%" PRIu64"", &m1);

    uint32_t b0, b1, b2, b3, res2;

    b0 = m1 & 255;
    b1 = (m1 >> 8) & 0xFF;
    b2 = (m1 >> 16) & 0xFF;
    b3 = m1 >> 24;

    res2 = b0 | b1 | b2 | b3; // little-endian
    // b3| b2|b1|b0
    // b3 |b1|b2|b0

    printf("r=%" PRIu64 ", %" PRIx64, res2, res2);
}
// prog6_5

#include <stdio.h>


size_t max_bits_in_row(unsigned x) {

    size_t res = 0, count = 0;;
    size_t num_bits = 8 * sizeof(x);

    for (int i = 0; i < num_bits; i++) {
        unsigned r = x & (1 << i);
        if (r) {
            count++;
        }
        else {
            if (count > res) {
                res = count;
            }
        }
    }

    return res;
}

int main() {
    unsigned m2 = 0x01020340;

    printf(" max 1th in a row is %zu", max_bits_in_row(m2));
}
// prog6_6

#include <stdio.h>

int main() {

    for (int x = 0; x < 17; x++) {

        int t1 = (x & (x - 1)) > 0;
        int t2 = (x & -x);

        printf("%d: %d % d \n", x, t1, t2);

    }

}
// prog6_7

#include <stdio.h>

int main() {
    unsigned M = (1 << 24) + (2 << 16) + (3 << 8) + 4;
    unsigned a1 = M & 0xFF;
    unsigned a2 = (M & 0xFF00) >> 8;
    if ((a1 == 4) && (a2 == 3)) { printf("Little"); }
    else if ((a1 == 4) && (a2 == 2)) { printf("Middle"); }
    else if ((a1 == 1)) { printf("Big"); }
    else { printf("Unknown"); }
}

// prog6_8
#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint16_t m, j;
    int16_t k;
    cout << "m-->";
    cin >> m;
    cout << bitset<16>(m) << endl;
    cout << "j-->";
    cin >> j;
    m = ~m;
    k = 1 << j;
    //cout<<bitset<32>(k)<<endl;
    m = m | k;
    m = ~m;
    cout << bitset<16>(m) << endl;
    cout << m << endl;

    return 0;
}

// prog6_12
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int a, i, j;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter i: ";
    cin >> i;
    cout << "Enter j: ";
    cin >> j;
    cout << bitset<16>(a) << endl;
    int bj = a & (1 << (j - 1));
    int bi = a & (1 << (i - 1));
    a = a & (~(1 << (i - 1))) & (~(1 << (j - 1)));
    if (bj) a = a | (1 << (i - 1));
    if (bi) a = a | (1 << (j - 1));
    cout << bitset<16>(a) << "\n" << "Result dec: " << a << "\n" << "hex: " << hex << a << endl;

    return 0;
}
#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint16_t m,j;
    int16_t k;
    cout<<"m-->";
    cin>>m;
    cout<<bitset<16>(m)<<endl;
    cout<<"j-->";
    cin>>j;
    m=~m;
    k=1<<j; 
    //cout<<bitset<32>(k)<<endl;
    m=m|k;
    m=~m;
    cout<<bitset<16>(m)<<endl;
    cout<<m<<endl;

    return 0;
}
