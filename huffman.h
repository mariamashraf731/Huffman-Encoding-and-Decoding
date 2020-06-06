#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <queue>
#include <unordered_map>
#include "freq_map.h"
#include <bitset>
#include <string>
#include <vector>
using namespace std;

// a tree node
struct Node
{
    uint8_t pixel;
    int freq;
    Node *left, *right;
};

// function to allocate a new node
Node* getnode (uint8_t pixel, int freq, Node* left, Node* right)
{
    Node* node = new Node();
    node->pixel = pixel;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}
//comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        //highest priority item has lowest frequency
        return l->freq > r->freq;

    }
};
//traverse the huffman tree and store huffman codes in a map
void encode(Node* root, string str, unordered_map<uint8_t , string> &huffmanCode)
{
    if (root== nullptr)
        return;
    // found a leaf node
    if (!root->left && !root->right)
    {
        huffmanCode[root->pixel] = str;
    }
    encode(root->left , str +"0" , huffmanCode);
    encode(root->right , str + "1", huffmanCode);

}

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
