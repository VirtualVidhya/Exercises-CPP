#include <iostream>

int main()
{
    const int QUES_CNT = 10;
    char correct_answers[QUES_CNT] = {'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B'};
    char student_answers[QUES_CNT];
    int correct_count = 0;

    std::cout << "Enter student answers: ";

    for (int i = 0; i < QUES_CNT; i++)
    {
        std::cin >> student_answers[i];
    }

    for (int i = 0; i < QUES_CNT; i++)
    {
        if (student_answers[i] == correct_answers[i])
        {
            correct_count++;
        }
    }

    int score = correct_count * 10;

    std::cout << "\nTotal correct answers: " << correct_count << '\n';
    std::cout << "Score: " << score << '\n';

    return 0;
}