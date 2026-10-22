#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;





struct Task
{
    int priority;
    string description;
    bool operator<(const Task& other) const
    {
        return priority < other.priority;
    }
};

struct EnemyThreat
{
    string enemyName;
    int threatLevel;

    bool operator<(const EnemyThreat& other) const
    {
        return threatLevel < other.threatLevel;
    }
};

int main()
{
    // priority_queue<int> pq;
    // pq.push(40);
    // pq.push(25);
    // pq.push(60);
    // pq.push(10);
    // pq.push(80);
    // pq.push(50);
    // pq.push(70);
    // cout << "Top: " << pq.top() << "\n";

    // while (!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    priority_queue<Task> tasks;

    tasks.push({3, "Spawn Goblin"}); // push() O(n)
    tasks.push({10, "Critical Heal"}); // push() O(n)
    tasks.push({7, "Boss Attack"}); // push() O(n)
    tasks.push({5, "Save Checkpoint"}); // push() O(n)
    tasks.push({8, "Defend Player"}); // push() O(n)
    tasks.push({12, "Emergency Shield"}); // push() O(n)
    // Q: Explain why Emergency Shield becomes the next top task:
    // because Emergency Shield has the highest priority than other tasks


    while (!tasks.empty())
    {
        // each top() call O(1)
        cout << tasks.top().priority << " - "
             << tasks.top().description << "\n";
        // pop() O(n)
        tasks.pop();
    }

    std::cout << "\n\n---Combat Task Queue---\n\n";
    priority_queue<Task> combat;

    combat.push({4, "Normal Attack"}); // O(n)
    combat.push({6, "Use Potion"}); // O(n)
    combat.push({2, "Play Animation"}); // O(n)

    // process one task
    cout << combat.top().description << "\n"; // O(1)
    combat.pop(); // O(n)

    combat.push({9, "Incoming Boss Strike"}); // O(n)

    // process one task
    cout << combat.top().description << "\n"; // O(1)
    combat.pop(); // O(n)

    combat.push({10, "Player Near Death - Heal"}); // O(n)

    // process the remaining tasks
    while (!combat.empty())
    {
        cout << combat.top().description << "\n"; // O(1)
        combat.pop(); // O(n)
    }

    // Q29: FIFO queue processes tasks in the order they arrive. A priority queue processes the highest priority task first
    // the "urgent?" task can go ahead of older
    // Q30: a character may have Attack and Reload waiting If their health becomes critically low, a newly added 
    // Emergency Heal task should have a higher priority and be processed first

    std::cout << "\n\n---Min Queue---\n\n";

    priority_queue<int, vector<int>, greater<int>> minQueue;

    minQueue.push(50);
    minQueue.push(10);
    minQueue.push(30);
    minQueue.push(5);

    cout << "Minimum: " << minQueue.top() << "\n";

    while (!minQueue.empty())
    {
        cout << minQueue.top() << " ";
        minQueue.pop();
    }

    //Q33: the smallest value is always at the top
    //Q34: in pathfinding process the location with the lowest travel cost first

    std::cout << "\n\n---Enemy Threats---\n\n";

    priority_queue<EnemyThreat> enemies;

    enemies.push({"Goblin", 20});
    enemies.push({"Orc", 45});
    enemies.push({"Mage", 60});
    enemies.push({"Troll", 70});
    enemies.push({"Skeleton", 10});

    // Process the two highest threats
    for (int i = 0; i < 2; i++)
    {
        cout << enemies.top().enemyName << "\n";
        enemies.pop();
    }

    enemies.push({"Dragon", 100});

    cout << "Next: " << enemies.top().enemyName << "\n";
    // the heap efficiently keeps the highest threat at the top


    return 0;
}

//Question 1: Enemy Threat System
//A player is fighting a Goblin (threat 20), Orc (45), Mage (60) and Dragon (100). Which enemy should an AI defence system react to first?
//What should happen if a new Boss with threat 120 appears while other enemies are still waiting?

// the system should react to Dragon first because it has the highest treat/priority
// if Boss appears with the threat 120 ot becomes the next enemy to process

//Question 2: Emergency Healing
//A game has several characters waiting for healing. How could you assign priority so that the character in the most danger is healed first?
//Would the highest or lowest numerical value represent the highest priority in your design? Explain.

// give higher priority to characters with lower health. the character in the most danger is healed first

//Question 3: NPC Task Scheduler
//An NPC has these tasks: Patrol, Eat, Escape Fire, Talk to Player and Sleep. Give each task a priority value. Show the order in which the
//NPC should process them. What happens if Escape Fire is added after Patrol is already waiting?

// Escape Fire (10) → Eat (8) → Talk to Player (6) → Patrol (3) → Sleep (1)
// if Escape Fire arrives while Patrol is waiting it is processed first

//Question 4: Multiplayer Server Events
//A server receives Normal Chat, Player Movement, Anti-Cheat Alert and Disconnect Warning events. Which events should have higher
//priority? Why might a priority queue be better than a normal FIFO queue for some of these events?

// Anti-Cheat Alert and Disconnect Warning should have higher priority than Player Movement and Normal Chat
// a priority queue handles urgent events before older

//Question 5: Pathfinding Connection
//Imagine a pathfinding algorithm stores locations together with an estimated travel cost. Which location should be processed first: the
//one with the highest cost or the lowest cost? Would you use a max-priority or min-priority queue?

// process the location with the lowest travel cost first and use a min-priority queue

//Question 6: Game Download / Asset Loading
//A game needs to load Main Character Model, Nearby Enemy Texture, Background Music and Menu Icon. Suggest priorities based on
//what the player needs immediately. How could a priority queue improve the player experience?

// Main Character Model (10) → Nearby Enemy Texture (8) → Background Music (3) → Menu Icon (1)
// a priority queue loads the most immediately needed assets first

// Question 7: Boss Battle Events
//During a boss fight, the following events are waiting: Play Background Animation (2), Boss Ultimate Attack (10), Update Score (1), Player
//Critical Health Warning (12), Spawn Minions (6). Write the expected processing order for a max-priority queue.

// Player Critical Health Warning (12) → Boss Ultimate Attack (10) → Spawn Minions (6) → Play Background Animation (2) → Update Score (1)

//Question 8: Design Your Own
//Create one game-development problem where FIFO would be a poor choice but a priority queue would be useful. State the items, their
//priority values, and the expected processing order.

// a character has Attack (5) Defend (7) Reload (3) Emergency Heal (10) sleep (1) and Escape Danger (9)
// in high priority ir will be: Emergency Heal (10) Escape Danger (9) Defend (7) Attack (5) Reload (3) Sleep (1)
// process them in that order. FIFO could delay urgent healing or escape danger behind less important actions