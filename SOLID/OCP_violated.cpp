#include<iostream>
#include<vector>

using namespace std;

class Product{
    public:
        string name;
        double price;

    Product(string n,double p){
        this->name = n;
        this->price = p;
    }
};

class ShoppingCart{
    private:
        vector<Product*> products;
    
    public:
        void addProduct(Product* p){
            products.push_back(p);
        }

        const vector<Product*> getProducts(){
            return products;
        }

        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total += p->price;
            }
            return total;
        }
};

class ShoppingCartPrinter{
    private:
        ShoppingCart* cart;

    public:
        ShoppingCartPrinter(ShoppingCart* c){
            this->cart = c;
        }

        void printInvoice(){
            cout << "Cart Invoice :" << endl;
            for(auto p : cart->getProducts()){
                cout << p->name << " - $" << p->price << endl;
            }
            cout << "Total : $" << cart->calculateTotal() << endl;
        }
};

class ShoppingCartStorage{
    private:
        ShoppingCart* cart;

    public:
        ShoppingCartStorage(ShoppingCart* c){
            this->cart = c;
        }

        void saveToSQLDatabase() {
            cout << "Saving Shopping cart to SQL ..." << endl;
        }

        void saveToMongoDatabase(){
            cout << "Saving Shopping cart to Mongo ..." << endl;
        }

        void saveToFile(){
            cout << "Saving Shopping cart to File ..." << endl;
        }
};

int main(){
    ShoppingCart* cart1 = new ShoppingCart();
    cart1->addProduct(new Product("Watch",1300));
    cart1->addProduct(new Product("Earphone",1000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart1);
    printer->printInvoice();

    ShoppingCartStorage* storage = new ShoppingCartStorage(cart1);
    storage->saveToFile();
    storage->saveToMongoDatabase();
    storage->saveToSQLDatabase();
    

    cout << "\n--------------------------"<<endl;

    ShoppingCart* cart2 = new ShoppingCart();
    cart2->addProduct(new Product("Watch",1300));
    cart2->addProduct(new Product("Earphone",1000));

    ShoppingCartPrinter* printer2 = new ShoppingCartPrinter(cart2);
    printer2->printInvoice();

    ShoppingCartStorage* storage2 = new ShoppingCartStorage(cart2);
    storage2->saveToFile();
    storage2->saveToMongoDatabase();
    storage2->saveToSQLDatabase();

}