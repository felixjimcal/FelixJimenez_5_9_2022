#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Movie.h"

#include <algorithm>
#include <string>
#include <vector>

class Interpreter {
  public:
    int InterpretDecade(int decade);
    std::vector<Movie> FilterMovies(int decade);

    std::vector<Movie> movies {};
};
#endif // INTERPRETER_H
