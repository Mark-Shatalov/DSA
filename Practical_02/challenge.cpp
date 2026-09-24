#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> playerNames { "Paul", "Mykhailo", "Mark", "Bob", "Ethan"};

    std::cout << "Names: \n";
    for(auto& name : playerNames)
    {
        std::cout << name << std::endl;
    }

    std::cout <<"\n";
    std::cout << "Sort the names: \n";
    std::sort(playerNames.begin(), playerNames.end());
    for (auto& name : playerNames)
    {
        std::cout << name << " ";
    }

    std::string enterName;
    std::cout << "\n\nEnter Name: "<< "\n";
    std::cin>> enterName;

    auto findName = std::find(playerNames.begin(), playerNames.end(), enterName);
    if(findName != playerNames.end())
    {
        std::cout << "User prompt is found (" << enterName << ")\n";
    }
    else 
    {
        std::cout << "User prompt is not found (" << enterName << ")\n";
    }

    std::cout << "\n---Disaply all names using std::for_each---\n";
    std::for_each(playerNames.begin(), playerNames.end(),
        [](std::string n)
    {
        std::cout << n <<"\n";
    });
}