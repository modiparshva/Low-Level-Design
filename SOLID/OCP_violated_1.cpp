#include <iostream>
#include <vector>

using namespace std;

// Product class
class Product {
public:
    string name;
    double price;

    Product(string n, double p) {
        this->name = n;
        this->price = p;
    }
};

// ShoppingCart class
class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() const {
        return products;
    }

    double calculateTotal() const {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }
};

// ShoppingCartPrinter class
class ShoppingCartPrinter {
public:
    void printInvoice(const ShoppingCart* cart) {
        cout << "Cart Invoice:" << endl;
        for (auto p : cart->getProducts()) {
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total : $" << cart->calculateTotal() << endl;
    }
};

// ShoppingCartStorage class
class ShoppingCartStorage {
public:
    void saveToSQLDatabase(const ShoppingCart* cart) {
        cout << "Saving shopping cart to SQL..." << endl;
    }

    void saveToMongoDatabase(const ShoppingCart* cart) {
        cout << "Saving shopping cart to Mongo..." << endl;
    }

    void saveToFile(const ShoppingCart* cart) {
        cout << "Saving shopping cart to file..." << endl;
    }
};

// Counter class
class Counter {
private:
    ShoppingCartPrinter* printer;
    ShoppingCartStorage* storage;

public:
    Counter() {
        this->printer = new ShoppingCartPrinter();
        this->storage = new ShoppingCartStorage();
    }

    void checkoutCart(ShoppingCart* cart) {
        printer->printInvoice(cart);
        storage->saveToFile(cart);
        storage->saveToMongoDatabase(cart);
        storage->saveToSQLDatabase(cart);
    }

    ~Counter() {
        delete printer;
        delete storage;
    }
};

// Main function
int main() {
    Counter* counter1 = new Counter();  // One counter

    // Customer 1
    ShoppingCart* cart1 = new ShoppingCart();
    cart1->addProduct(new Product("Watch", 1300));
    cart1->addProduct(new Product("Earphone", 1000));
    counter1->checkoutCart(cart1);

    cout << "\n--------------------------\n";

    // Customer 2
    ShoppingCart* cart2 = new ShoppingCart();
    cart2->addProduct(new Product("Shoes", 2000));
    cart2->addProduct(new Product("Bag", 1500));
    counter1->checkoutCart(cart2);

    // Cleanup
    delete cart1;
    delete cart2;
    delete counter1;

    return 0;
}
