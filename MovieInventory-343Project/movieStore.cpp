// -----------------------movieStore.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include "movieStore.h"

MovieHashTable table;
Transaction transactions;

/*
---------------------buildMovie---------------
This is a method that reads a file and creates movie objects based on the contents of the file. 
The method takes an ifstream object as a parameter, which represents the input file to be read. 
It then reads each line of the file and parses the values from each line to create a movie object 
of the appropriate type (drama, comedy, or classic) and inserts it into a hash table. The parsing 
is done using the stringstream class to separate the comma-separated values in each line. Once a 
movie object is created, it is inserted into the hash table using the insertMovie method of the 
MovieHashTable class. The method continues reading lines from the file until there are no more lines to read.
*/
void MovieStore::buildMovie(ifstream &file){
    string line, title, director, stock, releaseYear;
    char type;

    while(getline(file, line)){
        if(line[0] == 'D'){ //7 drama movie
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            getline(ss >> ws, stock, ','); 
            getline(ss >> ws, director, ','); 
            getline(ss >> ws, title, ','); 
            getline(ss >> ws, releaseYear); 
            Drama* drama = new Drama(stoi(stock), std::string(director), std::string(title), stoi(releaseYear));
            table.insertMovie(drama);
        } else if(line[0] == 'F'){ //7 comedy movies
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            getline(ss >> ws, stock, ','); 
            getline(ss >> ws, director, ','); 
            getline(ss >> ws, title, ','); 
            getline(ss >> ws, releaseYear); 
            Comedy* comedy = new Comedy(stoi(stock), std::string(director), std::string(title), stoi(releaseYear));
            table.insertMovie(comedy);
        } else if(line[0] == 'C'){ //14 classic movies
            string majorLastName, majorFirstName, majorAndReleaseDate, majorActorFullName;
            int releaseMonth;
            stringstream ss(line);
            string token;
            getline(ss, token, ','); // consume type character
            getline(ss >> ws, stock, ','); 
            getline(ss >> ws, director, ','); 
            getline(ss >> ws, title, ',');
            getline(ss >> ws, majorAndReleaseDate); 
            stringstream ss_major(majorAndReleaseDate);
            ss_major >> majorFirstName >> majorLastName >> releaseMonth >> releaseYear;
            majorActorFullName = majorFirstName + " " + majorLastName;
            Classic* classic = new Classic(stoi(stock), std::string(director), std::string(title), std::string(majorActorFullName), releaseMonth, stoi(releaseYear));
            table.insertMovie(classic);
        }
    }
}

/*
---------------------buildCustomer---------------
This is a method that reads a file and creates customer objects based on the contents of the file.
The method takes an ifstream object as a parameter, which represents the input file to be read.
It then reads each line of the file and parses the values from each line to create a customer object
with the given ID and name. The parsing is done using the stringstream class to separate the
space-separated values in each line. Once a customer object is created, it is inserted into the
Transaction table using the insertCustomer method of the TransactionHashTable class. The method
continues reading lines from the file until there are no more lines to read.
*/
void MovieStore::buildCustomer(ifstream &file) {
  string line, lastName, firstName;
  int id;

  while (getline(file, line)) {
    stringstream ss(line);

    if (ss >> id >> lastName >> firstName) {
      Customer *customer = new Customer(id, lastName, firstName);
      // Insert the customer into the Transaction table or any other data structure
      // For example, if you have a Transaction object named 'transactions':
      transactions.insertCustomer(customer);
    }
  }
}


/*
---------------------readCommand-----------------
This function extract data from the data4command and check whether the action is Borrow,
Return, Inventory or History. If the action is type I or H, it will display the movieStore
current inventory or a specific customer transaction history. If the action is B or R, it 
will call the updateMovieStore and updateTransaction.
*/
void MovieStore::readCommand(ifstream &file){
    string line;
     while(getline(file, line)){ //adjust movie stock 
        if(line[0] == 'B' || line[0] == 'R'){
            stringstream ss(line);
            updateMovieStore(ss);
        }else if(line[0] == 'I'){//display inventory
            cout << "----------------------Display Movie Inventory--------------------------" << endl;
            printMovieInventory();
        }else if(line[0] == 'H'){//display customer history transaction
          cout << "----------------------Display Customer Transaction--------------------------" << endl;
          int id = 0;
          stringstream ss(line.substr(1)); // Create a stringstream with the part of the line after the 'H'
          ss >> id; // Extract the id from the stringstream
          printTransaction(id);
        }else{
          cout <<"Invalid Action " << line[0] << endl;
        }
    }
}

