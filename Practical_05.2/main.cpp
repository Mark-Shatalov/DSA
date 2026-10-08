#include <iostream>
#include <string>
using namespace std;


struct Player
{
    int id;
    string name;
    int health;
};

struct PlayerNode
{
    Player data;
    PlayerNode* next;
};

// Q1 - O(1): fixed number of operations
PlayerNode* createNode(Player player)
{
    PlayerNode* newNode = new PlayerNode;
    newNode->data = player;
    newNode->next = nullptr;
    return newNode;
}

// O(1): 3 pointers
void insertBeginningCircular(PlayerNode*& head, PlayerNode*& tail, Player player)
{
    PlayerNode* newNode = createNode(player);

    if(head==nullptr)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
        return;
    }
    // 3 pointers
    newNode->next = head;
    head = newNode;
    tail->next = head;
}

// O(1): adds a new player to the end of the circular list
void insertEndCircular(PlayerNode*& head, PlayerNode*& tail, Player player)
{
    PlayerNode* newNode = createNode(player);

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
        return;
    }

    tail->next = newNode;
    tail = newNode;
    tail->next = head;
}

// prints n nodes
// so the complexity is O(n)
// checking current != nullptr is unsafe - because a circular list never reaches nullptr
void displayCircular(PlayerNode* head)
{
    if(head==nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }
    PlayerNode* current = head;
    do
    {
        std::cout << current->data.name << " (ID " << current->data.id
                  << ", health " << current->data.health << ")";
        current = current->next;
        if(current != head)
        {
            std::cout << " -> ";
        }
    } while(current != head);
    std::cout << "\n";
    std::cout << "---Back to head: " << head->data.name << "---\n";
}

// best case O(1)
// worst case O(n)
bool searchCircular(PlayerNode* head, int targetID)
{
    if (head == nullptr)
    {
        return false;
    }

    PlayerNode* current = head;
    do
    {
        if (current->data.id == targetID)
        {
            return true;
        }

        current = current->next;
    } while (current != head);

    return false;
}

// counts how many nodes are checked during the search
int countSearchStepsCircular(PlayerNode* head, int targetID)
{
    if (head == nullptr)
    {
        return 0;
    }

    int steps = 0;
    PlayerNode* current = head;

    do
    {
        steps++;

        if (current->data.id == targetID)
        {
            return steps;
        }

        current = current->next;
    } while (current != head);

    return steps;
}

bool removeByIDCircular(PlayerNode*& head,PlayerNode*& tail,int targetID);

void playTurns(PlayerNode* head, int numberOfTurns);

int pairwiseComparisons(PlayerNode* head);

void clearCircular(PlayerNode*& head, PlayerNode*& tail);


int main()
{
    // part 1
    // O(1) - fixed work
    PlayerNode* head = nullptr;
    PlayerNode* tail = nullptr;
    
    // part 2 
    //O(1) insert for each insert because tail is known
    std::cout << "\n\n---Build The Circular List---\n\n";
    insertEndCircular(head, tail, {201, "Knight", 100});
    insertEndCircular(head, tail, {202, "Mage", 100});
    insertEndCircular(head, tail, {203, "Archer", 100});
    insertEndCircular(head, tail, {204, "Healer", 100});

    displayCircular(head);

    if(tail->next == head)
    {
        std::cout << "Tail points to head: true\n";
    }
    else
    {
        std::cout << "Tail points to head: false\n";
    }

    //part 3
    // 3 pointer assignments O(1)
    std::cout << "\n-Insert Rogue at the beginning-\n";
    insertBeginningCircular(head,tail,{200,"Rogue",100});

    displayCircular(head);
    if(tail->next == head)
    {
        std::cout << "Tail points to head: true\n";
    }
    else
    {
        std::cout << "Tail points to head: false\n";
    }

    //part 4
    // prints n nodes
    // so the complexity is O(n)
    // checking current != nullptr is unsafe - because a circular list never reaches nullptr 
    displayCircular(head);

    // part 5
    // best case: O(1) 
    // worst case: O(n) 
    // a missing target is important because every node must be checked

    std::cout << "\n---Search Table---\n";
    std::cout << " =Target=\t=Predicted steps=\t =Actual steps=\t\t =Case=\n";

    int searchIDs[] = {200, 202, 204, 999};
    int predictedSteps[] = {1, 3, 5, 5};
    string labels[] = {"200 - Rogue", "202 - Mage", "204 - Healer", "999 - Missing"};
    string cases[] = {"Best case", "Average case", "Worst case", "Missing case"};

    for(int i = 0; i < 4; i++)
    {
        int actualSteps = countSearchStepsCircular(head, searchIDs[i]);
        std::cout << labels[i] << "\t\t" << predictedSteps[i] << "\t\t\t" << actualSteps << "\t\t" << cases[i] << "\n";

        if(searchCircular(head, searchIDs[i]))
        {
            std::cout << "-Found-\n";
        }
        else
        {
            std::cout << "-Not found-\n";
        }
    }

};
