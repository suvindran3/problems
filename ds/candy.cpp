#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    void checkNeighbors()
    {
        if (leftAssigned)
        {
            if (left->rating > this->rating && left->candies <= this->candies)
            {
                left->increment();
            }
        }
        if (rightAssigned)
        {
            const bool shouldDistribute = right->rating > this->rating && right->candies <= this->candies;
            if (right->rating > this->rating && right->candies <= this->candies)
            {
                right->increment();
            }
        }
    }

public:
    Student(int v)
    {
        candies = 1;
        rating = v;
    }
    int rating;
    int candies;
    bool leftAssigned = false;
    bool rightAssigned = false;
    Student *left;
    Student *right;

    void linkLeft(Student *l)
    {
        // cout<<"Linked to: "<<l->rating<<" ["<<rating<<"]"<<"\n";
        left = l;
        leftAssigned = true;
        l->linkRight(this);
    }

    void linkRight(Student *r)
    {
        right = r;
        rightAssigned = true;
    }

    void startDistribution()
    {
        checkNeighbors();
    }

    void increment()
    {
        candies++;
        checkNeighbors();
    }
};

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int candiesRequired = 0;
        vector<Student> students = {};
        for (auto r : ratings)
        {
            Student student = Student(r);
            students.push_back(student);
        }
        for (size_t i = 1; i < students.size(); i++)
        {
            students[i - 1].linkLeft(&students[i]);
        }
        for (auto s : students)
        {
            s.startDistribution();
        }
        for (auto s : students)
        {
            candiesRequired += s.candies;
        }
        return candiesRequired;
    }
};

int main()
{
    vector<int> ratings = {1, 3, 2, 2, 1};
    const int solution = Solution().candy(ratings);
    cout << "Number of candies required: " << solution << "\n";
}
