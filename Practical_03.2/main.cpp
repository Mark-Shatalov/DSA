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
    
    Enemy boss {999, "Ancient Dragon", 250, 5000};

    enemies.insert(enemies.begin(), boss);
    displayEnemies(enemies);

    enemies.erase(enemies.begin());
    displayEnemies(enemies);
    // one should not assume that the variable selectedEnemy remains valid after the deletion operation as it may have been reset

    std::cout << "\n============ Part 9 ============\n\n";

    int sizeBeforeClenup = enemies.size();

    auto itRemove = std::remove_if(enemies.begin(), enemies.end(),
        [](const Enemy& e)
        {
			return e.health <= 0;
        });
        
    enemies.erase(itRemove, enemies.end());

    int removedCount = sizeBeforeClenup - enemies.size();

    std::cout << "Removed " << removedCount << " enemies with health <=0\n\n";
    std::cout << "Remaining enemies:\n";
    displayEnemies(enemies);

    std::cout << "\n============ Part 10 ============\n\n";
    std::vector<int> spawnSlots;

    spawnSlots.reserve(5);
    std::cout << "Spawn slots size: " << spawnSlots.size() << "\n";
	std::cout << "Spawn slots capacity: " << spawnSlots.capacity() << "\n";

	// no, spawnSlots[0] does not exist until an element is added to spawnSlots
    spawnSlots.resize(5);
	std::cout << "Spawn slots size after resize: " << spawnSlots.size() << "\n";
	std::cout << "Spawn slots capacity after resize: " << spawnSlots.capacity() << "\n";
	for (int i = 0; i < spawnSlots.size(); ++i)
	{
		std::cout << "Spawn slot " << i << ": " << spawnSlots[i] << "\n";
	}
    // reserve() means: allocate memory but do not change the size
    // resize() means: change the size of the vector
    // spawnSlots[0] is now safe to access resize(5) actually constructs five
    // elements, unlike reserve() which only allocates capacity without creating any elements or changing the vectors size

    std::cout << "\n============ Part 11 ============\n\n";

    int minScore;
    int maxHealth;

    std::cout << "Enter minimum score: " << "\n";
	std::cin >> minScore;
	std::cout << "Enter maximum health: " <<"\n";;
	std::cin >> maxHealth;

    auto satisfyingEnemy = std::find_if(enemies.begin(), enemies.end(),
		[minScore, maxHealth](const Enemy& e)
		{
			if (e.score >= minScore && e.health <= maxHealth && e.health > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		});
    if(satisfyingEnemy!=enemies.end())
    {
        std::cout << "Found an enemy satisfying the criteria:\n";
        std::cout << "Name: " << satisfyingEnemy->name << "\n";
        std::cout << "Health: " << satisfyingEnemy->health << "\n";
        std::cout << "Score: " << satisfyingEnemy->score << "\n";
    }
    else
    {
        std::cout << "No enemy satisfies the criteria." << std::endl;
    }

    std::cout << "\n============ Part 12 ============\n\n";
    int unusedEnemySlots = enemies.capacity() - enemies.size();
    std::cout << "Size before reserve: " << enemies.size() << "\n";
    std::cout << "Capacity before reserve: " << enemies.capacity() << "\n";

    if(unusedEnemySlots < 6)
    {
		// reserve() is appropriate because it adds capacity without adding empty enemies
        enemies.reserve(enemies.size() + 6);
    }

    std::cout << "Size after reserve: " << enemies.size() << "\n";
    std::cout << "Capacity after reserve: " << enemies.capacity() << "\n";

    addReinforcement(enemies, { 301, "Wraith", 30, 520});
    addReinforcement(enemies, {302, "Golem", 120, 800});
    addReinforcement(enemies, {303, "Imp", 10, 90});
    addReinforcement(enemies, {304, "Vampire", 60, 950});
    addReinforcement(enemies, {305, "Hunter", 75, 650});
    addReinforcement(enemies, {306, "Demon", 95, 1300});

    int activeEnemies = std::count_if(enemies.begin(), enemies.end(),
        [](const Enemy& e)
        {
            return e.health > 0;
        });
    auto firstLowHealth = std::find_if(enemies.begin(), enemies.end(),
		[](const Enemy& e)
		{
			return e.health > 0 && e.health < 20;
		});
	auto firstHighScore = std::find_if(enemies.begin(), enemies.end(),
		[](const Enemy& e)
		{
			return e.score > 1000;
		});
    
    displayEnemies(enemies);    
    std::cout << "\n|-----Battle summary-----|\n";

    std::cout << "\nActive enemies: " << activeEnemies << "\n";
    std::cout << "Vector size: " << enemies.size() << "\n";
    std::cout << "Vector capacity: " << enemies.capacity() << "\n";
    std::cout << "Unused capacity: " << enemies.capacity() - enemies.size() << "\n";

    std::cout << "\n";
    if (firstLowHealth != enemies.end())
	{
		std::cout << "First living enemy below 20 health: " << firstLowHealth->name << std::endl;
	}
	else
	{
		std::cout << "No living enemy below 20 health" << std::endl;
	}
	if (firstHighScore != enemies.end())
	{
		std::cout << "First enemy with score above 1000: " << firstHighScore->name << std::endl;
	}
	else
	{
		std::cout << "No enemy with score above 1000" << std::endl;
	}
    std::cout << "\n";
    std::cout << "\n";

    return 0;
}