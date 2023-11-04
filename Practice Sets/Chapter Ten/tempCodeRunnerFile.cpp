int main() {
    BetterPopMap betterPopMap;

    std::ifstream inputFile("popSmall.txt");
    if (!inputFile) {
        std::cerr << "Error opening the input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string token;
        int key;
        std::string data;

        if (std::getline(iss, token, ',')) {
            key = std::stoi(token);
        }

        if (std::getline(iss, data)) {
            size_t first = data.find_first_not_of(' ');
            size_t last = data.find_last_not_of(' ');
            data = data.substr(first, (last - first + 1));
        }

        betterPopMap.insert(key, data);
    }

    inputFile.close();

    std::cout << "List of all records:" << std::endl;
    betterPopMap.print();
    std::cout << std::endl;

    std::cout << "Search for key 6037: " << betterPopMap.find(6037) << std::endl;
    std::cout << "Search for key 6000: " << betterPopMap.find(6000) << std::endl;

    betterPopMap.insert(6066, "1, New County, CA");
    betterPopMap.insert(6065, "2000, Riverside, CA");

    std::cout << "Records after insertions:" << std::endl;
    betterPopMap.print();
    std::cout << std::endl;

    betterPopMap.erase(6999);
    betterPopMap.erase(6075);

    std::cout << "Records after deletions:" << std::endl;
    betterPopMap.print();

    return 0;
}

