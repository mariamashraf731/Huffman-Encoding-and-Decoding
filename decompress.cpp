#include <iostream>
#include "deserilize.h"

int main (argc,char* argv[]) {
        deserillized compressed_data= deserilize(argv[1]);
        std::vector<uint8_t> decoded = decode( compressed_data.freq_map, compressed_data.bits_string);
        std::ofstream image_out;
        image_out.open("image.pgm", std::ios::out | std::ios::binary);

        image_out<<compressed_data.format<<std::endl;
        image_out<<compressed_data.rows<<" "<<im.cols<<std::endl;
        image_out<<compressed_data.maxval<<std::endl;
        image_out<<decoded;

}
