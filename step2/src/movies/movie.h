#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

struct Movie {
  std::string title = "";
  int year = 0;
  std::vector<std::string> cast{}, genres{};
} movie;
#endif // MOVIE_H
