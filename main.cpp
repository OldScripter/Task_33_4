#include <iostream>

/**
 * @function Calculate average values array of T type with certain length.
 * @tparam [in] T Type of array values
 * @param [in] array Array of values to be used for calculation
 * @param [in] length Length of values array
 * @return [out] result Average values of certain number of values in array
 */
template <typename T>
double getAverage(T* array, int length)
{
    double result {0};
    for (int i = 0; i < length; ++i)
    {
        result += *(array + i);
    }
    result /= length;
    return result;
}

/**
 * @function Get several input values of type T from std::cin into array with certain length.
 * @tparam [in] T Type of input values
 * @param [in,out] array Array to be filled
 * @param [in] length Length of array to be filled
 */
template <typename T>
void getFromCin(T* array, int length)
{
    std::cout << "Please enter value (1 per line):\n";
    std::string input;
    for (int i = 0; i < length; ++i)
    {
        std::getline(std::cin, input);
        try
        {
            if (std::is_same<T, int>())
            {
                *(array + i) = std::stoi(input);
            }
            else if (std::is_same<T, float>())
            {
                *(array + i) = std::stof(input);
            }
            else if (std::is_same<T, double>())
            {
                *(array + i) = std::stod(input);
            }
            else
            {
                std::cin >> *(array + i);
            }
        }
        catch (...)
        {
            std::cerr << "Type is not supported. Please use int, float or double types.\n";
        }
    }
}

int main()
{
    int arrayInteger[5] {0};
    int length {5};
    double average {0};
    
    std::cout << "Please enter 5 integer values:\n";
    getFromCin(arrayInteger, length);
    average = getAverage(arrayInteger, length);
    std::cout << "Average is: " << average << "\n";

    double arrayDouble[5]{0};
    std::cout << "Please enter 5 double values:\n";
    getFromCin(arrayDouble, length);
    average = getAverage(arrayDouble, length);
    std::cout << "Average is: " << average << "\n";

    return 0;
}