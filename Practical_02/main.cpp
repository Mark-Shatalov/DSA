#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int> score)
{
    for (auto it = score.begin(); it != score.end(); ++it)
    {
        std::cout << "Scores: " << *it << std::endl;
    }

}


int main()
{
    std::vector<int> scores
    {
        4200, 1800, 7600, 3500, 5900,
        2400, 8100, 4600, 3500, 6700
    };

    printVector(scores);

    std::cout << "\nThe total score is: " << scores.size() << std::endl;
    std::cout << "The first score is: " << scores.front() << std::endl;

    if (scores.empty())
    {
        std::cout << "The vector is empty." << std::endl;
    }
    else
    {
        std::cout << "The vector is not empty." << std::endl;
    }

    std::cout << "\nTASK 2" <<"\n";
    std::cout << "-------------------------------------------------------------------------\n" << std::endl;

    auto it = scores.begin();
    
    std::cout << "The first value: " << *it << std::endl;
    ++it;
    std::cout << "The second value: " << *it << "\n\n";

    short count = 0;
    for(auto it = scores.begin(); it != scores.end(); ++it)
    {
        std::cout << "Score " << count+1 << " is: " << *it << "\n";
        count++;
    }

    std::cout << "\nTASK 3" <<"\n";
    std::cout << "-------------------------------------------------------------------------\n" << std::endl;

    std::cout << "---Print in ascending order---\n";
    std::sort(scores.begin(), scores.end());
    
    printVector(scores);

    std::cout << "\n---Print reverse---\n\n";

    std::reverse(scores.begin(), scores.end());
    printVector(scores);

    // Q3A 
    // Because its already tested and optimized 

    std::cout << "\nTASK 4" <<"\n";
    std::cout << "-------------------------------------------------------------------------\n" << std::endl;

    int userPrompt = 0;
    std::cout << "Please enter a score to search: " << "\n";
    std::cin >> userPrompt;
    std::cout << "\n";

    auto find = std::find(scores.begin(), scores.end(), userPrompt);
    printVector(scores);
    std::cout << "\n";
    if (find != scores.end())
    {
        std::cout << "User prompt is found (" << userPrompt << ")\n";
    }
    else 
    {
        std::cout << "User prompt is not found (" << userPrompt << ")\n";
    }

    std::cout << "\nTASK 5" <<"\n";
    std::cout << "-------------------------------------------------------------------------\n" << std::endl;

    count = 0;
    std::for_each(scores.begin(), scores.end(),
        [&count](int n)
    {
        std::cout << "Scores " << count+1 << " is: " << n << " points" << "\n"; 
        count++;
    });
    std::cout << "\n";

    std::cout << "Scores after 250-point bonus: \n";

    std::for_each(scores.begin(), scores.end(),
        [](int& n)
    {
        n += 250;
        
    });
    printVector(scores);

    std::cout << "\n";


    std::cout << "\nTASK 6" <<"\n";
    std::cout << "-------------------------------------------------------------------------\n" << std::endl;

    std::cout << "---Print Original scores---\n\n";
    std::vector<int> original
    {
        4200, 1800, 7600, 3500, 5900,
        2400, 8100, 4600, 3500, 6700
    };
    printVector(original);

    std::cout << "\n---Print number of scores and the first score---\n\n";
    std::cout << "Size of vector: " << original.size() <<"\n";
    std::cout << "First score: " << original.front() << "\n";

    std::cout << "\n---Print highest to lowest order--- \n\n";
    
    std::sort(original.begin(), original.end());
    std::reverse(original.begin(), original.end());
    printVector(original);

    std::cout << "\n---Ask user to enter a score to search---\n\n";
    short askUser = 0;

    std::cout << "Please enter a score to search: \n";
    std::cin >> askUser; 

    auto findOriginal = std::find(original.begin(), original.end(), askUser);

    if(findOriginal != original.end())
    {
        std::cout << "User prompt is found (" << askUser << ")\n";
    }
    else 
    {
        std::cout << "User prompt is not found (" << askUser << ")\n";
    }

    std::cout << "\n---Score after 250-bonus---\n\n";
    std::for_each(original.begin(), original.end(),
        [](int& n)
    {
        n += 250;
    });
    printVector(original);

    return 0;
}