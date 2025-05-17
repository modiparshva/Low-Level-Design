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
            for (auto p : products){
                total += p->price;
            }
            return total;
        }
};

class ShoppingCartPrinter {
    private:
        ShoppingCart* cart;
        
    public:
        ShoppingCartPrinter(ShoppingCart* c){
            this->cart = c;
        }

        void printCart(){
            cout << "Invoice :" << endl;
            for(auto p : cart->getProducts()){
                cout << p->name << " - $" << p->price << endl;
            }
            cout << "Total Bill : "<< cart->calculateTotal() << endl;
        }
};

class Persistance{
    private:
        ShoppingCart* Cart;

    public:
        virtual void save(ShoppingCart* Cart) = 0;
};

class SQLPersistance : public Persistance{
    public:
        void save(ShoppingCart* Cart) override {
            cout << "Saving shopping cart to the SQL DB !" << endl;
        }
};

class MongoPersistance : public Persistance{
    public:
        void save(ShoppingCart* Cart) override {
            cout << "Saving shopping cart to the Mongo DB !" << endl;
        }
};

class FilePersistance : public Persistance{
    public:
        void save(ShoppingCart* Cart) override {
            cout << "Saving shopping cart to the File !" << endl;
        }
};

int main(){
    ShoppingCart* Cart = new ShoppingCart();
    Cart->addProduct(new Product("Apple", 10000));
    Cart->addProduct(new Product("MI",5000));

    ShoppingCartPrinter* print = new ShoppingCartPrinter(Cart);
    print->printCart();

    Persistance* db = new SQLPersistance();
    Persistance* mongo = new MongoPersistance();
    Persistance* file = new FilePersistance();

    db->save(Cart);
    mongo->save(Cart);
    file->save(Cart);

    return 0;
}