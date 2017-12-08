#ifndef _function4
#define _function4

#include <string>
using namespace std;

int GetLength(string word)
{
    int length = 3;
    word.size();
    return word.size();
}

void Test_GetLength()
{
    cout << "************ Test_GetLength ************" << endl;

    string input;
    int expectedOutput;
    int actualOutput;

    /* TEST 1 ********************************************/
    input = "cat";
    expectedOutput = 3;

    actualOutput = GetLength( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_GetLength: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_GetLength: Test 1 FAILED!" << endl;
    }

    /* TEST 2 ********************************************/
    // CREATE YOUR OWN TEST
    input = "mouse";             // change me
    expectedOutput = 5;     // change me

    actualOutput = GetLength( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_GetLength: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_GetLength: Test 1 FAILED!" << endl;
    }

    /* TEST 3 ********************************************/
    // CREATE YOUR OWN TEST
    input = "holographic";             // change me
    expectedOutput = 11;     // change me

    actualOutput = GetLength( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_GetLength: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_GetLength: Test 1 FAILED!" << endl;
    }
}

#endif



