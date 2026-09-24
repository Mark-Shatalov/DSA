
// Mark Shatalov 
// C00312571

#include <iostream>
#include <vector>

template <typename T>
T largest(std::vector<T> values)
{
    T largestValue = values[0];

    for(T value: values)
    {
        if(value > largestValue)
        {
            largestValue = value;
        }
    }
    return largestValue;
}

template <typename T>
T smallest(std::vector<T> values)
{
    T smallestValue = values[0];
    
    for(T value: values)
    {
        if(value < smallestValue)
        {
            smallestValue = value;
        }
    }
    return smallestValue;
}


int main()
{
    int total = 0;
    int count = 0;

    
    std::vector<int> scores = {120, 450, 230, 900, 340};
    
    std::vector<float> speeds = {3.5f, 7.2f, 4.8f, 9.1f};

    for (int score : scores)
    {
        total += score;
        std::cout << score << std::endl;
        if(score > 300)
        {
            count +=1;
        }
    }
    std::cout << "\nThe total amount is:" << total << std::endl;
    std::cout << "How many numbers above 300:" << count << std::endl;
    std::cout << "\nHighest score is: " << largest(scores) << std::endl;
    std::cout << "Highest speed is: " << largest(speeds) << std::endl;
    std::cout << "\nSmallest value is:" << smallest(scores) << std::endl;
    std::cout << "Smallest value is:" << smallest(speeds) << std::endl;

    return 0;
}


// Question 1 
// What does vector <int> mean?
// vector<int> is a dynamic array which store integer data type

// Question 2
// In largest(), what is the algorithm doing?
// the largest alghorithm is checking the largest number through array 

// Question 3
// Why did largest(vector<int>) fail when we passed vector<float>?
// because its diffrent data type, that means you cannot pass the float data type to integer

// Question 4 
// What does T represent in template <typename T>?
// this template allows us to pass different types of data without literally duplicating the function

// Question 5
// In one sentence: why are templates useful?
// you dont need to repeat code for same alghoritms and different types of data