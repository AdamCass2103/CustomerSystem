#include "Customer.h"
#include <sstream>

Customer::Customer() : customerId(0), title(""), name(""), type("") {}

Customer::Customer(int id, std::string title, std::string name, std::string type, std::vector<int> purchases)
    : customerId(id), title(title), name(name), type(type), purchases(purchases) {}

Customer::Customer(const Customer& other)
    : customerId(other.customerId), title(other.title), name(other.name), type(other.type), purchases(other.purchases) {}

Customer& Customer::operator=(const Customer& other) {
    if (this != &other) {
        customerId = other.customerId;
        title = other.title;
        name = other.name;
        type = other.type;
        purchases = other.purchases;
    }
    return *this;
}

Customer::~Customer() {}

int Customer::getId() const { return customerId; }
std::string Customer::getName() const { return name; }
std::string Customer::getType() const { return type; }

void Customer::setName(const std::string& name) { this->name = name; }
void Customer::setType(const std::string& type) { this->type = type; }

bool Customer::operator==(const Customer& other) const {
    return customerId == other.customerId;
}

bool Customer::operator!=(const Customer& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Customer& c) {
    os << c.customerId << ";" << c.title << ";" << c.name << ";" << c.type << ";" << c.purchases.size();
    for (int p : c.purchases) {
        os << ";" << p;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Customer& c) {
    std::string line;
    if (getline(is, line)) {
        std::stringstream ss(line);
        std::string item;
        getline(ss, item, ';');
        c.customerId = stoi(item);
        getline(ss, c.title, ';');
        getline(ss, c.name, ';');
        getline(ss, c.type, ';');
        getline(ss, item, ';');
        int count = stoi(item);
        c.purchases.clear();
        for (int i = 0; i < count; ++i) {
            getline(ss, item, ';');
            c.purchases.push_back(stoi(item));
        }
    }
    return is;
}
