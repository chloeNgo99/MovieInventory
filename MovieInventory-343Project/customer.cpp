// -----------------------customer.cpp---------------------------
// Chloe Ngo & Morrison Young CSS343
// 03/08/2023
// -----------------------------------------------------------------
#include "customer.h"

/*
---------------------Customer Constructor-----------------
This constructor initializes a Customer object with default values or with the specified ID, last name, and first name.
*/
Customer::Customer() : id(0), lastName(""), firstName("") {}

Customer::Customer(int id, string lastName, string firstName)
    : id(id), lastName(lastName), firstName(firstName) {}


/*
---------------------getCustomerID-----------------
This method returns the integer ID associated with this Customer object.
*/
int Customer::getCustomerID() {
  return this->id;
}

/*
---------------------getCustomerFullName-----------------
This method returns the first and last name associated with this Customer object.
*/
string Customer::getCustomerFullName() {
  return firstName + " " + lastName;
}

/*
---------------------addTitle----------------
This method takes a constant reference to a string as a parameter and adds it to the vector of titles owned by the
customer object. The title is added to the end of the vector.
*/
void Customer::addTitle(const string &title) {
  titles.push_back(title);
}

/*
---------------------getTitles----------------
This method returns a vector of strings that contains all the titles associated with the customer. It retrieves
the vector of titles stored in the titles member variable and returns it.
*/
vector<string> Customer::getTitles() const {
  return titles;
}

/*
---------------------addAction----------------
This method takes a character action as a parameter and adds it to the actions vector of the customer object.
The actions vector keeps track of the actions taken by the customer, such as borrowing or returning a title.
The method simply appends the action character to the end of the vector.
*/
void Customer::addAction(const char &action) {
  actions.push_back(action);
}

/*
---------------------getActions----------------
This method returns a vector of chars that represent the actions performed by the customer on the titles they have checked out.
It retrieves the vector of actions from the private member variable 'actions' of the Customer object.
*/
vector<char> Customer::getActions() const {
  return actions;
}
