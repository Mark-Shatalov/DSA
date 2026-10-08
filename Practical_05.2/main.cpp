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

// O(n) worst case because finding the target may require checking every node
bool removeByIDCircular(PlayerNode*& head, PlayerNode*& tail, int targetID)
{
    if (head == nullptr)
    {
        return false;
    }

    PlayerNode* current = head;
    PlayerNode* previous = tail;

    do
    {
        if (current->data.id == targetID)
        {
            if (head == tail)
            {
                delete current;
                head = nullptr;
                tail = nullptr;
                return true;
            }

            previous->next = current->next;

            if (current == head)
            {
                head = current->next;
            }

            if (current == tail)
            {
                tail = previous;
            }

            tail->next = head;
            delete current;
            return true;
        }

        previous = current;
        current = current->next;
    } while (current != head);

    return false;
}

// O(t) t is numberOfTurns
void playTurns(PlayerNode* head, int numberOfTurns)
{
    if (head == nullptr || numberOfTurns <= 0)
    {
        return;
    }

    PlayerNode* current = head;

    for (int turn = 1; turn <= numberOfTurns; turn++)
    {
        cout << "Turn " << turn << ": " << current->data.name << endl;
        current = current->next;
    }
}

// O(n^2): each of the n players is compared with all n players
int pairwiseComparisons(PlayerNode* head)
{
    if(head == nullptr)
    {
        return 0;
    }

    int comparisons = 0;
    PlayerNode* currentPlayer = head;

    do
    {
        PlayerNode* comparedPlayer = head;

        do
        {
            comparisons++;
            comparedPlayer = comparedPlayer->next;
        } while (comparedPlayer != head);

        currentPlayer = currentPlayer->next;
    } while (currentPlayer != head);

    return comparisons;
}

// O(n) deletes n nodes
void clearCircular(PlayerNode*& head, PlayerNode*& tail)
{
    if (head == nullptr)
    {
        tail = nullptr;
        return;
    }

    PlayerNode* current = head->next;

    while (current != head)
    {
        PlayerNode* nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
    }

    delete head;
    head = nullptr;
    tail = nullptr;
}


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

    // part 7
    // complexity: O(t) where t is the number of turns
    // no reset to head is needed
    // circular linking allows repeated cycling without reaching nullptr
    std::cout << "\n---Game Turn Simulation---\n";
    playTurns(head, 7);

    //part 8
    // 5 to 10 players increases comparisons from 25 to 100.  
    std::cout << "\n\t\t---Pairwise Comparisons---\n";
    std::cout << "Players n\tExpected Comparisons\tActual\t\tBig-O" << endl;

    for (int playerCount = 3; playerCount <= 5; playerCount++)
    {
        PlayerNode* testHead = nullptr;
        PlayerNode* testTail = nullptr;

        for (int id = 1; id <= playerCount; id++)
        {
            insertEndCircular(testHead, testTail, {id, "Player" + to_string(id), 100});
        }

        int expected = playerCount * playerCount;
        int actual = pairwiseComparisons(testHead);
        cout << playerCount << "\t\t\t" << expected << "\t\t"<< actual << "\t\tO(n^2)" << endl;

        clearCircular(testHead, testTail);
    }

    // part 6
    // reconnecting pointers is O(1) but searching for the target is O(n)
    std::cout << "\n---Remove By ID---\n";
    std::cout << "Remove head Rogue: ";

    if (removeByIDCircular(head, tail, 200))
    {
        cout << "removed" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    displayCircular(head);

    cout << "\nRemove middle Mage: ";
    if (removeByIDCircular(head, tail, 202))
    {
        cout << "removed" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    displayCircular(head);

    cout << "\nRemove tail Healer: ";
    if (removeByIDCircular(head, tail, 204))
    {
        cout << "removed" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    displayCircular(head);

    cout << "\nRemove missing 999: ";
    if (removeByIDCircular(head, tail, 999))
    {
        cout << "removed" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    displayCircular(head);

    PlayerNode* oneHead = nullptr;
    PlayerNode* oneTail = nullptr;
    insertEndCircular(oneHead, oneTail, {1, "Warrior", 100});
    cout << "\nRemove only node: ";
    if (removeByIDCircular(oneHead, oneTail, 1))
    {
        cout << "removed" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    cout << "\nOne node list is now empty: ";
    if (oneHead == nullptr && oneTail == nullptr)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    cout << "\nRemove from empty list: ";
    if (removeByIDCircular(oneHead, oneTail, 1))
    {
        cout << "removed" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

};
