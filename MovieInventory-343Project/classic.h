#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"
#include <string>

class Classic : public Movie {
public:
    Classic();
    Classic(int stock, std::string director, std::string title, std::string majorActorFullName, int releaseMonth, int releaseYear);

    std::string getMajorActorFirstName();
    std::string getMajorActorLastName();
    std::string getMajorActorFullName();
    int getReleaseMonth();
    int getReleaseYear();
    int getReleaseDate();

    char getType() override;
    std::string getInfo() override;
    bool operator==(const Movie&) const;

private:
    std::string actorFirstName;
    std::string actorLastName;
    std::string majorActorFullName;
    int releaseMonth, releaseYear;
};

#endif  // CLASSIC_H
