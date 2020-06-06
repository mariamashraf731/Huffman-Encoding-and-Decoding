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


}
