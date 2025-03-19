#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Product {
    int id;
    string name;
    int quantity;
    double price;
};


void displayMenu() {
    cout << "\n=== Inventory Management System ===" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. View Inventory" << endl;
    cout << "3. Update Product Quantity" << endl;
    cout << "4. Delete Product" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}


void addProduct(vector<Product> &inventory) {
    Product newProduct;
    cout << "\nEnter Product ID: ";
    cin >> newProduct.id;


    for (const auto &product : inventory) {
        if (product.id == newProduct.id) {
            cout << "Product with this ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Product Name: ";
    cin.ignore(); 
    getline(cin, newProduct.name);
    cout << "Enter Product Quantity: ";
    cin >> newProduct.quantity;
    cout << "Enter Product Price: ";
    cin >> newProduct.price;

    inventory.push_back(newProduct);
    cout << "Product added successfully!" << endl;
}


void viewInventory(const vector<Product> &inventory) {
    if (inventory.empty()) {
        cout << "\nInventory is empty!" << endl;
        return;
    }

    cout << "\n=== Current Inventory ===" << endl;
    for (const auto &product : inventory) {
        cout << "ID: " << product.id << ", Name: " << product.name
             << ", Quantity: " << product.quantity << ", Price: $" << product.price << endl;
    }
}


void updateProductQuantity(vector<Product> &inventory) {
    int id, newQuantity;
    cout << "\nEnter Product ID to update quantity: ";
    cin >> id;

    for (auto &product : inventory) {
        if (product.id == id) {
            cout << "Enter new quantity for product '" << product.name << "': ";
            cin >> newQuantity;
            product.quantity = newQuantity;
            cout << "Quantity updated successfully!" << endl;
            return;
        }
    }

    cout << "Product with ID " << id << " not found!" << endl;
}


void deleteProduct(vector<Product> &inventory) {
    int id;
    cout << "\nEnter Product ID to delete: ";
    cin >> id;

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            cout << "Product deleted successfully!" << endl;
            return;
        }
    }

    cout << "Product with ID " << id << " not found!" << endl;
}

int main() {
    vector<Product> inventory;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                viewInventory(inventory);
                break;
            case 3:
                updateProductQuantity(inventory);
                break;
            case 4:
                deleteProduct(inventory);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
