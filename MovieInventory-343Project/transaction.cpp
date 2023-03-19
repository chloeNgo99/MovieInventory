// -----------------------transaction.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include "transaction.h"

/*
Transaction constructor initializes an instance of Transaction class.
*/
Transaction::Transaction() {
}

/*
---------------------Transaction Destructor---------------------
This is the destructor of the Transaction class. It iterates over all of the linked lists in the hash table and deletes each Customer object pointer contained in each list. This is necessary to prevent memory leaks and to ensure that all dynamically allocated memory is properly freed. 
*/
Transaction::~Transaction() {
  for (int i = 0; i < TABLE_SIZE; ++i) {
    for (auto* customer : table[i]) {
      delete customer;
    }
  }
}

/*
---------------------hashFunction-----------------
This is a helper function for the Transaction class that takes an integer value representing a customer ID as its input parameter and returns an integer value representing the corresponding index in the hash table
for the given ID. The hash function calculates the modulus of the ID value by the size of the hash table to obtain the index. This ensures that each customer ID maps to a unique index in the hash table. The hash table uses chaining to handle collisions, so multiple customer IDs may map to the same index.
*/
int Transaction::hashFunction(int id) {
  return id % TABLE_SIZE;
}

/*
---------------------insertCustomer-----------------
Inserts a new customer into the hash table. First, it calculates the index to insert the customer by passing the customer ID to the hashFunction. Then, it adds the customer pointer to the linked listat that index.
*/
void Transaction::insertCustomer(Customer *customer) {
  int id = customer->getCustomerID();
  int index = hashFunction(id);
  table[index].push_back(customer);
}

/*
---------------------getCustomer----------------
This method takes an integer ID as a parameter and uses it to search for a Customer object in the hash table. The ID is used to determine which index of the table to search for the customer. The method then iterates through the linked list at the index, comparing the ID of each customer with the input ID until a match is found or the end of the list is reached. If a match is found, the method returns a pointer to the Customer object. If no match is found, the method returns a nullptr.
*/
Customer *Transaction::getCustomer(int id) {
  int index = hashFunction(id);

  for (Customer *customer : table[index]) {
    if (customer->getCustomerID() == id) {
      return customer;
    }
  }

  return nullptr; // Customer not found
}

/*
---------------------update----------------
Updates the customer transaction history by adding a new title and action to the customer's record.
*/
void Transaction::update(int customerId, const string &title, char action) {
  Customer *customer = getCustomer(customerId);
  if (customer != nullptr) {
    customer->addTitle(title);
    customer->addAction(action);
  } else {
    std::cerr << "Customer not found: " << customerId << std::endl;
  }
}

/*
---------------------printTransactions----------------
This method takes an integer customer ID as a parameter and uses it to search for a Customer object in the hash table
using the getCustomer method. If a match is found, the method prints the customer's ID and full name, as well as a list
of all the movie titles and actions associated with the customer. If no match is found, the method prints an error message
to standard error indicating that the customer was not found.
*/
void Transaction::printTransactions(int customerId) {
  Customer *customer = getCustomer(customerId);
  if (customer != nullptr) {
    std::cout << "ID: " << customer->getCustomerID() << " Name: " << customer->getCustomerFullName() << std::endl;
    auto titles = customer->getTitles();
    auto actions = customer->getActions();
    for (size_t j = 0; j < titles.size(); ++j) {
      std::cout << "  Action: " << actions[j] << " Title: " << titles[j] << std::endl;
    }
  } else {
    std::cerr << "Customer not found: " << customerId << std::endl;
  }
}