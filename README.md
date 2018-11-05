# HW9-Dynamic-Arrays-C-
This homework assignment gives you the opportunity to practice structures, classes, dynamic array creation, use of overloaded operators. Your program will read from an input file that contains account records. Each account record starts with a delimiter, which is the ‘#’ character, followed by the account number, followed by the number of owners, followed by one or more owner records (there is one record for each owner), followed by the number of transactions, followed by one or more transaction records (there is one record for each transaction). An owner record consists of the owner’s name followed by the owner’s DOB in mm/dd/yyyy format, followed the owner’s address. A transaction record consists of the transaction date, followed by the transaction type (1 for account creation, 2 for deposit, and 3 for withdrawal), followed by the amount. The various fields are separated by a white space, except for the owner’s name and address, which are surrounded by a new line. Below is an example of account record. The // comments are added for clarification, but are not part of the file content. 

# Input File
'#' (Github is weird with using # so take off the '' from around the hashtag for input)
1200 // account number 
2 // number of owners 
Kirk // owner’s name 
02/12/2200 // owner’s DOB 
Enterprise // owner’s address 
Mr. Spock // owner’s name 
03/13/2300 // owner’s DOB 
Galaxy Way // owner’s address 
2 // number of transactions 
02/15/2320 3 100 // first transaction record 
02/11/2320 1 200 // second transaction record 

Your program should determine the number of account records in the file, dynamically create an array of Account of size equal to the number of account records (note this is an array of Account, not an array of pointers to Account), and populate the array with the data read from the file. Finally it should display for each account, the owner’s data and the transactions data sorted according to their dates (the oldest transaction should be listed first). Your program should implement the following: 

# 1. Date class 
This class is as defined in HW8, implement in-line in Date.h 
# 2. Account class 
This class is adapted from HW7. The additions with respect to HW7 are in boldface italics. Implement in-line in Account.h struct 

Transaction {  Date transactionDate;  int type;  double amount; }; 
struct Person {  string name;  Date DOB;  string address; }; 

The class Account has the following private member variables:  
accountNumber of type int  numOwners of type int  
ownerPtr of type Person *  
balance of type double  
numTransactions of type int // Number of transactions for the account  
transacPtr of type Transaction * // Pointer to an array that holds the Transactions 

and the following public member functions:  
  void setOwner(int, Person): as in HW7  
  Person getOwner(int) const: as in HW7 
  int getAccountNumber() const: as in HW7 
  double getBalance() const: as in HW7 
  int getNumOwners() const: as in HW7 

The public member functions new with respect to HW7 are defined as follows. 
- void set(int accountNumber_, int numOwners_): mutator that sets the accountNumber and numOwners, dynamically creates an array of Person of size numOwners, and assign to ownerPtr. Sets balance to zero. 
- void setTransacPtr(Transaction * transacPtr_): mutator that sets transacPtr to transacPtr_ 
- int getNumTransactions() const: accessor for numTransactions  void setNumTransactions(int numTransactions_): mutator that sets numTransactions to numTransactions_ 
- Transaction getTransaction(int ind) const: accessor that returns the Transaction at index ind of the transacPtr array 

# 3. Stand-alone Functions (in main.cpp) 
You should implement the following stand-alone functions. 
/* This function takes as argument a string representing a date in the mm/dd/yyyy format and returns the month as an int The argument string is assumed properly formatted and no input validation is required */ int getMonth(string d) {  // Function body } /* This function takes as argument a string representing a date in the mm/dd/yyyy format and returns the day as an int The argument string is assumed properly formatted and no input validation is required */ int getDay(string d) {  // Function body } /* This function takes as argument a string representing a date in the mm/dd/yyyy format and returns the year as an int The argument string is assumed properly formatted and no input validation is required */ int getYear(string d) {  // Function body } /* This function reads from an account file and populates an array of Account objects (not an array of pointers to Account) with all the owners and transactions data read from the file. The owner data is the owner’s name, DOB and address. The transaction data is the transaction date, transaction type (account creation, deposit, withdrawal), and transaction amount. For each account, the function should dynamically allocate an array of Transaction of size equal to the number of transactions, assign the array’s address to transacPtr, and populate the array with the transaction data. In the array, the transactions should be sorted by date (oldest first). It takes as arguments the file name, the array and the size of the array. It returns true if file open is successful, false otherwise. It should close the file when done */ bool readAccounts(string fname, Account accntPtr [], int numAccnts) {  // Function body } /* This function reads from a file to determine the number of accounts It returns -1 if file open is unsuccessful, else it returns the number of accounts */ int determineNumAccounts(string fname) {  // Function body } 4. Outline of main Call determineNumAccounts to determine the number of account records in the file Dynamically create an array of Account of size equal to the number of accounts, to hold the Account objects (note this is an array of Account, not an array of pointers to Account), Call readAccounts to read data from the file and populate the array of Accounts. Read the populated array of Accounts to display for each account the account number, along with the data for all the owners, and the data for all the transactions. The owner data is the owner’s name, DOB and address. The transaction data is the transaction date, transaction type (account creation, deposit, withdrawal), and transaction amount. Additionally, the new balance resulting from each transaction is displayed. The transactions should be listed by date, the oldest transaction being listed first.
