// -----------------------movie.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include "movie.h"

/*
---------------------Movie Constructor----------------
This constructor initializes all member variables of the Movie object.
It takes in four parameters: stock, director, title, and releaseYear.
*/
Movie::Movie() {
    stock = 0;
    director = "";
    title = "";
    releaseYear = 0;
}

/*
---------------------Movie Constructor----------------
This constructor initializes all member variables of the Movie object.
It takes in four parameters: stock, director, title, and releaseYear.
*/
Movie::Movie(int stock, std::string director, std::string title, int releaseYear) {
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseYear = releaseYear;
}

/*
---------------------Movie Destructor----------------
This is the destructor for the Movie object.
*/
Movie::~Movie() {}

/*
---------------------getTitle----------------
This method returns the title of the Movie object.
*/
std::string Movie::getTitle() {
    return title;
}

/*
---------------------getStock----------------
This method returns the stock of the Movie object.
*/

int Movie::getStock() {
    return stock;
}

/*
---------------------increaseStock----------------
This method increments the stock of the Movie object by 1.
*/

void Movie::increaseStock() {
    stock += 1;
}

/*
---------------------decreaseStock----------------
This method decrements the stock of the Movie object by 1.
*/
void Movie::decreaseStock() {
    stock -= 1;
}

/*
---------------------getDirector----------------
This method returns the director of the Movie object.
*/
std::string Movie::getDirector() {
    return director;
}

/*
---------------------getReleaseYear----------------
This method returns the release year of the Movie object.
*/
int Movie::getReleaseYear() {
    return releaseYear;
}

/*
---------------------operator==----------------
This method checks if two Movie objects are equal.
It takes in a reference to another Movie object as a parameter.
It returns true if the title, director, releaseYear, and type of the two objects are equal; otherwise, it returns false.
*/
bool Movie::operator==(const Movie& other) const {
    return (title == other.title && director == other.director && releaseYear == other.releaseYear && type == other.type);
}

/*
---------------------getType----------------
This method returns the type of the Movie object.
It returns 'M' (for movie) for the base Movie class.
*/
char Movie::getType() {
    return 'M';
}

/*
---------------------getInfo----------------
This method returns a string containing information about the Movie object.
It returns a string with the title, director, and release year of the movie.
*/
std::string Movie::getInfo() {
    return getTitle() + ", " + getDirector() + ", " + std::to_string(getReleaseYear());
}
