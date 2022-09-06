#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "movie.h"

#include <algorithm>
#include <string>
#include <vector>

class Interpreter {
  public:
    void ImportFile();
    int InterpretDecade(int decade);
    std::vector<Movie> FilterMovies(int decade);
    void ExportFile(int decade, std::vector<Movie> filteredMovies);

    std::vector<Movie> movies {};
};
#endif // INTERPRETER_H
