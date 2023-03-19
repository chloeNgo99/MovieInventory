# MovieInventory

## Description:

A local movie rental store wishes to automate their inventory tracking system. Currently there are three types of movies/videos (in DVD media) to be tracked:
- **Comedy** (denoted as **‘F’** for funny)
- **Drama** (denoted as **‘D’**)
- **Classics** (denoted as **‘C’**)
Borrows and returns of items by customers are also to be tracked. Four types of actions are desired in the system:
- **Borrow** (denoted as **‘B’**): (stock – 1) for each item borrowed
- **Return** (denoted as **‘R’**): (stock + 1) for each item returned
- **Inventory** (denoted as **‘I’**): outputs the inventory of all the items in the store
- History (denoted as ‘H’): outputs all the transactions of a customer
You will design and implement a program that will initialize the contents of the inventory from a file (**data4movies.txt**), the customer list from another file (data4customers.txt), and then process an arbitrary sequence of commands from a third file (**data4commands.txt**).

### Details

In **data4movies.txt**, the information about each movie is listed as follows:
- For comedy movies: **F**, Stock, Director, Title, Year it released
- For drama movies: **D**, Stock, Director, Title, Year it released
- For classics movies: **C**, Stock, Director, Title, **Major actor Release date**
For example:

  F, 10, Nora Ephron, You've Got Mail, 1998
  
  D, 10, Steven Spielberg, Schindler's List, 1993
  
  C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
  
  C, 10, George Cukor, Holiday, Cary Grant 9 1938
  
  Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971
  
  D, 10, Phillippe De Broca, King of Hearts, 1967
  
Important notes **about data4movies.txt**:
- You may assume correct formatting, but codes may be invalid, e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue.
- While the stock for each line is 10, do not assume that is the case in your design and implementation.
- The classical movie type has a different format than the other two. It contains Major actor which is always formatted as two strings, first name and last name, separated by a space. Then the Release date contains month and year information, and no comma (but a space) between Major actor and Release date. In addition, for classical movies, one movie (e.g., Holiday) may have multiple lines so the total stock of this movie will be the sum of all the stocks in the lines about this movie (e.g., 20 for Holiday in the above example).
Example:
**Scenario 1**

C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
C, 10, George Cukor, Holiday, Cary Grant 9 1938

There are 20 total for Holiday initially. If customer wants to borrow Holiday with Hepburn, it will decrease the stock from Hepburn's stock, and the result is

C, 9, George Cukor, Holiday, Katherine Hepburn 9 1938
C, 10, George Cukor, Holiday, Cary Grant 9 1938

**Scenario 2**

C, 0, George Cukor, Holiday, Katherine Hepburn 9 1938
C, 10, George Cukor, Holiday, Cary Grant 9 1938

There are 10 total for holiday initially. If customer wants to borrow Holiday with Hepburn, it is unavailable and ask other alternative (Holiday with Grant) To store the data in the system, the items should be sorted as follows:

- comedy movies (**‘F’**) sorted by Title, then Year it released
- dramas (**‘D’**) are sorted by Director, then Title
- classics (**‘C’**) are sorted by Release date, then Major actor

You can assume that each item is uniquely identified by its complete set of sorting attributes.

**data4customers.txt** contains customer information, one line per customer. Customers have a 4-digit ID number that uniquely identifies them, followed by last name, first name, all separated by a space. For example,
  1111 Mouse Mickey
  1000 Mouse Minnie
You can also assume that this data is formatted correctly.
**data4commands.txt** is used to test your code. The first field is action type (B, R, I, or H). Then the rest of fields are as follows:
- Action types **I**: no more fields
- Action type **H**: one more field **customer ID**. Fields are separated by a space
- Action types **B** and **R**: **customer ID** followed by **type of media** (currently only ‘D’ for
DVD) then **movie type and movie data** (with values of the two sorting attributes, using
comma or space to separate them as in the movie data file). Fields are separated by a space.
For example,
B 1234 D C 9 1938 Katherine Hepburn

