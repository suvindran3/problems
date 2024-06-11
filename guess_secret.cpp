#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Master
{
public:
    vector<string> choices;
    Master(vector<string> &words)
    {
        choices = words;
    }
    int guess(string word)
    {
        if (attempts > maxAttempt)
        {
            return -1;
        }
        int score = 0;
        bool isThere = contains(word);
        if (!isThere)
            return -1;
        for (int i = 0; i < 6; i++)
        {
            if (word[i] == chosenWord[i])
            {
                score++;
            }
            return score;
        }
        attempts++;
    }

    void setSecret()
    {
        int randomNum = sizeof(choices) / sizeof(choices[0]);
        chosenWord = choices[rand() % randomNum];
        cout << "The chosen word is: " << chosenWord << "\n";
    }

private:
    string chosenWord;
    const int maxAttempt = 10;
    int attempts = 0;

    bool contains(string word)
    {
        static int size = sizeof(choices) / sizeof(choices[0]);
        for (int i = 0; i < size; i++)
        {
            if (choices[i] == word)
            {
                return true;
            }
        }
        return false;
    }
};

void filterWords(vector<string> &words, map<string, int> scores, string genWord)
{
    string word = genWord;
    vector<string> foundWords = {};
    for (const auto &[key, value] : scores)
    {
        foundWords.push_back(key);
    }
    for (int i = 0; i < scores.size() - 1; i++)
    {
        if (scores[foundWords[i]] > 0)
        {
            for (int j = i + 1; j < scores.size(); j++)
            {
                for (int k = 0; k < 6; k++)
                {

                    if (foundWords[i][k] == foundWords[j][k])
                    {
                        genWord[k] = foundWords[i][k];
                    }
                }
            }
        }
    }
}

void guessTheWord(vector<string> &words, Master &master)
{
    map<string, int> guesses = {};
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            const int score = master.guess(words[i]);
            guesses[words[i]] = score;
        }
        else
        {
            const int score = master.guess(words[i]);
        }
    }
}

int main()
{
    vector<string> words = {"acckzz", "ccbazz", "eiowzz", "abcczz"};
    Master master = Master(words);
    Master *ref = &master;
    guessTheWord(words, *ref);
}