#include <iostream>
#include <list>
#include <string>
#include <iterator>

class TextEditor {
    std::list<char> text;
    std::list<char>::iterator cursor;

public:
    TextEditor(const std::string& initial = "") {
        text.assign(initial.begin(), initial.end());
        cursor = text.end();
    }
    void left() {
        if (cursor != text.begin()) cursor--;
    }
    void right() {
        if (cursor != text.end()) cursor++;
    }
    void insert(char c) { text.insert(cursor, c); }
    void deleteChar() {
        if (cursor != text.begin()) {
            cursor--;
            cursor = text.erase(cursor);
        }
    }
    int current() { return std::distance(text.begin(), cursor); }
    void move(int i) {
        if (i >= 0 && i <= text.size()) {
            cursor = text.begin();
            std::advance(cursor, i);
        }
    }
    void display() {
        for (auto it = text.begin(); it != text.end(); ++it) {
            if (it == cursor) {
                std::cout << "|";
            }
            std::cout << *it;
        }
        if (cursor == text.end()) {
            std::cout << "|";
        }
        std::cout << " (" << text.size() << " characters)" << std::endl;
    }
};

int main() {
    TextEditor editor("HHello Word");
    int option;
    std::cout << "Author: Noah Rainbow" << std::endl; 
    do {
        std::cout << "Editing Menu" << std::endl;
        std::cout << "1. Left" << std::endl;
        std::cout << "2. Right" << std::endl;
        std::cout << "3. Insert character" << std::endl;
        std::cout << "4. Delete character" << std::endl;
        std::cout << "5. Move to position" << std::endl;
        std::cout << "6. Display current position" << std::endl;
        std::cout << "7. Display text" << std::endl;
        std::cout << "8. Quit" << std::endl;
        std::cout << "Enter an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                editor.left();
                std::cout << "Cursor moved to the left" << std::endl; 
                break;
            case 2:
                editor.right();
                std::cout << "Cursor moved to the right" << std::endl; 
                break;
            case 3:
                char c;
                std::cout << "Enter a character: ";
                std::cin >> c;
                editor.insert(c);
                std::cout << "Inserted Character " << c << std::endl;
                break;
            case 4:
                editor.deleteChar();
                std::cout << "Deleted one character" << std::endl; 
                break;
            case 5:
                int position;
                std::cout << "Enter a position: ";
                std::cin >> position;
                editor.move(position);
                std::cout << "Moved to position: " << position << std::endl;
                break;
            case 6:
                std::cout << "Current position: " << editor.current() << std::endl;
                break;
            case 7:
                editor.display();
                std::cout << std::endl; 
                break;
            case 8:
                std::cout << "Thanks for using my editor program." << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    } while (option != 8);

    return 0;
}
