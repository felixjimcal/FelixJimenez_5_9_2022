#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Movie.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

class Interpreter {
  public:
    void ImportFile();
    int InterpretDecade(int decade);
    std::vector<Movie> FilterMovies(int decade);
    void ExportFile(int decade, std::vector<Movie> filteredMovies);

    std::vector<Movie> movies {};
};
#endif // INTERPRETER_H
