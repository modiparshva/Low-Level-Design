#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Product {
    public:
        string name;
        double price;

        Product(string n,double p){
            this->name = n;
            this->price = p;
        }
};

class ShoppingCart {
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

class shoppingCartPrint {
    private:
        ShoppingCart* Cart;

    public:
        shoppingCartPrint(ShoppingCart* c){
            this->Cart = c;
        }
        
        void printInvoice(){
            cout << "Invoice:" << endl;
            for (auto p : Cart->getProducts()){
                cout << p->name << " - $" << p->price << endl;
            }
            cout << "Total : " << Cart->calculateTotal() << endl;
        }
};

class shoppingCartStorage {
    private:
        ShoppingCart* Cart;

    public:
        shoppingCartStorage(ShoppingCart* c){
            this->Cart = c;
        }
        
        void saveCart(){
            cout << "Saving shopping cart to Database ..." << endl;
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Apple", 1.99));
    cart->addProduct(new Product("MI", 4.99));

    shoppingCartPrint* print = new shoppingCartPrint(cart);
    print->printInvoice();

    shoppingCartStorage* db = new shoppingCartStorage(cart);
    db->saveCart();

    return 0;
}