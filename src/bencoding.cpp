#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <ctype.h>
#include "bencoding.h"
using namespace std;

class bencoding {

    public: 
        map<string, string> parse(string filename) {

            char c;
            vector<string> a;
            ifstream file;
            map<string,string> returner;

            file.open(filename);
            while (file.get(c)) {
                switch (c) {
                    case 'i':
                        a.push_back(parseInteger(file));
                        break;
                    case 'd':
                        //a.push_back(parseDict(file));
                        break;
                    case 'l':
                        //a.push_back(parseList(file));
                        break;
                    default:
                        if (isdigit(c)) {
                            //a.push_back(parseString(file));
                        }
                }
            }
            return returner;


        }

    private:
        int reverseInt(int number) {
            int holder = 0;
            int remainder;

            while (number != 0) {
                remainder = number % 10;
                holder = holder * 10 + remainder;
                number /= 10;
            }
            
            return holder;
        }

        string parseInteger(ifstream& reader) {
            int hold = 0, power = 0;
            char c;
            while (reader.get(c)) {
                if (c == 'e') {
                    break;
                }

                hold += (int(c) - 48) * pow(10, power++);
            }
            return to_string(reverseInt(hold));
        }


};


int main(void) {
    bencoding obj;
    obj.parse("/Users/loganlach/sideProjects/bittorrent/src/empty.torrent");
    
}