/*
---------------------updateMovieStore-----------------
This function takes a stringstream as input and updates the movie inventory based on the 
information in the stringstream. It reads the action, customer ID, media type, and movie 
type from the stringstream, and then based on the movie type (F for comedy, D for drama, 
C for classic), it extracts additional information such as title, director, release date, 
and major actor name. It then calls the adjustStock function of the movie inventory table 
to update the stock of the movie.
*/
void MovieStore::updateMovieStore(stringstream& ss) const{
    char action, type, media;
    string line, title, director, releaseAndActor, releaseYear, token, customerId, stock;
    ss >> action >> customerId >> media >> type;
    if(type == 'F'){
        getline(ss >> ws, title, ',');
        getline(ss >> ws, releaseYear, ',');
      
        if(table.searchMovie(type, title, "", stoi(releaseYear), "") != nullptr){
          Movie *movie = table.searchMovie(type, title, "", stoi(releaseYear), "");
          if(movie->getStock() > 0){
            updateTransaction(stoi(customerId), action, title);
          }
        }
      
        table.adjustStock(action, type, title, "", stoi(releaseYear), "");
      
    }else if(type == 'D'){
        getline(ss >> ws, director, ',');
        getline(ss >> ws, title, ',');
      
        if(table.searchMovie(type, title, director, 0, "") != nullptr){
          Movie *movie = table.searchMovie(type, title, director, 0, "");
          if(movie->getStock() > 0){
            updateTransaction(stoi(customerId), action, title);
          }
        }
        
      table.adjustStock(action, type, title, director, 0, "");
      
    }else if(type == 'C'){
        string majorFirstName, majorLastName, releaseDate, majorActorFullName;
        int releaseMonth;
        getline(ss >> ws, releaseAndActor, ',');
        stringstream ss_major(releaseAndActor);
        ss_major >> releaseMonth >> releaseYear >> majorFirstName >> majorLastName;
        releaseDate = to_string(releaseMonth) + releaseYear;
        majorActorFullName = majorFirstName + " " + majorLastName;

        if(table.searchMovie(type, "", "", stoi(releaseDate), majorActorFullName) != nullptr){
          Movie *movie = table.searchMovie(type, "", "", stoi(releaseDate), majorActorFullName);
          if(movie->getStock() > 0){
            updateTransaction(stoi(customerId), action, movie->getTitle());
          }
        }
        table.adjustStock(action, type, "", "", stoi(releaseDate), majorActorFullName);
    }
  
}


/*
---------------------updateTransaction-----------------
This method updates the transaction history of a customer based on a specific action and movie title.
The method takes a customer ID, an action (borrow or return), and a movie title as parameters.
It then calls the update method of the TransactionHashTable class to update the transaction history of the
customer with the specified ID based on the specified action and movie
title.
*/
void MovieStore::updateTransaction(int customerId, char action, string title) const{
  //cout << customerId << " " << action << " " << title << endl;
  transactions.update(customerId, title, action);
}

/*
---------------------updateMovieStore-----------------
print the hashtable inventory
*/
void MovieStore::printMovieInventory(){
    table.printInventory('C');
    table.printInventory('D');
    table.printInventory('F');
    cout << endl;
}


/*
---------------------printTransaction-----------------
This method prints the transaction history of a customer based on their ID. It takes a customer ID as a
parameter and prints the transaction history of the customer using the printTransactions method of the
TransactionHashTable class.
*/
void MovieStore::printTransaction(int customerId){
  transactions.printTransactions(customerId);
  cout << endl;
}
