#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Enemy
{
    int id;
    string name;
    int health;
    int score;
};

void displayEnemies(const vector<Enemy>& enemies)
{
    cout << left
         << setw(8)  << "ID"
         << setw(16) << "Name"
         << setw(10) << "Health"
         << setw(10) << "Score" << "\n";
    cout << string(44, '-') << "\n";
    for (const Enemy& e : enemies)
    {
        cout << left
             << setw(8)  << e.id
             << setw(16) << e.name
             << setw(10) << e.health
             << setw(10) << e.score << "\n";
    }
}

void addReinforcement(std::vector<Enemy>& enemies, const Enemy& enemy)
{
    int oldSize = enemies.size();
    float oldCapacity = enemies.capacity();
    
    std::cout << "Added: " << enemy.name << std::endl;
    std::cout << "Size before : " << oldSize << std::endl;
    std::cout << "Capacity before: " << oldCapacity << std::endl;

    enemies.push_back(enemy);
    int newSize = enemies.size();
    float newCapacity = enemies.capacity();

    std::cout << "Size after: " << newSize << std::endl;
    std::cout << "Capacity after: " << newCapacity << "\n" << std::endl;

    if(oldCapacity!=newCapacity)
    {
        std::cout << "*****Reallocation occured*****\n" << std::endl;
    }


}

int main()
{
    std::cout << "============ Part 1 ============\n";
    vector<Enemy> enemies;

    enemies.reserve(10);

    enemies.push_back({201, "Goblin",     45,  120});
    enemies.push_back({202, "Orc",        80,  300});
    enemies.push_back({203, "Skeleton",   18,  220});
    enemies.push_back({204, "Dark Mage",  35,  500});
    enemies.push_back({205, "Troll",      100, 450});
    enemies.push_back({206, "Assassin",   12,  700});
    enemies.push_back({207, "Slime",      5,   80});
    enemies.push_back({208, "Dragon",     150, 1200});

    displayEnemies(enemies);

    std::cout << "\nSize of enemies vector: " << enemies.size() << std::endl;
    std::cout << "Capacity of enemies vector: " << enemies.capacity() <<  std::endl;
    std::cout << "Display unused capacity: " << enemies.capacity() - enemies.size() << "\n" << std::endl;

    std::cout << "\n============ Part 2 ============\n";
    
    addReinforcement(enemies, { 209, "Warlock", 70, 650 });
	addReinforcement(enemies, { 210, "Wolf", 35, 180 });
	addReinforcement(enemies, { 211, "Knight", 90, 600 });
	addReinforcement(enemies, { 212, "Necromancer", 55, 900 });

    std::cout << "\n============ Part 3 ============\n";
    
    int targetID;
    std::cout << "Enter enemy ID to target: ";
    std::cin >> targetID;

   auto it = std::find_if(enemies.begin(), enemies.end(),
		[targetID](const Enemy& e)
		{
			return e.id == targetID;
		});
    if(it!=enemies.end())
    {
        std::cout << "ID: " << it->id << std::endl; 
        std::cout << "Name: " << it->name << std::endl;
        std::cout << "Score: " << it->score << std::endl;
        std::cout << "Health: " << it->health << std::endl;
    }
    else
    {
        std::cout << "Target not found." << std::endl;    
    }

    std::cout << "\n============ Part 4 ============\n";
    
    displayEnemies(enemies);
    std::cout << "\n";
    for(auto it = enemies.begin(); it!=enemies.end(); ++it)
    {
        if(it->health > 0)
        {
            it->health -=5;
        }
    }

    displayEnemies(enemies);

    std::cout << "\n============ Part 5 ============\n\n";

    auto criticalIt = std::find_if(enemies.begin(), enemies.end(),
        [](const Enemy& e)
        {
            return e.health > 0 && e.health < 20;
        });
    
    if (criticalIt != enemies.end())
    {
        std::cout << "Name: " << criticalIt->name << std::endl;
        std::cout << "Health: " << criticalIt->health << std::endl;
        std::cout << "Score: " << criticalIt->score << std::endl;
    }
    else
    {
        std::cout << "No critical enemy found." << std::endl;
    }

    std::cout << "\n============ Part 6 ============\n\n";

    auto priorityIt = std::find_if(enemies.begin(), enemies.end(),
        [](const Enemy& e)
        {
            return e.health > 0 && e.health < 30 && e.score >= 500;
        });

    if(priorityIt!=enemies.end())
    {
        std::cout << "High-value vulnerable target detected!" << std::endl;
        std::cout << "Name: " << priorityIt->name << std::endl;
        std::cout << "Health: " << priorityIt->health << std::endl;
        std::cout << "Score: " << priorityIt->score << std::endl;
    }
    else
    {
        std::cout << "No high-value vulnerable target found." << std::endl;
    }

    std::cout << "\n============ Part 7 ============\n\n";
    auto healIt = std::find_if(enemies.begin(), enemies.end(),
        [](const Enemy& e)
        {
            return e.health > 0 && e.health < 25 && e.score >= 500;
        });
    
    if(healIt!=enemies.end())
    {
        int oldHealth = healIt->health;
        healIt->health +=20;
        if(healIt->health > 100)
        {
            healIt->health = 100;
        }
        std::cout << "Name: " << healIt->name << std::endl;
        std::cout << "Old health: " << oldHealth << std::endl;
        std::cout << "New health: " << healIt->health << std::endl;
    }
    else
    {
        std::cout << "No emergency healing required." << std::endl;
    }

    std::cout << "\n============ Part 8 ============\n\n";
    auto selectedEnemy = enemies.begin();
    
    Enemy boss {999, "Ancient Dragon", 250, 500};

    enemies.insert(enemies.begin(), boss);

    displayEnemies(enemies);
    
    return 0;
}