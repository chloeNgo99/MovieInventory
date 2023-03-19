// -----------------------comedy.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include "comedy.h"
#include <typeinfo>

/*
---------------------Comedy Constructor----------------
This constructor initializes a new Comedy object with the provided parameters by calling the base class constructor with the parameters for the stock, director, title, and release year.
*/
Comedy::Comedy(int stock, std::string director, std::string title, int releaseYear) : Movie(stock, director, title, releaseYear) {}

/*
---------------------getType----------------
This method returns a char that represents the type of the Comedy object. For the Comedy class, the type is always 'F'.
*/
char Comedy::getType() {
    return 'F';
}

/*
---------------------getInfo----------------
This method returns a string that contains information about the Comedy object, including its type, stock count, director, title, and release year.
*/
std::string Comedy::getInfo() {
    return std::string(1, getType()) + ", " + to_string(getStock()) + ", " + getDirector() +", " + getTitle() + ", " + to_string(getReleaseYear());
}

/*
---------------------operator==----------------
This method compares the current Comedy object with another Movie object to determine if they are equal.
*/
bool Comedy::operator==(const Movie& movie) const {
    if(typeid(movie) != typeid(Comedy)) {
        return false;
    }
    const Comedy& other = static_cast<const Comedy&>(movie);
    return (title == other.title && director == other.director && releaseYear == other.releaseYear);
}