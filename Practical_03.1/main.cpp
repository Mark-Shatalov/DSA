
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

void printSection(const string& title)
{
    cout << "\n============================================================\n";
    cout << title << "\n";
    cout << "============================================================\n";
}
void displayIntVector(const vector<int>& values)
{
    cout << "[ ";
    
    for (int value : values)
    {
        cout << value << " ";
    }
    cout << "]\n";
}
void displayEnemies(const vector<Enemy>& enemies)
{
    cout << left
    << setw(8) << "ID"
    << setw(15) << "Name"
    << setw(10) << "Health"
    << setw(10) << "Score"
    << "\n";
    cout << string(43, '-') << "\n";
 
    for (const Enemy& e : enemies)
    {
        cout << left
        << setw(8) << e.id
        << setw(15) << e.name
        << setw(10) << e.health
        << setw(10) << e.score
        << "\n";
    }
}

void printVector(const std::vector<int>& scores)
{
    std::cout << "\n";
    for (int i = 0; i < scores.size(); i++)
    {
        cout << "Index " << i << ": " << scores[i] << "\n";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> scores = {50, 80, 40, 90};

    // Part 1
    // Task 1.1
    // 1
    printVector(scores);

    // 2
    std::cout << "Size of scores vector: " << scores.size() << std::endl;
    std::cout << "Capacity of scores vector: " << scores.capacity() << std::endl;
    std::cout << "\n";

    // 3
    std::cout << "The first element  of scores vector: " << scores.front() << std::endl;
    std::cout << "The last element of scores vector: " << scores.back() << std::endl;
    std::cout << "The elemnt at index 2: " << scores.at(2) << std::endl;

    // Task 1.2
    std::cout << "\n";
    std::cout << "============================================================\n";

    scores.push_back(70);
    printVector(scores);
    std::cout << "Size of scores: " << scores.size() << " . Capacity of scores: " << scores.capacity() << std::endl;
    scores.push_back(100);
    printVector(scores);
    std::cout << "Size of scores: " << scores.size() << " . Capacity of scores: " << scores.capacity() << std::endl;
    scores.pop_back();
    printVector(scores);
    std::cout << "Size of scores: " << scores.size() << " . Capacity of scores: " << scores.capacity() << std::endl;

    std::cout << "\n";
    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == 80)
        {
            scores[i] = 85;
            break;
        }
    }

    printVector(scores);


    // Part 2
    std::cout << "\nPart2";
    std::cout << "\n============================================================\n";
    std::vector<int> gameObjects;
    vector<int> valuesToAdd {10, 20, 30, 40, 50, 60, 70, 80};

    for (int value : valuesToAdd)
    {
        gameObjects.push_back(value);
        cout << "Added: " << value
             << " | Size: " << gameObjects.size()
             << " | Capacity: " << gameObjects.capacity() << "";
             printVector(gameObjects);
    }

    // Question 1 : At which additions did capacity change?
    // in a few additons (10 - 40) the capacity changes
    // Question 2 : Why can capacity be larger than size?
    // the capacity may exceed the size because the vector allocates excess memory, to avoid having to reallocate memory on every call to push_back()
    // Question 3 : Why should you not assume a fixed growth rule?
    // its implementation-defined so different compilers/libraries may grow differently

    // Part 3
    std::cout << "\nPart3";
    std::cout << "\n============================================================\n";

    std::vector<int> enemyIDs;
    enemyIDs.reserve(20);
    //size 0, capacity 20
    std::cout << "Size of enemyIDs: " << enemyIDs.size() << " . Capacity of enemyIDs: " << enemyIDs.capacity() << std::endl;

    for (int id = 101; id <= 110; id++)
    {
        enemyIDs.push_back(id);
        std::cout << "Added: " << id
                  << " | Size: " << enemyIDs.size()
                  << " | Capacity: " << enemyIDs.capacity() << std::endl;
                  printVector(enemyIDs);
    }

    // Q1: Did reserve(20) create 20 elements?
    // Answer: no its only reserve 20 spaces in memory
    // Q2: Why did size remain 0 immediately after reserve(20)?
    // Answer because reserve() only allocates memory it does not add any elements to the vector
    // Q3: What benefit did reserve(20) provide while adding IDs?
    // Answer with reserve(20) you already have a big enough space so adding 10 elements is just placing them in already-available space

    std::cout << "\nPart4";
    std::cout << "\n============================================================\n";

    std::vector<int> slots;
    slots.reserve(5);
    std::cout << "Size of slots: " << slots.size() << " . Capacity of slots: " << slots.capacity() << std::endl;

    slots.resize(5);
    std::cout << "Size of slots: " << slots.size() << " . Capacity of slots: " << slots.capacity() << std::endl;

    displayIntVector(slots);


    // reserve() means: allocate memory but do not change the size
    // resize() means: change the size of the vector

    std::cout << "\nPart5";
    std::cout << "\n============================================================\n";

    std::vector<Enemy> enemies;

    enemies.push_back({101, "Goblin", 75, 120});
    enemies.push_back({102, "Orc", 90, 300});
    enemies.push_back({103, "Skeleton", 15, 220});
    enemies.push_back({104, "Mage", 40, 550});
    enemies.push_back({105, "Troll", 100, 450});
    enemies.push_back({106, "Rogue", 18, 700});

    displayEnemies(enemies);

    std::cout << "\nPart6";
    std::cout << "\n============================================================\n";

    for( auto it = enemies.begin(); it != enemies.end(); ++it)
    {
         cout << "ID: " << it->id
            << " | Name: " << it->name
            << " | Health: " << it->health
            << " | Score: " << it->score << "\n";
    }

    auto it = enemies.begin();
    ++it;
    it->health = 70;

    std::cout << "\n";
    displayEnemies(enemies);

    // *it represents the Enemy object the iterator is currently pointing to. 
    // *it is the object itself and it-field(health, name, score) accesses
}
