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
    
    while(!inputFile.eof()){
    inputFile >> buffer;
    lineCount++;
    }
    
    inputFile.close();
    lineCount = lineCount - 1;        
    cout << "There are " << lineCount << " DNA strands in this file." << endl;
    
    DNAstrands Dstrand[lineCount];
    RCodon Rstrand[lineCount];
    
    inputFile.open("dnastrands.txt");
    
    for(int g = 0; g < lineCount; g++){
        inputFile >> currentstring;
        Dstrand[g].setStrand(currentstring);
        }
    inputFile.close();
     
    for(int a = 0; a < lineCount; a++){
		checkStrand(Dstrand[a].viewStrand(), a + 1);
	}
	
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

	for(int aa = 0; aa < lineCount; aa++){
		buffer = Rstrand[aa].returnStrand();
		Rstrand[aa].returnCodon(buffer, aa);
	}
		
return 0;
}
