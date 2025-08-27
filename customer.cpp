#include "customer.h"
#include <sstream>

Customer::Customer() : id(0), name(""), email(""), address(""), purchaseHistory({}) {}

Customer::Customer(int id, std::string name, std::string email, std::string address, std::vector<int> history)
    : id(id), name(std::move(name)), email(std::move(email)), address(std::move(address)), purchaseHistory(std::move(history)) {}

Customer::Customer(const Customer& other)
    : id(other.id), name(other.name), email(other.email), address(other.address), purchaseHistory(other.purchaseHistory) {}

Customer::~Customer() {}

int Customer::getId() const { return id; }
std::string Customer::getName() const { return name; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getAddress() const { return address; }
std::vector<int> Customer::getPurchaseHistory() const { return purchaseHistory; }

void Customer::setName(std::string n) { name = std::move(n); }
void Customer::setEmail(std::string e) { email = std::move(e); }
void Customer::setAddress(std::string a) { address = std::move(a); }
void Customer::setPurchaseHistory(std::vector<int> h) { purchaseHistory = std::move(h); }

std::ostream& operator<<(std::ostream& os, const Customer& c) {
    os << c.id << "," << c.name << "," << c.email << "," << c.address;
    for (int purchase : c.purchaseHistory) {
        os << "," << purchase;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Customer& c) {
    std::string line;
    if (std::getline(is, line)) {
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, ',');
        c.id = std::stoi(token);
        std::getline(ss, c.name, ',');
        std::getline(ss, c.email, ',');
        std::getline(ss, c.address, ',');
        c.purchaseHistory.clear();
        while (std::getline(ss, token, ',')) {
            c.purchaseHistory.push_back(std::stoi(token));
        }
    }
    return is;
}
