/*
Title: Homework 3.1 Evaluating performance of STL containers.
Author: Anik Barua
Version: 1.0
Date: 04-18-2021

Description: This C++ program evaluates the performance of STL containers (vector, list, set, unordered_set) by inserting and 
finding elements, with a relatively large data set. It measures the execution time and outputs the relative to the vector's 
speed in percentage.
*/

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <unordered_set>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

//Universal fuction for inserting at end and it returns the time.
template <typename T>
//v is the main vector and c is the container
double insertEnd(vector<int> &v, T &c)
{
    auto t0 = chrono::steady_clock::now(); //Start clock time

    //Insertion using iterator position returned by c.end()
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        c.insert(c.end(), *itr);
    }
    auto t1 = chrono::steady_clock::now(); //End clock time

    double time = double(chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()); //In milliseconds
    return time;
}

//Universal fuction for inserting at begin and it returns the time
template <typename T>
//v is the main vector and c is the container
double insertBegin(vector<int> &v, T &c)
{
    auto t0 = chrono::steady_clock::now(); //Start clock time

    //Insertion using iterator position returned by c.begin()
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        c.insert(c.begin(), *itr);
    }
    
    auto t1 = chrono::steady_clock::now(); //End clock time

    double time = double(chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()); //In milliseconds
    return time;
}

//Percentage function
double relativePercentage(double t1, double t2)
{
    return (t1 / t2) * 100;
}

int main()
{
    vector<int> v(100000); //Created a 100k int element vector
    int size = v.size();   // Size of vector

    //Initially setting the values 1~100,000
    for (int i = 0; i < size; i++)
    {
        v.at(i) = i + 1; //Fills up the numbers
    }

    //Randomize the order through shuffle
    shuffle(v.begin(), v.end(), default_random_engine(time(NULL)));

    //4 containers
    vector<int> vec1; 
    list<int> list1; 
    set<int> set1; 
    unordered_set<int> unorderedSet1; 

    //Vector
    double insertVec1 = insertEnd(v, vec1); //Inserting at .end()
    cout << "Total time for vector inserting at end: " << insertVec1 << " msec." << endl;

    vec1.clear(); //Clearing the containers
    double insertVec2 = insertBegin(v, vec1); //Inserting at .begin()
    cout << "Total time for vector inserting at begin: " << insertVec2 << " msec." << endl;

    //Find each value (1 to 10k) in the vector
    auto vt0 = chrono::steady_clock::now(); //Start clock time
    for (int i = 1; i <= 10000; i++)
    {
        find(vec1.begin(), vec1.end(), i); //Using "find" from the algorithm to find the values
    }
    auto vt1 = chrono::steady_clock::now(); //End clock time
    double timeVec = double(chrono::duration_cast<chrono::milliseconds>(vt1 - vt0).count()); //In milliseconds
    cout << "Total time for finding 10K numbers in vector: " << timeVec << " msec.\n";

    cout << "\n";

    //List
    double insertList1 = insertEnd(v, list1); //Inserting at .end()
    cout << "Total time for list inserting at end: " << insertList1 << " msec." << endl;

    list1.clear(); //Clearing the containers
    double insertList2 = insertBegin(v, list1); //Inserting at .begin()
    cout << "Total time for list inserting at begin: " << insertList2 << " msec." << endl;

    //Find each value (1 to 10k) in list
    auto lt0 = chrono::steady_clock::now(); //Start clock time
    for (int i = 1; i <= 10000; i++)
    {
        find(list1.begin(), list1.end(), i); //Using "find" from the algorithm to find the values
    }
    auto lt1 = chrono::steady_clock::now(); //End clock time
    double timeList = double(chrono::duration_cast<chrono::milliseconds>(lt1 - lt0).count()); //In milliseconds
    cout << "Total time for finding 10K numbers in list: " << timeList << " msec.\n";

    cout << "\n";

    //Set
    double insertSet1 = insertEnd(v, set1); //Inserting at .end()
    cout << "Total time for set inserting at end: " << insertSet1 << " msec." << endl;

    set1.clear(); //Clearing the containers
    double insertSet2 = insertBegin(v, set1); //Inserting at .begin()
    cout << "Total time for set inserting at begin: " << insertSet2 << " msec." << endl;

    //Find each value (1 to 10k) in set
    auto st0 = chrono::steady_clock::now(); //Start clock time
    for (int i = 1; i <= 10000; i++)
    {
        set1.find(i); //Uses the member function "find" of the set
    }
    auto st1 = chrono::steady_clock::now(); //End clock time
    double timeSet = double(chrono::duration_cast<chrono::milliseconds>(st1 - st0).count()); //In milliseconds
    cout << "Total time for finding 10K numbers in set: " << timeSet << " msec.\n";
    
    cout << "\n";

    //Unordered set
    double insertUset1 = insertEnd(v, unorderedSet1); //Inserting at .end()
    cout << "Total time for unordered set inserting at end: " << insertUset1 << " msec." << endl;

    unorderedSet1.clear(); //Clearing the containers
    double insertUset2 = insertBegin(v, unorderedSet1); //Inserting at .begin()
    cout << "Total time for unordered set inserting at begin: " << insertUset2 << " msec." << endl;

    //Find each value (1 to 10k) in Unordered Set
    auto ut0 = chrono::steady_clock::now(); //Start clock time
    for (int i = 1; i <= 10000; i++)
    {
        unorderedSet1.find(i); //Uses the member function "find" of the set
    }

    auto ut1 = chrono::steady_clock::now(); //End clock time
    double timeUnSet = double(chrono::duration_cast<chrono::milliseconds>(ut1 - ut0).count()); //In milliseconds
    cout << "Total time for finding 10K numbers in uordered set: " << timeUnSet << " msec.\n";

    cout << "\n";

    //Percentage relative to vector for insert end
    cout << "For list insert end, percentage relative to vector time: " << relativePercentage(insertList1, insertVec1) << "%" << endl;
    cout << "For set insert end, percentage relative to vector time: " << relativePercentage(insertSet1, insertVec1) << "%" << endl;
    cout << "For unordered set insert end, percentage relative to vector time: " << relativePercentage(insertUset1, insertVec1) << "%" << endl;

    cout << "\n";
    //Percentage relative to vector for insert begin
    cout << "For list insert begin, percentage relative to vector time: " << relativePercentage(insertList2, insertVec2) << "%" << endl;
    cout << "For set insert begin, percentage relative to vector time: " << relativePercentage(insertSet2, insertVec2) << "%" << endl;
    cout << "For unordered set insert begin, percentage relative to vector time: " << relativePercentage(insertUset2, insertVec2) << "%" << endl;

    cout << "\n";
    //Percentage relative to vector for find
    cout << "For list find, percentage relative to vector time: " << relativePercentage(timeList, timeVec) << "%" << endl;
    cout << "For set find, percentage relative to vector time: " << relativePercentage(timeSet, timeVec) << "%" << endl;
    cout << "For unordered set find, percentage relative to vector time: " << relativePercentage(timeUnSet, timeVec) << "%" << endl;

    return 0;
}