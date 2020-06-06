#ifndef HUFFMAN_H
#define HUFFMAN_H

#iclude <bitset>
#include <string>
#include <vector>



std::string bits_string (std::vector <uint8_t> image,  unordered_map <uint8_t , string > hCode){
    std::string bitsString="";
    //cout << " bits string  :  ";
    for(auto pixel : image){
      //  std::cout << hCode.at(ch);
        bitString += hCode.at(pixel);
    }
    return bitsString;
}

std::vector <uint8_t> bytes_array (std::string bits_string){
    std::stringstream stream(bits_string);
    std::vector <uint8_t> bytes_array ;
    while (stream.good()) {
        std::bitset<8> byte;
        ss >>byte;
        uint8_t b = uint8_t(byte.to_ulong());
        bytes_array.push_back(b);
    }
    //printing bytes_array
    /*
      for(auto i: bytes_array)
      {
          std::cout<<i <<" ";
      }
      */
    //std::cout<< "compressed size :   "<<bytes_array.size()<<std::endl;
    return byte_array;

}

#endif // HUFFMAN_H
