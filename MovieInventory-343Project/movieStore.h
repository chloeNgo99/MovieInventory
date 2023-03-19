#ifndef MOVIESTORE_H
#define MOVIESTORE_H

#include <fstream>
#include <iostream>
#include <string>
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include "moviehashtable.h"
#include "customer.h"
#include "transaction.h"
#include <sstream>
using namespace std; 

class MovieStore {
public:
    void buildMovie(std::ifstream &file);
    void buildCustomer(std::ifstream &file);
    void readCommand(std::ifstream &file);
    void printMovieInventory();
    void printTransaction(int );
private:
    void updateMovieStore(std::stringstream&) const;
    void updateTransaction(int customerID, char action, string title) const;
};

#endif
