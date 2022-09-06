#include "Interpreter.h"
#include <fstream>
#include <iostream>

int main() {
    Interpreter interpreter;

    interpreter.ImportFile();

    std::cout<<"Please, indicate a decade ("<< "1900" <<"/"<< "2010" << ")";

    int decade;;
    while(true){
        std::cin>>decade;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Only numbers and decades, please"<< std::endl;
        } else {
            decade = interpreter.InterpretDecade(decade);
            break;
        }
    }

    std::vector<Movie> filteredMovies = interpreter.FilterMovies(decade);
    interpreter.ExportFile(decade, filteredMovies);

  return 0;
}
