// -----------------------movieHashTable.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include "moviehashtable.h"

MovieHashTable::MovieHashTable() {}

/*
-----------------MovieHashTable destructor-----------------------
This is a destructor for the MovieHashTable class. It loops through all of the elements 
in the hash table (table) and deletes them one by one. It does this by first looping 
through each index of the table (there are TABLE_SIZE indices) and then looping 
through each element within the vector stored at that index. For each element, 
it calls the delete operator to free up the memory occupied by the movie object. 
This is done to ensure that all memory allocated for the hash table is properly 
cleaned up when the hash table is destroyed or goes out of scope.
*/
MovieHashTable::~MovieHashTable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (unsigned int j = 0; j < table[i].size(); j++) {
      delete table[i][j];
    }
  }
}

/*
-----------------inserMovie function-----------------------
This function inserts a new movie into the movie hash table. It determines the index 
where the movie should be stored in the hash table by calling the hash function based 
on the movie's type, title, director, release year, and major actor. If a movie with the 
same attributes already exists in the table, the function will delete the new movie 
and ignore it. If the movie is not a duplicate, it will be added to the table and 
sorted in the appropriate bucket based on its type using a switch statement.
*/
void MovieHashTable::insertMovie(Movie *movie) {

    int index = 0;
    //type, title, director, releaseYear, majorActor
    //check for each type of the movie and send it to the hash function by it's sorting
    if (movie->getType() == 'F') {
      index = hashFunction('F',movie->getTitle(), "", movie->getReleaseYear(), "");
    }else if (movie->getType() == 'D') {
      index = hashFunction('D',movie->getTitle(), movie->getDirector(), 0, "");
    }else if (movie->getType() == 'C') {
      Classic* classicMovie = dynamic_cast<Classic*>(movie);
      index = hashFunction('C', "", "", classicMovie->getReleaseDate(), classicMovie->getMajorActorFullName());
    }
    bool duplicate = false;
    
    //if find duplicate, ignore this and delete the movie
    for (unsigned int i = 0; i < table[index].size(); i++) {
        if (*(table[index][i]) == *movie) {
            delete movie;
            duplicate = true;
            break;
        }
    } 
    
    //if no duplivate, add it to the table 
    if (!duplicate) {
        table[index].push_back(movie);
        // Sort the bucket according to the movie type's sorting method
        switch (movie->getType()) {
            case 'F':
                sortComedyBucket(table[index]);
                break;
            case 'D':
                sortDramaBucket(table[index]);
                break;
            case 'C': {
                sortClassicBucket(table[index]);
                break;
            }
            default:
                // Shouldn't get here
                break;
        }
    }
}

/*
-----------------sortComedyBucket function-----------------------
This function is used to sort a vector of Movie objects that belong to the Comedy genre. 
The function takes a reference to the vector as an argument and uses the std::sort algorithm 
to sort the vector in ascending order based on the movie's title and release year. 
It uses a lambda function to compare two Movie pointers and return true if the first 
Movie should come before the second Movie in the sorted vector. If the two Movies have the same title, 
then the one with the earlier release year will come first. The sorted vector is updated in place.
For example, let cosider these 2 movie:
Drama(10, "Phillippe De Broca", "King of Hearts", 1967));
Drama(10, "Steven Spielberg", "Schindler's List", 1993));
They both have the same key which is 9, but K comes before S in alphabet order. Therefore, the bucket
at this table index will be sorted accordingly.
*/
void MovieHashTable::sortComedyBucket(std::vector<Movie*>& bucket) {
    std::sort(bucket.begin(), bucket.end(), [](Movie* a, Movie* b) {
        if (a->getTitle() != b->getTitle()) {
            return a->getTitle() < b->getTitle();
        }
        return a->getReleaseYear() < b->getReleaseYear();
    });
}


/*
-----------------sortDramaBucket function-----------------------
This function sorts a vector of pointers to Movie objects that belong to the Drama category. 
The sorting is done using the std::sort function with a lambda function as the comparator. 
The lambda function compares two pointers to Movie objects by their director names and then 
by their titles in case of ties. The function assumes that the vector passed to it only contains 
pointers to Movie objects of the Drama category.
*/
void MovieHashTable::sortDramaBucket(std::vector<Movie*>& bucket) {
    std::sort(bucket.begin(), bucket.end(), [](Movie* a, Movie* b) {
        if (a->getDirector() != b->getDirector()) {
            return a->getDirector() < b->getDirector();
        }
        return a->getTitle() < b->getTitle();
    });
}

