#include "pass.hpp"


/*GitHub signing the commit testing with gpg. */

int main(int argc, const char* argv[]) {
    PassGen obj;
    int size = 15;
    if (argc > 5) {
        obj.HelpMenu(argv[0]);
        return 1;
    }

    // Arguman parsing for the password gen. options.
    for (int i = 1; i < argc; i++) {
        std::string args = argv[i];
        if (args == "-d" || args == "--digit" ) {
            obj.SetDigit(1);
        }
        else if (args == "-s" || args == "--symbols") {
            obj.SetSymbol(1);
        }else if(args == "-h" || args == "--help"){
            obj.HelpMenu(argv[0]);
        }else if( args == "--size" ){
            if(!argv[i+1]){
                std::cerr << "Please specify the number!";
                return 29;
            }
            size = std::stoi(argv[i+1]);
        }
    }
    
    obj.GeneratePassword(obj.GetDigit(), obj.GetSymbol(), size);
    std::cout << obj.getPassword();
    return 0;
}

