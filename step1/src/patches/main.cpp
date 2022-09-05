#include <iostream>
#include <fstream>

int main()

{
    system("powershell | wmic qfe list > res.txt");
    std::ifstream dataFile("res.txt");
    std::string text = "";
    while (!dataFile.fail() && !dataFile.eof() )
    {
        dataFile >> text ;
        std::cout << text << std::endl;
    }
    return 0;
}
