#include <iostream> 
#include <string> 

class Person
{
private: 
    std::string name; 
    int age; 
public: 
    void introduction(std::string n)
    {
        name = n; 
        std::cout << "For the record my name is: " << name << std::endl; 
    }
    void introduction(std::string n, int a)
    {
        name = n; 
        age = a; 
        std::cout << "For the record my name is: " << name << " and my age is: " << age <<std::endl; 
    }
    void printIntro()
    {
        std::cout << "Name: " << name << "\n Age: " << age << std::endl; 
    }
};
class Student : public Person
{
    int id; 
    std::string majorStudent; 
public: 
    void major(std::string m)
    {
        introduction("Noah"); 
        introduction("Noah", 20);
        majorStudent = m; 
        std::cout << "Major is: " << majorStudent << std::endl; 
    }

    void print()
    {
        printIntro(); 
        std::cout << "Id: " << id << "\n Major: " << majorStudent << std::endl; 
    }
};

int main(int argc, char const *argv[])
{
    Student s; 
    s.major("Coding"); 
    s.print(); 
    return 0;
}
