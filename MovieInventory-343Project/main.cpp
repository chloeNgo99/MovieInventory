// -----------------------main.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;
#include "movieStore.h"

int main()
{ 
    ifstream movie("data4movies.txt");
    if (!movie) {
        cout << "Could not open movie file." << endl;
        return 1;
    }
    
    ifstream file("data4commands.txt");
    if (!file) {
        cout << "Could not opened command file" << endl;
        return 1;
    }

    ifstream customerFile("data4customers.txt");
    if (!customerFile) {
        cout << "Could not open movie file." << endl;
        return 1;
    }
  
    MovieStore store;
    store.buildMovie(movie);
    store.buildCustomer(customerFile);
    store.readCommand(file);
    cout << "------End Program------";
    return 0;
}


