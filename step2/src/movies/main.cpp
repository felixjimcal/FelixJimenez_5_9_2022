#include <QCoreApplication>
#include "Interpreter.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Interpreter interpreter;

    interpreter.ImportFile();

    std::cout<<"Please, indicate a decade ("<< interpreter.movies.front().year <<"/"<<
               interpreter.movies.back().year << ")"<<std::endl;

    int decade = 1910;
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
    decade = interpreter.InterpretDecade(decade);
    std::vector<Movie> filteredMovies = interpreter.FilterMovies(decade);
    interpreter.ExportFile(decade, filteredMovies);

    return a.exec();
}
