#include<iostream>
#include "reading.h"
#include<unordered_map>
#include "huffman.h"


image pgm_read (const std::string);

int main(int argc, char* argv[])
{
    image im;
    im = pgm_read (argv[1]);

    std::unordered_map<uint8_t,int> Frequency = freq_map (im.pixels_values);

    std::unordered_map<uint8_t,string> huffmanCode = buildhuffmanTree( Frequency);

    std::string compressed_string = bits_string(im.pixels_values,huffmanCode);

    std::vector <uint8_t> compressed_bytes = bytes_array(compressed_string);

    //serilizing compressed image

    std::ofstream out;
    out.open("encoded", std::ios::out | std::ios::binary);
    //data
    out<<im.format<<std::endl;
    out<<im.rows<<" "<<im.cols<<std::endl;
    out<<im.maxVal<<std::endl;
    out<<compressed_bytes.size()<<" "<< compressed_string.size()<<" " << Frequency.size() <<std::endl;

    //frequency map
    for (auto m : Frequency)
    {
        out << m.first<< " " << m.second << std::endl;
    }

    //compressed array
    int i=0;
    for(auto byte:compressed_bytes ){
        out<<byte;
        i++;
    }
    //std::cout<<i<<std::endl;
    //std::cout<<compressed_bytes.size()<<std::endl;




    out.close();

}
