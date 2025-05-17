#include<iostream>
#include<string>
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

class shoppingCart {
    private:
        vector<Product*> products;

    public:
        void addProduct(Product* p){
            products.push_back(p);
        }

        const vector<Product*>& getProducts(){
            return products;
        }

        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total += p->price;
            }
            return total;
        }

        void printInvoice(){
            cout << "Invoice:" << endl;
            for (auto p : products){
                cout << p->name << " - $" << p->price << endl;
            }
            cout << "Total : $" << calculateTotal() << endl;
        }

        void saveToDatabase(){
            cout << "saving shopping cart to database..." << endl;
        }
};

int main(){
    shoppingCart* cart = new shoppingCart();

    cart->addProduct(new Product("Laptop",15000));
    cart->addProduct(new Product("Iphone",150000));
    
    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}