#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <iostream>
#include "customer.h"
using namespace std;

class Transaction {
public:
  Transaction();
  ~Transaction();

  void insertCustomer(Customer *);
  Customer *getCustomer(int id);
  void update(int customerId, const string &title, char action);
  void printTransactions(int);

private:
  static const int TABLE_SIZE = 13;
  std::vector<Customer *> table[TABLE_SIZE];
  int hashFunction(int id);
};

#endif
