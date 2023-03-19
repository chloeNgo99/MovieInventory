#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
    Drama();
    Drama(int stock, std::string director, std::string title, int releaseYear);

    char getType() override;
    std::string getInfo() override;
    bool operator==(const Movie&) const;
};

#endif // DRAMA_H
