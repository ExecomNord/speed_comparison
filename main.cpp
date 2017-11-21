#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <istream>
#include <sstream>

using namespace std;

double shortBubbleSort(vector<int> alist)
{
    auto start = chrono::duration_cast<std::chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
    bool exchanges = true;
    int passnum = alist.size() - 1;
    int temp;
    while (passnum > 0 and exchanges)
    {
        exchanges = false;
        for (int i = 0; i < passnum; i++)
        {
            if (alist[i] > alist[i+1])
            {
                exchanges = true;
                temp = alist[i];
                alist[i] = alist[i + 1];
                alist[i + 1] = temp;            }
        }
        passnum--;
    }
    auto end = chrono::duration_cast<std::chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return (end - start) / 10000000.0;
}

int main()
{
    double totalTime = 0;
    double time;
    ifstream file("test_data.csv");
    string csvLine;
    while (file.good())
    {
         getline(file, csvLine);
         std::istringstream csvStream(csvLine);
         vector<int> csvRow;
         string csvCol;
         while(std::getline(csvStream, csvCol, ','))
            csvRow.push_back(stoi(csvCol));
         time = shortBubbleSort(csvRow);
         cout << "Number of elements: " <<  csvRow.size()
              << " done in: " << time << endl;
         totalTime += time;

    }

    cout << "Total time: " << totalTime << endl;
    return 0;
}
