#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // store the size of the vector
        int size_of_vector = digits.size();

        // iterate from the back of the vector to the front
        for (int i = size_of_vector - 1; i >= 0; i--) {

            // this is the "easy" case.
            // if the number at the index is NOT a 9, just add 1 and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // if the number is a 9, you need to change it to 0
            digits[i] = 0;
        }

        // in the case all the numbers are 9
        // example: [9, 9, 9]
        // you need to declare a new vector
        // set all values equal to 0
        vector<int> new_vector(size_of_vector, 0);


        // make the first number (front) of the vector a 1
        new_vector.insert(new_vector.begin(), 1);
        // return new vector
        return new_vector;
    }
};
int main()
{
    Solution solution;
    stringstream string_stream;

    vector<int> example_one{ 1, 2, 3 };
    vector<int> example_one_answer = solution.plusOne(example_one);
    copy(example_one_answer.begin(), example_one_answer.end(), ostream_iterator<int>(string_stream, " "));
    string example_one_string = string_stream.str();

    string_stream.clear();
    string_stream.str("");

    vector<int> example_two{ 4, 3, 2, 1 };
    vector<int> example_two_answer = solution.plusOne(example_two);
    copy(example_two_answer.begin(), example_two_answer.end(), ostream_iterator<int>(string_stream, " "));
    string example_two_string = string_stream.str();

    string_stream.clear();
    string_stream.str("");

    vector<int> example_three{ 9 };
    vector<int> example_three_answer = solution.plusOne(example_three);
    copy(example_three_answer.begin(), example_three_answer.end(), ostream_iterator<int>(string_stream, " "));
    string example_three_string = string_stream.str();

    cout << "Example One: " << example_one_string << endl;
    cout << "Example Two: " << example_two_string << endl;
    cout << "Example Three: " << example_three_string << endl;

    return 0;
}
