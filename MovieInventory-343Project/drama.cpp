// -----------------------drama.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include "drama.h"
#include <typeinfo>

/*
---------------------Drama()----------------
This is a default constructor for the Drama class which initializes a new Drama object with default values for all of its attributes.
It calls the base constructor of the Movie class to initialize the stock, director, title, and releaseYear member variables.
*/
Drama::Drama() : Movie() {}

/*
---------------------Drama()----------------
This is a constructor for the Drama class which initializes a new Drama object with the specified values for its attributes.
It calls the base constructor of the Movie class to initialize the stock, director, title, and releaseYear member variables.
*/
Drama::Drama(int stock, std::string director, std::string title, int releaseYear) : Movie(stock, director, title, releaseYear) {}

/*
---------------------getType----------------
This method returns a character that represents the type of the Movie object. For a Drama object, the character returned is 'D'.
*/
char Drama::getType() {
    return 'D';
}

/*
---------------------getInfo----------------
This method returns a string containing information about the Movie object in a specific format. The format is:
"D, <stock>, <director>, <title>, <releaseYear>"
*/
std::string Drama::getInfo() {
    return std::string(1, getType()) + ", " + to_string(getStock()) + ", " + getDirector() +", " + getTitle() + ", " + to_string(getReleaseYear());
}

/*
---------------------operator==----------------
This overloaded operator compares whether two Movie objects are equal based on their title, director, and releaseYear attributes.
It first checks if the type of the passed-in movie is Drama using the typeid operator. If the passed-in movie is not a Drama, it returns false.
Then, it performs a dynamic_cast to convert the passed-in movie to a Drama object and compares the title, director, and releaseYear attributes of the current Drama object with those of the passed-in Drama object.
Returns true if all the compared attributes are equal, false otherwise.
*/
bool Drama::operator==(const Movie& movie) const {
    if (typeid(movie) != typeid(Drama)) {
        return false;
    }
    const Drama& other = dynamic_cast<const Drama&>(movie);
    return (title == other.title && director == other.director && releaseYear == other.releaseYear);
}
