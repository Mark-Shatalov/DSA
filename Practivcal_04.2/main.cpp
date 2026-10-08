#include <iostream>
#include <string>

using namespace std;

struct Enemy
{
    int id;
    string name;
    int health;
};

struct EnemyNode
{
    Enemy data;
    EnemyNode* next;
};

void displayList(EnemyNode* head)
{
    EnemyNode* current = head;

    while (current != nullptr)
    {
        cout << current->data.id << " - "
             << current->data.name << " - HP "
             << current->data.health << " -> ";
        current = current->next;
    }

    cout << "nullptr" << endl;
}

EnemyNode* createNode(Enemy enemy)
{
    // Only creates a node; no existing head, tail, or link changes.
    return new EnemyNode{ enemy, nullptr };
}

// References let this function update the caller's head and tail.
void insertEnd(EnemyNode*& head, EnemyNode*& tail, Enemy enemy)
{
    EnemyNode* newNode = createNode(enemy);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void insertBeginning(EnemyNode*& head, EnemyNode*& tail, Enemy enemy)
{
    // Head changes every time; tail changes only when the list was empty.
    EnemyNode* newNode = createNode(enemy);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr)
    {
        tail = newNode;
    }
}

bool insertAfterID(EnemyNode*& head, EnemyNode*& tail, int targetID, Enemy enemy)
{
    EnemyNode* current = head;

    while (current != nullptr && current->data.id != targetID)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        return false;
    }

    EnemyNode* newNode = createNode(enemy);
    // Preserve the rest of the chain before linking the new node in.
    newNode->next = current->next;
    current->next = newNode;

    if (current == tail)
    {
        tail = newNode;
    }

    return true;
}

int insertEndUsingHead(EnemyNode*& head, EnemyNode*& tail, Enemy enemy)
{
    EnemyNode* newNode = createNode(enemy);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return 0;
    }

    EnemyNode* current = head;
    int pointerMoves = 0;

    while (current->next != nullptr)
    {
        current = current->next;
        pointerMoves++;
    }

    current->next = newNode;
    tail = newNode;
    return pointerMoves;
}

bool removeFirst(EnemyNode*& head, EnemyNode*& tail)
{
    if (head == nullptr)
    {
        return false;
    }

    EnemyNode* nodeToDelete = head;
    head = head->next;
    delete nodeToDelete;

    if (head == nullptr)
    {
        tail = nullptr;
    }

    return true;
}

bool removeByID(EnemyNode*& head, EnemyNode*& tail, int targetID)
{
    EnemyNode* current = head;
    EnemyNode* previous = nullptr;

    while (current != nullptr && current->data.id != targetID)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        return false;
    }

    if (previous == nullptr)
    {
        head = current->next;
    }
    else
    {
        // Bypass the middle or last node before deleting it.
        previous->next = current->next;
    }

    if (current == tail)
    {
        tail = previous;
    }

    delete current;
    return true;
}

void patrolReport(EnemyNode* head, EnemyNode* tail)
{
    int enemyCount = 0;
    int totalHealth = 0;
    EnemyNode* firstBelow40 = nullptr;
    EnemyNode* finalNode = nullptr;
    EnemyNode* current = head;

    while (current != nullptr)
    {
        enemyCount++;
        totalHealth += current->data.health;

        if (firstBelow40 == nullptr && current->data.health < 40)
        {
            firstBelow40 = current;
        }

        finalNode = current;
        current = current->next;
    }

    cout << "Enemy count: " << enemyCount << endl;
    cout << "Total health: " << totalHealth << endl;

    if (firstBelow40 != nullptr)
    {
        cout << "First enemy below 40 HP: " << firstBelow40->data.name
             << " - HP " << firstBelow40->data.health << endl;
    }
    else
    {
        cout << "First enemy below 40 HP: none" << endl;
    }

    if (finalNode == tail)
    {
        cout << "Final traversed node matches tail: yes" << endl;
    }
    else
    {
        cout << "Final traversed node matches tail: no" << endl;
    }
}

void clearList(EnemyNode*& head, EnemyNode*& tail)
{
    while (head != nullptr)
    {
        EnemyNode* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }

    tail = nullptr;
}

