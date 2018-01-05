#include "pass.hpp"
#include <cstdlib>
#include <ctime>
#include <random>
#include <utility>
#include <vector>

void PassGen::SetDigit(int flag) { digit = flag; }

void PassGen::SetSymbol(int flag) { symbols = flag; }

int PassGen::GetDigit() { return digit; }

int PassGen::GetSymbol() { return symbols; }

void PassGen::setPassword(std::string pass) { generatedPassword = std::move(pass); }

std::string PassGen::getPassword() { return generatedPassword; }

void PassGen::HelpMenu(const std::string &argument) {
  std::cerr << "Usage for " << argument << '\n'
            << "-d, --digit\t for numbers [0..9]\n"
            << "-s, --symbols\t for !@#$%.."
            << "--size [no]\t Generating passwords by given size.";
}

// FIXME: CCN is 7, try to fix it.
std::vector<char> CreateContainer(int dflag, int sflag) {
  // Flag option digit
  std::vector<char> digitals = {'0', '1', '2', '3', '4',
                                '5', '6', '7', '8', '9'};
  // base vector to be used for password generation
  std::vector<char> letters = {
      'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  // Flag option symbols.
  std::vector<char> metaChars = {
      '!', '#', '$', '%', '^', '&', '*', '(',  ')', '+', '-', '.', '/', ':',
      ';', '<', '=', '>', '?', '@', '[', '\\', ']', '_', '{', '|', '}', '~'};
  if (dflag == 1 && sflag == 1) {
    letters.insert(letters.begin(), digitals.begin(), digitals.end());
    letters.insert(letters.begin(), metaChars.begin(), metaChars.end());
  } else if (dflag == 1 && sflag == 0) {
    letters.insert(letters.begin(), digitals.begin(), digitals.end());
  } else if (dflag == 0 && sflag == 1) {
    letters.insert(letters.begin(), metaChars.begin(), metaChars.end());
  }
  return letters;
}

void PassGen::GeneratePassword(int dflag, int sflag, int size) {
  // Generating the container for the password generation.
  std::vector<char> passContainer = CreateContainer(dflag, sflag);
  std::string pass;
  // Random lib >?
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, passContainer.size() - 1);
  // Randomizing the generation each time it called!
  std::srand(std::time(nullptr));

  for (int i = 0; i < size; i++) {
    int x = dis(gen);
    pass += passContainer.at(x);
  }
  setPassword(pass);
}
