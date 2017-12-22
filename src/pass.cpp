#include "pass.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

void PassGen::SetDigit(int flag) {
	digit = flag;
}


void PassGen::SetSymbol(int flag) {
	symbols = flag;
}


int PassGen::GetDigit() {
	return digit;
}


int PassGen::GetSymbol(){
	return symbols;
}


void PassGen::HelpMenu(std::string argument){
    std::cerr << "Usage for "<<argument<<'\n'
            << "-d, --digit\t for numbers [0..9]\n"
            <<"-s, --symbols\t for !@#$%..";
}


//FIXME: CCN is 7, try to fix it.
std::vector<char> CreateContainer(int dflag, int sflag){
    // Flag option digit
    std::vector<char> digitals = {'0','1', '2', '3', '4', '5', '6', '7', '8','9'};
    //base vector to be used for password generation
    std::vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l',
                                 'm','n','o','p','q','r','s','t','u','v','w','x',
                                 'y','z','A','B','C', 'D','E','F','G','H','I','J',
                                 'K','L','M','N','O','P','Q','R','S','T','U','V','W',
                                 'X','Y','Z'};
    // Flag option symbols. 
    std::vector<char> metaChars = {'!','#','$','%','^','&','*','(',')','+','-',
                                    '.','/',':',';','<','=','>','?','@','[','\\',
                                    ']','_','{','|','}','~'}; 
   
    if(dflag == 1 && sflag == 1){
       letters.insert(letters.begin(), digitals.begin(), digitals.end());
        letters.insert(letters.begin(), metaChars.begin(), metaChars.end());
    }else if(dflag == 1 && sflag == 0){
        letters.insert(letters.begin(), digitals.begin(), digitals.end());
    }else if(dflag == 0 && sflag == 1){
        letters.insert(letters.begin(), metaChars.begin(), metaChars.end());
    }
    return letters;
}


void PassGen::GeneratePassword(int dflag, int sflag, int size=15){
    // Generating the container for the password generation.
    std::vector<char> passContainer = CreateContainer(dflag, sflag);
    //Randomizing the generation each time it called!
    srand(time(NULL));

    for(int i = 0; i < size; i++){
        int x = rand() % passContainer.size();
        std::cout<<passContainer.at(x);
    }
    std::cout << "\nRand generated. Newline inserting\n";
    // Printer -> separatable.
    for(std::vector<char>::const_iterator it = passContainer.begin();
            it != passContainer.end(); ++it){
        std::cout << *it;
    }
}
