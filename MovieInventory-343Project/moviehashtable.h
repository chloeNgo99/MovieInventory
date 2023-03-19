#ifndef MOVIE_HASHTABLE_H
#define MOVIE_HASHTABLE_H

#include "movie.h"
#include "classic.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class MovieHashTable {
public:
  MovieHashTable();
  ~MovieHashTable();

  void insertMovie(Movie *movie);
  void sortComedyBucket(std::vector<Movie*>& bucket);
  void sortDramaBucket(std::vector<Movie*>& bucket);
  void sortClassicBucket(std::vector<Movie*>& bucket);
  void removeMovie(Movie *movie);
  Movie* searchMovie(char, string, string, int, string);
  void adjustStock(char action,char type, string title, string director, int releaseYear, string majorActor);
  void printInventory(char) const;
  bool contains(Movie *movie) const;
  Movie *get(Movie *movie) const;

private:
  static const int TABLE_SIZE = 31;

  std::vector<Movie *> table[TABLE_SIZE];

  //int hashFunction(std::string title, std::string director,int releaseYear) const;
  int hashFunction(char type, std::string title, std::string director, int releaseYear, std::string majorActor);
  int hashString(std::string str);
};

#endif // MOVIE_HASHTABLE_H
