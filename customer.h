#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>

class Customer {
private:
    int id;
    std::string name;
    std::string email;
    std::string address;
    std::vector<int> purchaseHistory;

public:
    Customer(); // default constructor
    Customer(int id, std::string name, std::string email, std::string address, std::vector<int> history);
    Customer(const Customer& other); // copy constructor
    ~Customer();

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getAddress() const;
    std::vector<int> getPurchaseHistory() const;

    void setName(std::string name);
    void setEmail(std::string email);
    void setAddress(std::string address);
    void setPurchaseHistory(std::vector<int> history);

    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
    friend std::istream& operator>>(std::istream& is, Customer& c);
};

#endif
