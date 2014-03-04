/*
Title: RNA Codon Project
Name: Shoeb Rehman
Date: March 4, 2014
About: DNA class definition
*/

#ifndef DNAStrand_H

#define DNAStrand_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class DNAstrands{
      private:
              string strand;
      public:
              void setStrand(string string); //sets the strand based on what's read from the file
              string viewStrand(); // accessor function to view strand
};


void DNAstrands::setStrand(string string){
    this->strand = string;
}

string DNAstrands::viewStrand(){
     return strand;
}


#endif
