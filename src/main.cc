/**
 * Copyright 2022 Daniel Hernández de León
 * daniel.leon.19@ull.edu.es
 */

#include <iostream>

#include "../include/pd_automaton.h"
#include "../include/pda_parser.h"

#define loop while (true)

std::string Red(std::string string);
std::string Green(std::string string);
std::string AskFile();
std::string AskInput();
void my_handler(int s);

std::string Red(std::string string) { return "\x1B[31m" + string + "\033[0m"; }
std::string Green(std::string string) {
  return "\x1B[32m" + string + "\033[0m";
}

const char *TITLE = R"(
  _____           _         _                                   _                        _        
 |  __ \         | |       | |                       /\        | |                      | |       
 | |__) |   _ ___| |__   __| | _____      ___ __    /  \  _   _| |_ ___  _ __ ___   __ _| |_ __ _ 
 |  ___/ | | / __| '_ \ / _` |/ _ \ \ /\ / / '_ \  / /\ \| | | | __/ _ \| '_ ` _ \ / _` | __/ _` |
 | |   | |_| \__ \ | | | (_| | (_) \ V  V /| | | |/ ____ \ |_| | || (_) | | | | | | (_| | || (_| |
 |_|    \__,_|___/_| |_|\__,_|\___/ \_/\_/ |_| |_/_/    \_\__,_|\__\___/|_| |_| |_|\__,_|\__\__,_|
                                                                                                  
)";

std::string AskFile() {
  std::string filename;
  std::ifstream file;
  std::cout << "\nWrite the name of the file you wanna load:  ";
  do {
    std::getline(std::cin, filename);
    file = std::ifstream(filename);
    if (!file.good()) {
      std::cout << Red("The file cannot be loaded or does not exist.")
                << "\x1b[A";
      for (size_t i = 0; i < filename.length(); i++) {
        std::cout << " ";
      }
      for (size_t i = 0; i < filename.length(); i++) {
        std::cout << "\b";
      }
    }
  } while (!file.good());
  std::cout << "\33[2K";
  return filename;
}

std::string AskInput() {
  std::string input;
  std::cout << "Enter the input: ";
  std::getline(std::cin, input);
  return input;
}

int main() {
  std::cout << TITLE;
  std::string filename = AskFile();

  loop {
    try {
      std::string input = AskInput();
      PDAutomaton pda = PDAutomaton(filename);
      if (pda.Check(input)) {
        std::cout << " - " + Green("Accepted\n");
      } else {
        std::cout << " - " + Red("Rejected\n");
      }
      std::string see_trace;
      std::cout << "Do you wanna see the trace? [y/N]: ";
      std::getline(std::cin, see_trace);
      if (see_trace[0] == 'Y' || see_trace[0] == 'y') {
        std::cout << "\n" + pda.ShowTrace() + "\n";
      }
    } catch (std::runtime_error &e) {
      std::cout << " - " + Red(e.what()) << std::endl;
    }
  }
  return 0;
}
