#include <iostream>
#include "deserilize.h"
#include "Decoding.h"

int main (int argc,char* argv[])
 {
    deserillized compressed_data= deserilize(argv[1]);
    std::string decoded = decode( compressed_data.freq_map, compressed_data.bits_string);
    std::ofstream of

}
