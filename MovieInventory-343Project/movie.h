#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie {
public:
    Movie();
    Movie(int stock, std::string director, std::string title, int releaseYear);
    virtual ~Movie();

    std::string getTitle();
    int getStock();
    void increaseStock();
    void decreaseStock();
    std::string getDirector();
    virtual bool operator==(const Movie&) const;

    int getReleaseYear();
    virtual char getType();
    virtual std::string getInfo();

protected:
    std::string title;
    int stock;
    std::string director;
    int releaseYear;
    char type;
};

#endif  // MOVIE_H