B 1234 D F Pirates of the Caribbean, 2003

R 1234 D C 9 1938 Katherine Hepburn

B 1234 D D Steven Spielberg, Schindler's List,

S

H 1234

**X** 1234 Z C 9 1938 Katherine Hepburn

B 1234 D **Y** 2 1971 Ruth Gordon

B **9999** D F Pirates of the Caribbean, 2003

B 1234 D **C 2 1975 Blah Blah**

Again, the data will be formatted correctly, but may include errors.
- You must handle an invalid action code (e.g., ‘X’ in the above example), invalid video code (e.g., ‘Y’), incorrect customer ID (i.e., not found. For example, 9999), and invalid movie (i.e., not found. For example, classic movie in month 2 of 1975 with a "Blah Blah"
title). For bad data, discard the line and notify users.
- You must also handle incorrect commands. For example, a command that makes the number of an item in the inventory goes below zero, a return command when a movie was not borrowed, etc.

**Overall Requirements**: (Please see the grading guideline for more details)
- Do not print output for successful **‘B’** or **‘R’** commands, but print error messages for incorrect data and/or incorrect command. Output for **‘H’** and **‘I’** commands should be neatly formatted with one line per item/transaction. **‘I’** should output all Comedy movies,
then all Dramas, then all Classics. Each category of movies should be ordered according to the **sorting criteria** discussed above. ‘H’ should show a list of DVD transactions of a customer in chronological order (latest to earliest) and specify whether the movie was borrowed or returned.
- You are required to use at least one hash table in this assignment. There are multiple places where they could be used. We will be covering hash tables soon in the class. If you want to get started, the important aspect of hash tables is that they are used for fast lookup of items. For example, if each item can be mapped into a unique number, you can use an array to store the items according to their unique number and look them up in O(1) time. Hash tables usually waste some memory, since not all the array will be filled. However, the waste is not too bad, if you store pointers to items, rather than the items themselves.
- You are required to use inheritance for movie and transactions. If you find you’re using templates a lot, run it by me, as this assignment is designed for you to practice using inheritance.
- There are no other specific requirements for this assignment, but as always it should be well designed (not violate the basic design principles – will be discussed in class), easily extensible, efficiently coded, well documented, etc.

**Design Requirements**

Your design should document the work that needs to be done to complete the assignment. It should be a complete and clear description of how the program is organized. The more time you spend on your design, the less you will spend coding, debugging, and modifying.

Your design should include (at least) the following components **in this order**:
- Overview: This is a short description of the design and how the pieces fit together (the interaction between the classes). Include a description of main (List the objects that you have. Main should be short.)
- Class diagram: This is a UML diagram showing class relationships, including inheritance and composition. You can use Visio or neatly draw this by hand.
- Class descriptions: For each class in the design, describe the data and methods as part of a documented C++ header file (Exception: you do not need to include h files of classes you will not implement, of the extensions beyond the assignment specifications, but you must include a description of those classes). The task that each function performs, and the purpose of each data member should be clearly described. High-level pseudo code should be included for the most important methods (for example, those that control the flow of the program). Not all parameters need to be included for methods. Please order the files properly, i.e., put the most important classes first, put parent classes before children classes.

## Implementation
### Overview:
This program uses inheritance and a hash table data structure to manage and track customer and movie information for a movie store. The Movie class is the base class for the Comedy, Drama, and Classic movie subclasses, which have additional attributes and sorting functions. The program reads input data files to build movie and customer objects and uses a hash table to efficiently store and retrieve movie objects. The program also provides functionality for renting and returning movies and displaying customer transaction history. The Inventory class keeps track of the movie stock and customer rental history through MovieHashTable and CustomerHashtable classes. Overall, this program provides a robust and efficient system for managing a movie store's inventory and customer transactions.

