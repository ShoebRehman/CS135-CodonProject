/*
Title: RNA Codon Project
Name: Shoeb Rehman
Date: March 4, 2014
About: Driver program for the function
*/

#include <fstream>
#include <string>
#include <iostream>

#include "RCodon.h"
#include "DNAStrand.h"



using namespace std;

int main(){
    string currentstring;
    string buffer;
    ifstream inputFile;
    ofstream outputFile;
    int lineCount = 0;
    
    inputFile.open("dnastrands.txt");
    
	// Reads each strand of DNA and counts how many strands there are 
    while(!inputFile.eof()){
    inputFile >> buffer;
    lineCount++;
    }
    
    inputFile.close();
    lineCount = lineCount - 1;        
    cout << "There are " << lineCount << " DNA strands in this file." << endl; // Outputs the amount of strands
    
    DNAstrands Dstrand[lineCount];
    RCodon Rstrand[lineCount];
    
    inputFile.open("dnastrands.txt");
    
	//Stores the DNA strands
    for(int g = 0; g < lineCount; g++){
        inputFile >> currentstring;
        Dstrand[g].setStrand(currentstring);
        }
    inputFile.close();
     
	 //Checks each strand for any unknown letters
    for(int a = 0; a < lineCount; a++){
		checkStrand(Dstrand[a].viewStrand(), a + 1);
	}
	
	//Complements each nucleotide and stores them
	for(int t = 0; t < lineCount; t++){
        buffer = Dstrand[t].viewStrand();
        Rstrand[t].complement(buffer);
	}
	
	inputFile.open("rnastrands.txt");
	
	for(int j = 0; j < lineCount; j++){
		inputFile >> buffer;
		Rstrand[j].storeStrand(buffer);
	}
	
	inputFile.close();

	// Outputs Amino Acids
	for(int aa = 0; aa < lineCount; aa++){
		buffer = Rstrand[aa].returnStrand();
		Rstrand[aa].returnCodon(buffer, aa);
	}
		
return 0;
}
