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

// Builds Huffman tree and decode the input
std::unordered_map<uint8_t,string> buildhuffmanTree( std::unordered_map<uint8_t,int> freq_map)
{
    //creating a priority queue to store leaf nodes of huffmantree
    priority_queue<Node* , vector<Node*> , comp >Pq;

    //create a leaf node for each character and add it to the priority_queue
    for(auto pair: freq_map) {
        Pq.push(getnode(pair.first , pair.second , nullptr , nullptr));
    }

    //do it till there's more than 1 node in the queue
    while( Pq.size() != 1 )
    {
        //Removing the two nodes of the highest priority from the queue
        Node* left= Pq.top();
        Pq.pop();
        Node* right= Pq.top();
        Pq.pop();

        //create new internal node as parent of those two nodes
        // its frequency is the sum of their frequency
        //add this node to the priority_queue
        int sum = left->freq + right->freq;
        Pq.push(getnode( '\0' , sum , left , right));
    }

    // root stores pointer to root of huffmantree
    Node* root = Pq.top();

    //transverse the huffmantree and store the code in the map
    unordered_map<uint8_t , string > huffmanCode;
    encode (root , "" , huffmanCode);

    //print huffman Code
   /* cout << " Huffman codes are :\n" << '\n';
    for (auto pair: huffmanCode){
        cout << pair.first << " " << pair.second << '\n';
    }*/
    return huffmanCode;
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
