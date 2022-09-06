#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

struct Movie {
  std::string title = "";
  int year = 0;
  std::vector<std::string> cast{}, genres{};

  Movie(std::string Title = "", int Year = 0, std::vector<std::string> Cast = {}, std::vector<std::string> Genres = {}){
      title = Title;
      year = Year;
      cast = Cast;
      genres = Genres;
  }

};
#endif // MOVIE_H