int main()
{
    EnemyNode* head = nullptr;
    EnemyNode* tail = nullptr;

    Enemy goblin{ 101, "Goblin", 60 };
    Enemy orc{ 102, "Orc", 90 };
    Enemy troll{ 103, "Troll", 110 };
    Enemy slime{ 100, "Slime", 25 };
    Enemy darkMage{ 104, "Dark Mage", 70 };
    Enemy dragon{ 105, "Dragon", 180 };
    Enemy necromancer{ 106, "Necromancer", 85 };
    Enemy wraith{ 107, "Wraith", 35 };

    // Part 1
    // createNode is used by the insertion functions.

    // Part 2
    cout << "Starting patrol:" << endl;
    insertEnd(head, tail, goblin);
    displayList(head);
    insertEnd(head, tail, orc);
    displayList(head);
    insertEnd(head, tail, troll);
    displayList(head);
    cout << "Head ID: " << head->data.id << endl;
    cout << "Tail ID: " << tail->data.id << endl << endl;

    // Part 3
    EnemyNode* oldTail = tail;
    insertBeginning(head, tail, slime);
    cout << "After insertBeginning:" << endl;
    displayList(head);
    if (tail != oldTail)
    {
        cout << "Tail changed: yes" << endl << endl;
    }
    else
    {
        cout << "Tail changed: no" << endl << endl;
    }

    // Part 4
    if (insertAfterID(head, tail, 102, darkMage))
    {
        cout << "Insert Dark Mage after Orc: success" << endl;
    }
    else
    {
        cout << "Insert Dark Mage after Orc: failed" << endl;
    }
    displayList(head);

    // Part 5
    // This version traverses from head to locate the last node; insertEnd uses tail directly.
    int headTraversalMoves = insertEndUsingHead(head, tail, dragon);
    cout << "Pointer moves using head: " << headTraversalMoves << endl;
    displayList(head);

    // Part 6
    if (removeFirst(head, tail))
    {
        cout << "Remove first: success" << endl;
    }
    else
    {
        cout << "Remove first: failed" << endl;
    }
    displayList(head);

    // Part 7
    if (removeByID(head, tail, 104))
    {
        cout << "Remove Dark Mage: success" << endl;
    }
    else
    {
        cout << "Remove Dark Mage: failed" << endl;
    }

    displayList(head);

    if (removeByID(head, tail, 105))
    {
        cout << "Remove Dragon: success" << endl;
    }
    else
    {
        cout << "Remove Dragon: failed" << endl;
    }

    displayList(head);

    if (removeByID(head, tail, 999))
    {
        cout << "Remove ID 999: success" << endl;
    }
    else
    {
        cout << "Remove ID 999: not found" << endl;
    }
    cout << "Tail after last-node deletion: " << tail->data.id << endl;
    if (tail->data.id == 103 && tail->next == nullptr)
    {
        cout << "Tail correctly points to Troll: yes" << endl << endl;
    }
    else
    {
        cout << "Tail correctly points to Troll: no" << endl << endl;
    }

    // Part 8
    insertEnd(head, tail, necromancer);
    int tailTraversalMoves = 0; // insertEnd does not traverse to locate the last node.
    cout << "Pointer moves using tail: " << tailTraversalMoves << endl;
    cout << "Head traversal used " << headTraversalMoves
         << " moves; tail insertion used " << tailTraversalMoves << " moves." << endl;
    displayList(head);

    // Part 9
    cout << endl << "Edge-case tests:" << endl;
    EnemyNode* testHead = nullptr;
    EnemyNode* testTail = nullptr;
    if (removeFirst(testHead, testTail))
    {
        cout << "Remove first from empty list: success" << endl;
    }
    else
    {
        cout << "Remove first from empty list: safe - list is empty" << endl;
    }

    insertEnd(testHead, testTail, wraith);
    if (testHead == testTail)
    {
        cout << "One-node head and tail match: yes" << endl;
    }
    else
    {
        cout << "One-node head and tail match: no" << endl;
    }

    removeFirst(testHead, testTail);
    if (testHead == nullptr && testTail == nullptr)
    {
        cout << "Both pointers null after one-node removal: yes" << endl;
    }
    else
    {
        cout << "Both pointers null after one-node removal: no" << endl;
    }

    if (removeByID(testHead, testTail, 999))
    {
        cout << "Remove ID 999 from empty list: success" << endl;
    }
    else
    {
        cout << "Remove ID 999 from empty list: safe - not found" << endl;
    }

    insertEnd(testHead, testTail, wraith);
    EnemyNode* tailBeforeInsert = testTail;
    if (insertAfterID(testHead, testTail, 107, slime))
    {
        cout << "Insert after current tail: success" << endl;
    }
    else
    {
        cout << "Insert after current tail: failed" << endl;
    }

    if (testTail != tailBeforeInsert && tailBeforeInsert->next == testTail
        && testTail->data.id == 100 && testTail->next == nullptr)
    {
        cout << "Tail changed: yes" << endl;
    }
    else
    {
        cout << "Tail changed: no" << endl;
    }
    displayList(testHead);
    clearList(testHead, testTail);

    // Part 10
    cout << endl << "Patrol report:" << endl;
    patrolReport(head, tail);
    cout << "If the final node does not match tail, check the functions that update tail,"
         << " especially insertAfterID after the old tail or removeByID on the last node." << endl;

    // Part 11
    clearList(head, tail);
    displayList(head);
    if (head == nullptr && tail == nullptr)
    {
        cout << endl << "List cleared: yes" << endl;
    }
    else
    {
        cout << endl << "List cleared: no" << endl;
    }

    return 0;
}

