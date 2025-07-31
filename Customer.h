#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <string>

class Customer {
private:
    int customerId;
    std::string title;
    std::string name;
    std::string type;
    std::vector<int> purchases;

public:
    Customer();
    Customer(int id, std::string title, std::string name, std::string type, std::vector<int> purchases);
    Customer(const Customer& other);
    Customer& operator=(const Customer& other);
    ~Customer();

    int getId() const;
    std::string getName() const;
    std::string getType() const;

    void setName(const std::string& name);
    void setType(const std::string& type);

    bool operator==(const Customer& other) const;
    bool operator!=(const Customer& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
    friend std::istream& operator>>(std::istream& is, Customer& c);
};

#endif
