#ifndef READING_H
#define READING_H

#include<iostream>
#include <string>
#include<vector>


struct image {

    unsigned int rows;
    unsigned int cols;
    unsigned int maxVal;
    std::string format;
    std::vector <uint8_t> grayvalues;
};

image pgm_read( const std::string filepath){
    

#endif // READING_H
