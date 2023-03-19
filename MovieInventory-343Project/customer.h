#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
using namespace std;

class Customer {
public:
  Customer();
  Customer(int id, string lastName, string firstName);

  int getCustomerID();
  string getCustomerFullName();
  void addTitle(const string &title);
  vector<string> getTitles() const;
  void addAction(const char &action);
  vector<char> getActions() const;

private:
  int id;
  string lastName;
  string firstName;
  vector<string> titles;
  vector<char> actions;
};

#endif
