#include <iostream> 
#include <string> 

int main(int argc, char const *argv[])
{
    std::string s[8] = {"I wll always us object-oriented design.", "I will alwas use objectoriented design.","I will al us object-oriented design.","I will always use object-oriented desi.","I wl always ue object-oriented design.","I will always use object-orited esign.","I will always use design.", "I will always use", };
    for(int i = 0; i < 12; ++i)
    {
        std::cout << "I will always use object-oriented design." << std::endl; 
    }

    std::cout << s[0] << std::endl; 
    std::cout << s[1] << std::endl; 
    
    for(int i = 0; i < 10; ++i)
    {
        std::cout << "I will always use object-oriented design." << std::endl; 
    }

    std::cout << s[2] << std::endl; 
    std::cout << s[3] << std::endl; 
    std::cout << s[4] << std::endl; 
    for(int i = 0; i < 20; ++i)
    {
        std::cout << "I will always use object-oriented design." << std::endl; 
    }

    std::cout << s[5] << std::endl; 
    std::cout << s[6] << std::endl; 
    std::cout << s[7] << std::endl; 
    
    return 0;
}
