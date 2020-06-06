#include <iostream>
#include "deserilize.h"

int main (argc,char* argv[]) {
    deserillized compressed_data= deserilize(argv[1]);
    std::string decoded = decode( compressed_data.freq_map, compressed_data.bits_string);
    std::ofstream of

}
