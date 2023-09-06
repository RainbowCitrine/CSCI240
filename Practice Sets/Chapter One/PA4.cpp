#include <iostream> 
#include <string> 

class GameEntry
{
public: 
    std::string name; 
    int score; 
    std::string date; 

    GameEntry(std::string name = "", int score = 0, std::string date = "")
    {
        this->name = name; 
        this->score = score; 
        this->date = date; 

        if(score < 0 || score > 1000)
            score = 0; 
    }
    void setName(std::string name) {this->name = name;}
    void setDate(std::string date) {this->date = date;}
    void setScore(int score) {this->score = score;}
    std::string getName() {return name;}
    int getscore() {return score;}
    std::string getDate() {return date;}
};

class GameScore
{
public: 
    std::string name; 
    GameEntry scores[5]; 
    GameScore(const std::string& name)
    {
        this->name = name; 
    }
    void add(const GameEntry& entry)
    {
        for(int i = 0; i < 5; ++i)
        {
        
            if(entry.score > scores[i].score)
            {
                for(int j = 4; j > i; --j)
                {
                    scores[j] = scores[j - 1]; 
                }
                scores[i] = entry; 
                break;
            }
        }
    }
    void print()
    {
        std::cout << "Top scores for " << name << std::endl; 
        for(GameEntry& entry : scores)
            std::cout << "Player: " << entry.name << ", Score: " << entry.score << ", Date: " << entry.date << std::endl; 
    }
};

int main()
{
    GameScore game("Pac-Man");
    game.add(GameEntry("Noah", 800, "081322"));
    game.add(GameEntry("Billy", 500, "081322"));
    game.add(GameEntry("Tommy", 700, "081322"));
    game.add(GameEntry("Brady", 900, "081322"));
    game.add(GameEntry("Rainbow", 129, "081322"));

    game.print(); 
}
