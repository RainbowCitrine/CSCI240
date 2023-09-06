#include <iostream> 
#include <string> 

class Flower
{
protected: 
    std::string name; 
    int pedals; 
    float price; 
public: 
    Flower(std::string name = "", int pedals = 0, float price = 0)
    {
        this->name = name; 
        this->pedals = pedals; 
        this->price = price; 
    }
    void setName(std::string name) {this->name = name;}
    void setPedals(int pedals) {this->pedals = pedals;}
    void setPrice(float price) {this->price = price;}
    std::string getName() {return name;}
    int getPedals() {return pedals;}
    float getPrice() {return price;}

    void print()
    {
        std::cout << name << " " << pedals << " " << price << std::endl; 
    }
};

int main(int argc, char const *argv[])
{
    Flower f("Daisy", 5, 10.00);
    f.print(); 

    return 0;
}
