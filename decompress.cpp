#include <iostream>
#include "deserilize.h"

int main (int argc ,char* argv[]) {
    deserillized compressed_data= deserilize(argv[1]);
    std::vector<uint8_t> decoded = decode( compressed_data.freq_map, compressed_data.bits_string);
    //std::cout<<decoded.size();

    std::ofstream image_out;

    image_out.open("image.pgm", std::ios::out | std::ios::binary);

    image_out<<compressed_data.format<<std::endl;
    image_out<<compressed_data.rows<<" "<<compressed_data.cols<<std::endl;
    image_out<<compressed_data.maxval<<std::endl;
    int i = 0;
    for (auto d : decoded)
    {
        if (i++ % compressed_data.cols == 0){
            image_out << std::endl;
        }

        image_out << d << " ";
    }
    image_out.close();

}
