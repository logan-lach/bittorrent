#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
    fstream h;
    h.open("/Users/loganlach/sideProjects/bittorrent/src/t1.torrent");
    char c;
    while (h.get(c)) {
        cout << c;
    }
    return 0;
}
