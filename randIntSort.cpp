#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>


using namespace std;
using namespace std::chrono;

int main()
{
    string* array;
    array = new string[1000000];
    unsigned long long loop = 0;
    string line;
    ifstream myfile("random_integers.csv");

    if (myfile.is_open())
    {
        //read each line of file, store in array as string
        while (!myfile.eof())
        {
            getline(myfile, line);
            array[loop] = line;
            loop++;
        }
        myfile.close();
        
        //allocate new array, convert old array to ints
        int* array2;
        array2 = new int[1000000];
        for (int i = 1000000 - 1; i >= 0; i--)
            array2[i] = stoi(array[i]);
        
        //time process
        auto start = std::chrono::system_clock::now(); //start clock
        sort(array2, array2 + 1000000); //sort array
        auto end = std::chrono::system_clock::now(); //stop clock

        //print results
        cout << "Elapsed time in seconds: "
             << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
             << " ns" << endl;

        //free space
        delete[] array;
        delete[] array2;
    }

    else 
        cout << "can't open the file";

    system("PAUSE");

    return 0;
}