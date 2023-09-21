#include <iostream>
#include <list>
#include <string>
#include <iterator>

class TextEditor
{
    std::list<char> text;
    std::list<char>::iterator cursor;

public:
    TextEditor(const std::string& initial = "")
    {
        text.assign(initial.begin(), initial.end());
        cursor = text.end();
    }
    void left()
    {
        if (cursor != text.begin()) cursor--;
    }
    void right()
    {
        if (cursor != text.end()) cursor++;
    }
    void insert(char c) { text.insert(cursor, c); }
    void deleteChar()
    {
        if (cursor != text.begin())
        {
            cursor--;
            cursor = text.erase(cursor);
        }
    }
    int current() { return std::distance(text.begin(), cursor); }
    void move(int i)
    {
        if (i >= 0 && i <= text.size())
        {
            cursor = text.begin();
            std::advance(cursor, i);
        }
    }
    void display()
    {
        for (auto it = text.begin(); it != text.end(); ++it)
        {
            if (it == cursor)
            {
                std::cout << "|";
            }
            std::cout << *it;
        }
        if (cursor == text.end())
        {
            std::cout << "|";
        }
        std::cout << " (" << text.size() << " characters)" << std::endl;
    }
};

int main(int argc, char const* argv[])
{
    TextEditor editor("HHello Word");
    editor.display();

    std::cout << "Current Position: " << editor.current() << std::endl;

    editor.right();
    editor.left();
    editor.insert('l');

    editor.display();

    editor.move(1);
    editor.deleteChar();
    editor.display();

    return 0;
}