/*
-----------------sortClassicBucket function-----------------------
This function sorts a vector of Movie pointers that represents a bucket of Classic movies in the 
movie hash table. It uses a lambda function to define the sorting criteria. The sorting criteria 
first compares the release year of the movies, then the release month, then the last name of the 
major actor, and finally the first name of the major actor. The function assumes that all the 
pointers in the vector are pointing to Classic objects, so it uses dynamic_cast to downcast them 
to Classic pointers in order to access the Classic-specific attributes used for sorting.
*/
void MovieHashTable::sortClassicBucket(std::vector<Movie*>& bucket) {
    std::sort(bucket.begin(), bucket.end(), [](Movie* a, Movie* b) {
        if (typeid(*a) == typeid(Classic) && typeid(*b) == typeid(Classic)) {
            Classic* classicA = dynamic_cast<Classic*>(a);
            Classic* classicB = dynamic_cast<Classic*>(b);
        
            if (classicA->getReleaseDate() != classicB->getReleaseDate()) {
                return classicA->getReleaseDate() < classicB->getReleaseDate();
            }
            return classicA->getMajorActorFullName() < classicB->getMajorActorFullName();
        }
        return false;
    });
}

/*
-------------------------searchMovie function-----------------------

*/
Movie* MovieHashTable::searchMovie(char type, string title, string director, int releaseYear, string majorActor){
    int index = 0;
    //type, title, director, releaseYear, majorActor
    //check for each type of the movie and send it to the hash function by it's sorting
    if (type == 'F') {
      index = hashFunction('F',title, "", releaseYear, "");
    }else if (type == 'D') {
      index = hashFunction('D',title, director, 0, "");
    }else if (type == 'C') {
      index = hashFunction('C', "", "", releaseYear, majorActor);
      //cout << "searchMovie index: " << index << endl;
    }
    
    // Search for the movie in the hash table
    for (const auto &movie : table[index]) {
        if (type == 'F') {
            if (movie->getTitle() == title && movie->getReleaseYear() == releaseYear) {
                return movie;
            }
        }else if (type == 'D') {
            if (movie->getTitle() == title && movie->getDirector() == director) {
                return movie;
            }
        }else if (type == 'C') {
            Classic* classicMovie = dynamic_cast<Classic*>(movie);
            if(classicMovie == nullptr){
                continue;
            }else{
                string actorFullName = classicMovie->getMajorActorFullName();
                string movieRelaseDate = to_string(classicMovie->getReleaseMonth()) + to_string(classicMovie->getReleaseYear());
                if (movieRelaseDate == to_string(releaseYear) && actorFullName == majorActor) {
                    return movie;
                }
            }
        }
    }
    return nullptr;
}

void MovieHashTable::adjustStock(char action,char type, string title, string director, int releaseYear, string majorActor){
    //cout << "adjustStock" << endl;
    Movie* movie = searchMovie(type, title, director, releaseYear, majorActor);
    if(movie != nullptr){
        if(action == 'R'){
            movie->increaseStock();
        }else if(action == 'B'){
            if(movie->getStock() > 0){
              movie->decreaseStock();
            }else{
              cout << movie->getTitle() << " is out of stock" << endl;
            } 
        }
        //cout << "Success adjust the stock" << endl;
    }
}

/*
-----------------hashFunction function-----------------------
This is a member function of the MovieHashTable class that implements the hash function 
used to map movie objects to indices in the hash table. The function takes in several parameters, 
including the movie type ('F' for comedy, 'D' for drama, and 'C' for classic), the movie title, director, 
release year, and major actor's name. The function uses a switch statement to determine the type of 
the movie and then applies a different hashing algorithm based on the type.
*/
int MovieHashTable::hashFunction(char type, string title, string director, int releaseYear, string majorActor) {
    int index = -1;
    //cout <<"Title " << title << endl;
    switch (type) { 
        case 'F': // Comedy
            index = (hashString(title) + releaseYear) % TABLE_SIZE;
            break;
        case 'D': // Drama
            index = (hashString(director) * 2 + hashString(title)) % TABLE_SIZE;
            break;
        case 'C': // Classic
            index = (releaseYear + hashString(majorActor)) % TABLE_SIZE;
            break;
        default:
            // Invalid type
            break;
    }

    return index;
}

/*
-----------------hashString function-----------------------
This is a member function of the MovieHashTable class that implements a simple hash function for 
strings. The function takes in a string as a parameter and computes a hash value based on the 
characters in the string. The function uses a for loop to iterate over each character in the 
input string. For each character, the function multiplies its ASCII value by 3 and adds the 
result to the running hash value. The hash value is then returned as an integer.
*/
int MovieHashTable::hashString(string str) {
    int hash = 0;
    for (char c : str) {
        c *= 3;
        hash = hash + c;
    }
    //cout << "hash: " << abs(hash) << endl;
    return abs(hash);
}

/*
-----------------printInventory function-----------------------
This is a member function of the MovieHashTable class that prints the inventory 
of movies stored in the hash table to the console. The function iterates over 
each bucket in the hash table, and then iterates over each movie object in each bucket.
*/
void MovieHashTable::printInventory(char type) const {
  for (const auto &bucket : table) {
    for (const auto &movie : bucket) {
      if(movie->getType() == type){
        cout << movie->getInfo() << endl;
      }
    }
  }
}
