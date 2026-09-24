#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> scores {50,20,80,30,60};
    std::vector<int> temporary { 1,2,3 };
    // Q1
    for (int i = 0; i < scores.size(); i++)
    {
        std::cout << "Scores " << i+1 << ": " << scores[i] << std::endl;
    }

    // Q2
    std::cout << "Size of vector: " << scores.size() << std::endl;
    
    // Q3
    if(scores.empty())
    {
        std::cout << "Vector is empty." << std::endl;
    }
    else
    {
        std::cout << "Vector contains data." << std::endl;
    }

    // Q4
    std::cout << "\nThe first element is: " << scores.front() << std::endl;

    // Q5
    // for (int i = 0; i < temporary.size(); i++)
    // {
    //     std::cout << "Temp " << i+1 << ": " << temporary[i] << std::endl;
    // }
    std::cout << "Temp size is: " << temporary.size() << std::endl;
    temporary.clear();
    std::cout << "Temp size is: " << temporary.size() << std::endl;
    
    ///////  Q 6
    std::cout << "\nScores size before adding a new value: " << scores.size() << std::endl;

    scores.push_back(90);
    for (int i = 0; i < scores.size(); i++)
    {
        std::cout << "Scores " << i+1 << ": " << scores[i] << std::endl;
    }
    std::cout << "Scores size after adding a new value: " << scores.size() << std::endl;

    // Q8
    auto it = scores.begin();
    std::cout << "\n" << *it <<"\n"; // value at the current pos
    ++it;   // move to the next pos
    std::cout << *it << "\n";
    ++it; 
    std::cout << *it << "\n\n";

    // Q9
    for (auto it = scores.begin(); it != scores.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // Q10 
    // .end() is a stopping iterator not the last element //

    // Q 11
    std::cout << "\n";
    for (auto it = scores.begin(); it != scores.end(); ++it)
    {
        *it = *it + 5;
        std::cout << *it << std::endl;
    }
    // we just added a 5 to each value in the vector

    // Q12
    std::cout << "\n";
    for (auto it = scores.begin(); it != scores.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::sort(scores.begin(), scores.end());
    std::cout << "\n";

    std::cout << "sorted in ascending order.\n";
    for (auto it = scores.begin(); it != scores.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // Q13 
    std::reverse(scores.begin(), scores.end());
    std::cout << "\n";

    std::cout << "reversed.\n";
    for (auto it = scores.begin(); it != scores.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // Q14
    std::cout << "\n";

    auto found =  std::find(scores.begin(), scores.end(), 60);
    if (found != scores.end())
    {
        std::cout << "60 found\n";
    }
    else
    {
        std::cout << "60 not found\n";
    }

    // Q15
    std::cout << "\n";
    auto found999 =  std::find(scores.begin(), scores.end(), 999);
    if (found999 != scores.end())
    {
        std::cout << "999 found\n";
    }
    else
    {
        std::cout << "999 not found\n";
    }

    // std::find() returns scores.end() when the value is not present
   


    // Q16 
    std::cout << "\n";
    std::for_each(scores.begin(), scores.end(),
        [](int n)
        {
            std::cout << n << " ";
        });
    // Q17
    std::cout << "\n";
    std::for_each(scores.begin(), scores.end(),
        [](int n)
        {
            std::cout << n * 2 << " ";
        });

    // Q18
    std::cout << "\n";
    std::for_each(scores.begin(), scores.end(),
        [](int& n)
        {
            n += 100;
        });
    std::cout << "\n";
    
    for(int value : scores)
    {
        std::cout << value << "" << std::endl;
    }
    
    // MINI CHALLENGE
    std::cout << "\n\n\n\n\n";
    std::vector<int> levelTimes {42, 35, 58, 31, 49, 35};
    

    std::cout << "Number of recorded times: " << levelTimes.size() << std::endl;
    std::cout << "The first element is: " << levelTimes.front() << std::endl;


    std::cout << "\n";
    std::sort(levelTimes.begin(), levelTimes.end());
    for (int values : levelTimes)
    {
        std::cout << "level seconds: " << values << std::endl;
    }

    std::cout << "\n";
    auto find_35 = std::find(levelTimes.begin(), levelTimes.end(), 35);
    if(find_35 != levelTimes.end())
    {
        std::cout << "35 found\n";
    }
    else
    {
        std::cout << "35 not found\n";
    }

    std::cout << "\n";
    std::reverse(levelTimes.begin(), levelTimes.end());
    for (int values : levelTimes)
    {
        std::cout << "level seconds: " << values << std::endl;
    }

    std::cout << "\n";
    std::for_each(levelTimes.begin(), levelTimes.end(),
        [](int n)
        {
            std::cout << n << " ";
        });

    return 0;
}

///////////////////////////////////////////////

// Q1 - What is the container in std::sort(scores.begin(), scores.end())?

// scores is a container

// Q2 What are the two iterators in that statement?

// scores.begin() and scores.end() - two iterators

// Q3 What does end() represent?

// represent the last position after the last element in the vector

// Q4 Which algorithm would you use to search for a specific value?

// std::find()

// Q5 What is the difference between [](int n) and [](int& n) when used with for_each?

// [](int n) - recieves a copy of the value(original vector is not changed), 
// [](int& n) - recieve a reference to the actual value (original vector can be changed)