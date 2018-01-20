#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

typedef  char byte;

byte pack_byte(bool bits[8])
{
    byte result(0);
    for(unsigned i(8); i--;)
    {
        result <<= 1;
        result |= byte(bits[ i ]);
    }
    return result;
}

void unpack_byte(byte b, bool* bits)
{
    for(unsigned i(0); i < 8; ++i)
    {
        bits[ i ] = (b & 0x01) != 0;
        b >>= 1;
    }
}
void init_bool_arr (bool* arr) {
    for (int i(0);i<8;++i) {
        arr[i]=0;
    }
}
void pack_string (string s) {
    size_t bytes_in_string = s.length() / 8;
    size_t ostatok = s.length() % 8;
    byte ans [bytes_in_string] ;
    bool tmp_arr[8];
    int ukas(0);
    for (int t(0);t<bytes_in_string;++t) {
        init_bool_arr(tmp_arr);
        for (int i(0);i<8;++i) {
            switch (s[ukas++]) {
                case 'u':
                    tmp_arr[i]=1;
                    break;
                case 'd':
                    tmp_arr[i]=0;
                default:
                    break;
            }
        }
        byte ch = pack_byte(tmp_arr);
        ans[t] = ch;
    }
    if (ostatok) {
        init_bool_arr(tmp_arr);
        for (int i(0);i<ostatok;++i){
            switch (s[ukas++]) {
                case 'u':
                    tmp_arr[i]=1;
                    break;
                case 'd':
                    tmp_arr[i]=0;
                default:
                    break;
            }
        }
        byte ch = pack_byte(tmp_arr);
        ans[bytes_in_string] = ch;
        bytes_in_string++ ;
    }
    for (int i(0);i<bytes_in_string;++i) {
        cout<<ans[i];
    }
}

int main () {
    string str = "uuuuudduudududud";
    pack_string(str);
}
