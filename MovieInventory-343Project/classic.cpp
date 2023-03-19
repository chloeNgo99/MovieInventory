// -----------------------classic.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include "classic.h"
#include <typeinfo>

/*
---------------------Classic::Classic---------------------
This is the default constructor for the Classic class. It inherits from the Movie class and sets the values of
releaseMonth, actorFirstName and actorLastName to default values of 0 and empty strings respectively.
*/
Classic::Classic() : Movie() {
    releaseMonth = 0;
    actorFirstName = "";
    actorLastName = "";
}

/*
---------------------Classic::Classic----------------
This is a constructor for the Classic class. It takes in several parameters: an integer stock, a string director, a string title,
a string majorActorFullName, an integer releaseMonth, and an integer releaseYear. It calls the constructor of the Movie class, which
takes in parameters for stock, director, title, and releaseYear. In addition to these parameters, the Classic constructor sets the
majorActorFullName and releaseMonth member variables of the Classic object.
*/
Classic::Classic(int stock, std::string director, std::string title, std::string majorActorFullName, int releaseMonth, int releaseYear)
        : Movie(stock, director, title, releaseYear), majorActorFullName(majorActorFullName), releaseMonth(releaseMonth), releaseYear(releaseYear) {
}

/*
---------------------getMajorActorFullName----------------
This method returns a string containing the full name of the major actor for this Classic movie.
It retrieves the private member variable 'majorActorFullName' of the Classic object.
*/
std::string Classic::getMajorActorFullName(){
    return majorActorFullName;
}

/*
---------------------getReleaseMonth----------------
This method returns the release month of this Classic movie as an integer.
It retrieves the private member variable 'releaseMonth' of the Classic object.
*/
int Classic::getReleaseMonth() {
    return releaseMonth;
}

/*
---------------------getReleaseYear----------------
This method returns the release year of this Classic movie as an integer.
It retrieves the private member variable 'releaseYear' of the Classic object.
*/
int Classic::getReleaseYear(){
    return releaseYear;
}

/*
---------------------getReleaseDate----------------
This method returns the release date of this Classic movie as an integer.
It combines the release month and year of the Classic object and returns them as a single integer.
*/
int Classic::getReleaseDate(){
    return stoi(to_string(releaseMonth) + to_string(releaseYear));
}

/*
---------------------getType----------------
This method returns the type of the movie as a character.
It returns the character 'C' to indicate that this is a Classic movie.
*/
char Classic::getType() {
    return 'C';
}

/*
---------------------getInfo----------------
This method returns a string containing all the relevant information about the Classic movie, including its type,
stock, director, title, major actor's full name, release month, and release year.
It retrieves the necessary information from the Classic object and formats it into a string.
*/
std::string Classic::getInfo() {
    return std::string(1, getType()) + ", " + std::to_string(getStock()) + ", " +
           getDirector() + ", " + getTitle() + ", " + majorActorFullName + " " + std::to_string(getReleaseMonth()) + " " +
           std::to_string(getReleaseYear());
}

/*
---------------------operator==----------------
This method compares a Classic movie object with another Movie object to check for equality.
It first checks if the other Movie object is a Classic movie using typeid. If it is, it then downcasts
the other Movie object to a Classic object and compares the titles, directors, release years, release months,
and major actor's full names of the two Classic movies.
*/
bool Classic::operator==(const Movie& movie) const{
    if(typeid(movie) != typeid(Classic)) {
        return false;
    }
    const Classic& other = dynamic_cast<const Classic&>(movie);
    return (title == other.title && director == other.director && releaseYear == other.releaseYear && 
    releaseMonth == other.releaseMonth && majorActorFullName == other.majorActorFullName);
}

