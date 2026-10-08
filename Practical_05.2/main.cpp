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

// Q1 - O(1): fixed number of operations.
PlayerNode* createNode(Player player)
{
    PlayerNode* newNode = new PlayerNode;
    newNode->data = player;
    newNode->next = nullptr;
    return newNode;
}

void insertBeginningCircular(PlayerNode*& head,
PlayerNode*& tail,
Player player);

void insertEndCircular(PlayerNode*& head, PlayerNode*& tail, Player player);

void displayCircular(PlayerNode* head);

bool searchCircular(PlayerNode* head, int targetID);

int countSearchStepsCircular(PlayerNode* head, int targetID);

bool removeByIDCircular(PlayerNode*& head,PlayerNode*& tail,int targetID);

void playTurns(PlayerNode* head, int numberOfTurns);

int pairwiseComparisons(PlayerNode* head);

void clearCircular(PlayerNode*& head, PlayerNode*& tail);


int main()
{
    // part 1
    // O(1) - fixed work.
    PlayerNode* head = nullptr;
    PlayerNode* tail = nullptr;
    
};
