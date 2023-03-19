#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
    Comedy(int stock, std::string director, std::string title, int releaseYear);

    char getType() override;
    std::string getInfo() override;
    bool operator==(const Movie&) const;
};

#endif // COMEDY_H
