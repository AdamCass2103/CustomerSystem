#include <iostream>
#include <fstream>
#include <vector>
#include "customer.h"

std::vector<Customer> customers;

void addCustomer() {
    int id;
    std::string name, email, address;
    std::vector<int> purchases;
    int count;

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    std::cout << "Enter address: ";
    std::getline(std::cin, address);

    std::cout << "Number of purchases: ";
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        int purchase;
        std::cout << "Purchase " << i + 1 << ": ";
        std::cin >> purchase;
        purchases.push_back(purchase);
    }

    customers.emplace_back(id, name, email, address, purchases);
}

void displayCustomers() {
    for (const auto& c : customers) {
        std::cout << c << std::endl;
    }
}

void saveToFile() {
    std::ofstream file("customers.txt");
    for (const auto& c : customers) {
        file << c << std::endl;
    }
    file.close();
}

void loadFromFile() {
    std::ifstream file("customers.txt");
    Customer c;
    customers.clear();
    while (file >> c) {
        customers.push_back(c);
    }
    file.close();
}

int main() {
    int choice;
    do {
        std::cout << "\n1. Add Customer\n2. Display All\n3. Load from File\n4. Save to File\n0. Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: displayCustomers(); break;
            case 3: loadFromFile(); break;
            case 4: saveToFile(); break;
        }
    } while (choice != 0);

    return 0;
}
