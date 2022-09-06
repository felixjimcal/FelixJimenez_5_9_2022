#include "Interpreter.h"

int Interpreter::InterpretDecade(int decade)
{
    int result = 2000;

    if (std::to_string(decade).size() == 2 && decade % 10 == 0){
        if(decade > 00){
            result =std::stoi(std::to_string(19) + std::to_string(decade));
        }
    }

    // movies.at(0).year = remember, when we collect the data, we are already sorting the list
    // if the list changes we do not have to update this line
    if (std::to_string(decade).size() == 4 && decade >= movies.at(0).year && decade % 10 == 0){
        result = decade;
    }
    return result;
}

std::vector<Movie> Interpreter::FilterMovies(int decade)
{
    std::vector<Movie> result;
    std::copy_if (movies.begin(), movies.end(), std::back_inserter(result), [&decade](const Movie movie){
        return movie.year >= decade && movie.year <= decade+9;
    });
    return result;
}
