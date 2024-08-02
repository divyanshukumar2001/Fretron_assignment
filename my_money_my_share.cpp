/*
QUESTION CLARIFICATION QUESTION-->
    The apples available do not allow for an exact proportional distribution based on the amount paid. For example, if the apples cannot be divided in a way that matches the proportions exactly due to their discrete weights.
    Eg Apples - 200g 300g 100g 500g
    Lets just say Ram needs 500g
    Sham needs 300g
    Rahim needs 150g
    what to do in this condition as we can see Rahim's needs can't be fullfilled even though we have 300g of apples left?


    Individual person's targetWeight can be in decimals so I took double as data type


APPROACH-->
    First we calculate the totalWeight of apples.
    Then we calculate the individual person's apple needs -> totalWeight * (there percentage)/100
    Then we store the apples weight and there frequency inside of a hashmap
    Then we iterate in the hashmap, and keep on incrementing the each person's desired weight if it is present in the hashmap(there could be a case if no desired amount of apples are present in the map)
    Now we can decrement the frequency of that apple inside of the hashmap as we have used it.

SOURCES-->
    there is a similar question on gfg which I have solved earlier so I used that approach here
    https://www.geeksforgeeks.org/find-number-currency-notes-sum-upto-given-amount/

 */

#include <bits/stdc++.h>

using namespace std;

struct Person
{
    string name;
    double proportion;
    vector<int> apples;
};

int main()
{
    vector<int> appleWeights;
    int weight;

    // Input weights of apples
    cout << "Enter apple weight in gram (-1 to stop) : ";
    while (cin >> weight && weight != -1)
    {
        appleWeights.push_back(weight);
        cout << "Enter apple weight in gram (-1 to stop) : ";
    }

    // Calculate total weight
    double totalWeight = 0;
    unordered_map<int, int> weightFrequency;
    for (int w : appleWeights)
    {
        totalWeight += w;
        weightFrequency[w]++;
    }

    // Define people with their contributions
    vector<Person> people = {
        {"Ram", 50 / 100.0, {}},
        {"Sham", 30 / 100.0, {}},
        {"Rahim", 20 / 100.0, {}}};

    // Distribute apples based on proportion
    for (auto &person : people)
    {
        double targetWeight = totalWeight * person.proportion;

        for (auto it = weightFrequency.begin(); it != weightFrequency.end();)
        {
            if (targetWeight <= 0 || it->second == 0)
            {
                ++it;
                continue;
            }

            if (it->first <= targetWeight)
            {
                person.apples.push_back(it->first);
                targetWeight -= it->first;
                it->second--;
            }
            else
            {
                ++it;
            }
        }
    }

    // Output the result
    cout << "Distribution Result:\n";
    for (const auto &person : people)
    {
        cout << person.name << " : ";
        for (int i = 0; i < person.apples.size(); ++i)
        {
            cout << person.apples[i];
            if (i != person.apples.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }

    return 0;
}
