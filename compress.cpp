#include<iostream>
#include "reading.h"

image pgm_read (const std::string);

int main(int argc, char* argv[])
{
    image im;
    im = pgm_read (argv[1]);

}
