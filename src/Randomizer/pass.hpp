#ifndef __PASS_H_INCLUDED__
#define __PASS_H_INCLUDED__

#include <iostream>
#include <string>

class PassGen {
private:
  std::string generatedPassword;
  int digit{0};
  int symbols{0};

public:
  PassGen() = default;
  ~PassGen() = default;
  // Set and Get Methods
  int GetDigit();
  int GetSymbol();
  void SetDigit(int flag);
  void SetSymbol(int flag);
  void HelpMenu(const std::string &argument);
  void GeneratePassword(int /*dflag*/, int /*sflag*/, int /*size*/);
  // Saving the generated password.
  void setPassword(std::string /*pass*/);
  std::string getPassword();
};


#endif //__PASS_H_INCLUDED__
