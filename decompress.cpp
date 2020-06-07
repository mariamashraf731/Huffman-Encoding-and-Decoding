#include <iostream>
#include "deserilize.h"
#include "Decoding.h"
#include "huffman.h"
#include <unordered_map>

int main (int argc ,char* argv[]) 
{

    deserillized compressed_data= deserilize(argv[1]);
    std::string decoded = decode( compressed_data.freq_map, compressed_data.bits_string);
    std::unordered_map<uint8_t,int> Frequency = compressed_data.freq_map;
    std::string compressed_string = compressed_data.bits_string;
    std::vector <uint8_t> compressed_bytes = bytes_array(compressed_string);
    std::ofstream image_out;

    image_out.open("image.pgm", std::ios::out | std::ios::binary);

    image_out<<compressed_data.format<<std::endl;
    image_out<<compressed_data.rows<<" "<<compressed_data.cols<<std::endl;
    image_out<<compressed_data.maxval<<std::endl;
    image_out<<decoded;

    //frequency map
    for (auto m : Frequency)
    {
        image_out << m.first<< " " << m.second << std::endl;
    } 
    //compressed array
    int i=0;
    for(auto byte:compressed_bytes ){
        image_out<<byte;
        i++;
    }
    //std::cout<<i<<std::endl;
    //std::cout<<compressed_bytes.size()<<std::endl;
}
