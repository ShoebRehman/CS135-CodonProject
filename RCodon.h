/*
Title: RNA Codon Project
Name: Shoeb Rehman
Date: March 4, 2014
About: RNA Codon Class definition with function definitions
*/

#ifndef RCodon_H


#define RCodon_H


#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class RCodon{
      private:
             string codon;
             string strand;
      public:
             void returnCodon(string codon, int counter); // This outputs the amino acid that corresponds to the codon that it is reading
             string returnStrand(); // accessor function for strand
             void complement(string b); // complements the DNA into RNA
             void storeStrand(string strand); //mutator function for strand
};

// Takes the RNA string and outputs the Amino Acid produced
void RCodon::returnCodon(string codon, int counter){
    ofstream outputFile("aminoacids.txt", ios::app);
    outputFile << "From RNA " << counter + 1 << ": \n \t";
for (int i = 0; i < codon.size(); i+=3){
            if(codon.substr(i,3)=="uuu"||codon.substr(i,3)=="uuc"){
                outputFile << " Phe -";
            }
            if(codon.substr(i,3)=="uua"||codon.substr(i,3)=="uug"||codon.substr(i,3)=="cuu"||codon.substr(i,3)=="cuc"||codon.substr(i,3)=="cua"||codon.substr(i,3)=="cug"){
                outputFile << " Leu -";
            }
            if(codon.substr(i,3)=="auu"||codon.substr(i,3)=="auc"||codon.substr(i,3)=="aua"){
                outputFile << " Ile -";
            }
            if(codon.substr(i,3)=="aug"){
                outputFile <<" Met -";
            }
            if(codon.substr(i,3)=="guu"||codon.substr(i,3)=="guc"||codon.substr(i,3)=="gua"||codon.substr(i,3)=="gug"){
                outputFile <<" Val -";
            }
            if(codon.substr(i,3)=="ucu"||codon.substr(i,3)=="ucc"||codon.substr(i,3)=="uca"||codon.substr(i,3)=="ucg"){
                outputFile <<" Ser -";
            }
            if(codon.substr(i,3)=="ccu"||codon.substr(i,3)=="ccc"||codon.substr(i,3)=="cca"||codon.substr(i,3)=="ccg"){
                outputFile <<" Pro -";
            }
            if(codon.substr(i,3)=="acu"||codon.substr(i,3)=="acc"||codon.substr(i,3)=="aca"||codon.substr(i,3)=="acg"){
                outputFile <<" Thr -";
            }
            if(codon.substr(i,3)=="gcu"||codon.substr(i,3)=="gcc"||codon.substr(i,3)=="gca"||codon.substr(i,3)=="gcg"){
                outputFile <<" Ala -";
            }
            if(codon.substr(i,3)=="uau"||codon.substr(i,3)=="uac"){
                outputFile <<" Tyr -";
            }
            if(codon.substr(i,3)=="cau"||codon.substr(i,3)=="cac"){
                outputFile <<" His -";
            }
            if(codon.substr(i,3)=="caa"||codon.substr(i,3)=="cag"){
                outputFile <<" Gln -";
            }
            if(codon.substr(i,3)=="aau"||codon.substr(i,3)=="aac"){
                outputFile <<" Asn -";
            }
            if(codon.substr(i,3)=="aaa"||codon.substr(i,3)=="aag"){
                outputFile <<" Lys -";
            }
            if(codon.substr(i,3)=="gau"||codon.substr(i,3)=="gac"){
                outputFile <<" Asp -";
            }
            if(codon.substr(i,3)=="gaa"||codon.substr(i,3)=="gag"){
                outputFile <<" Glu -";
            }
            if(codon.substr(i,3)=="ugu"||codon.substr(i,3)=="ugc"){
                outputFile <<" Cys -";
            }
            if(codon.substr(i,3)=="ugg"){
                outputFile <<" Trp -";
            }
            if(codon.substr(i,3)=="cgu"||codon.substr(i,3)=="cgc"||codon.substr(i,3)=="cga"||codon.substr(i,3)=="cgg"){
                outputFile <<" Arg -";
            }
            if(codon.substr(i,3)=="agu"||codon.substr(i,3)=="agc"){
                outputFile <<" Ser -";
            }
            if(codon.substr(i,3)=="aga"||codon.substr(i,3)=="agg"){
                outputFile <<" Arg -";
            }
            if(codon.substr(i,3)=="ggu"||codon.substr(i,3)=="ggc"||codon.substr(i,3)=="gga"||codon.substr(i,3)=="ggg"){
                outputFile <<" Gly -";
            }
            if(codon.substr(i,3)=="uaa"||codon.substr(i,3)=="uag"||codon.substr(i,3)=="uga"){
                outputFile << "- STOP\n";
                i = codon.size() + 1;
            }
        }
	outputFile << endl;
}

// Complements the DNA strand into an RNA strand
void RCodon::complement(string b){
       ofstream outputFile;
       outputFile.open("rnastrands.txt",ios::app);
	for(int g = 0; g < b.size(); g++){
		if(b[g]=='a'){
			outputFile << "a";
		}
		if(b[g]=='t'){
			outputFile << "u";
		}
		if(b[g]=='g'){
			outputFile << "g";
		}
		if(b[g]=='c'){
			outputFile << "c";
		}
	}
	outputFile << endl;
}

// Stores strand	
void RCodon::storeStrand(string strand){
	this->strand = strand;
}

// Accessor function to return strand
string RCodon::returnStrand(){
	return strand;
}

// Checks for any unknown letters in the DNA strand
void checkStrand(string b, int counter){
bool status = true;
for(int g = 0; g < b.size(); g++)
	{
		if((b[g] != 'a') && (b[g] != 't') && (b[g] !='g') && (b[g] != 'c')){
		cout << "There is an unknown letter in string " << counter << "!" << endl;
		cout << "Your unknown letter is: " << b[g] << endl;
		cout << "The letter is located on the " << g+1 << " letter." << endl;
		status = false; 
		}
	}
	if(status){
	cout << "For string # " << counter << ", there aren't any unknown letters in it." << endl;
	}
}

#endif