### Description of the Main class:
In the main class, we will create an instance of the MovieStore, then passing each data file to the following function: buildMovie, buildCustomer, buildICommand. After that, we will perform the display Inventory which will display the output after the buildCommand has generated, and displayHistory will generate all the customer transactions output.

### MovieStore class:
The MovieStore class will extract the text file line by line for each of the build functions, in order to start building the customer and movie objects and update the inventory. Additionally, the class will have a displayInventory function to handle the display output of all movie items/objects the store has. Furthermore, the displayHistory function will be responsible for displaying the customer transaction history.

### Inventory class:
The Inventory class represents the inventory system for the movie store. It is responsible for keeping track of the movies that are available for rent and the customers who have rented them. This class contains a hashtable of Movie objects, which are indexed by their unique sorting attributes (e.g., title, director, release date). It also maintains a list of Customer objects who have rented movies from the store. It also provides functions to update the stock of movies when they are rented or returned, to search for movies by their unique sorting attributes, and to handle customer transactions such as renting and returning movies.

### MovieHashTable class:
The MovieHashTable class is responsible for implementing the hash table data structure to efficiently store and retrieve Movie objects. The class provides functions to add a Movie object to the hash table, remove a Movie object from the hash table, retrieve a Movie object by its unique sorting attributes, and display all the Movie objects in the hash table. The class also implements the hash function and collision resolution method necessary for the hash table data structure. The hash function is used to convert a unique sorting attribute of a Movie object into an index in the hash table, and the collision resolution method is used to handle cases where two Movie objects have the same index. Additionally, the class provides overloaded operators to sort the Movie objects in the hash table based on their unique sorting attributes. The sorting behavior differs between the Comedy, Drama, and Classic Movie classes, so each subclass implements its own version of the overloaded operators.

### Movie class:
The movie class is a base class that represents a movie in the movie store system, which has the following attributes: stock, director, title, and year. This class is design as an abstract class for the comedy, drama, and movie subclasses. The Movie class also provides a virtual operator<() method that is used to compare two movies based on their sorting attributes, which is used for sorting the movies in the inventory.

### Comedy class:
The Comedy class is a child class of the Movie class and represents a comedy movie. It contains additional data members specific to comedy movies, such as the comedian name, and implements the sorting function to sort the movies by title and year of release.

### Drama class:
The Drama class is another child class of the Movie class and represents a drama movie. It contains additional data members specific to drama movies, such as the director name, and implements the sorting function to sort the movies by director and title.

### Classic class:
The Classic class is also a child class of the Movie class and represents a classic movie. It contains additional data members specific to classic movies, such as the release date and major actor name, and implements the sorting function to sort the movies by release date and major actor.

### Customer class:
The Customer will manage and process customer data for the movie rental system, providing a structure for organizing and manipulating customer information and transaction history. It will have a default constructor, a constructor that takes an input stream for reading customer data from a file, a copy constructor, and a virtual destructor. It also has member functions for setting customer data, displaying customer transaction history, and adding a new transaction to a customer's history.

### CustomerHashTable class:
A customer hash table is a data structure that can be used to store and retrieve customer information efficiently. We can use the customer ID as the key and store the customer object as the value. This will allow us to quickly retrieve customer information for a given transaction.By using a customer hash table, we can avoid having to search through a list of customers for each transaction, which can be slow for large datasets.

### Transaction class:
The Transaction class is a key component in managing and processing movie rental transactions, providing a structure for organizing and manipulating rental data. It will communicate with the Customer and Inventory classes to handle transactions properly. The class will have a default constructor, a copy constructor, and a virtual destructor. It also has member functions for setting and displaying transaction data, creating a new transaction object, and retrieving information about the transaction, such as the media type, transaction type, and inventory item.

### UML Diagram: uml Link

<img alt="Movie Store Inventory Diagram" src="https://github.com/chloeNgo99/MovieInventory/blob/main/MovieStore_Diagram.png">

## Demo Link
https://replit.com/join/mylezajtpl-chloengo99
