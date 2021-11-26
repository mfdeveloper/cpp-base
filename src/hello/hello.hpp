#ifndef HELLO_HPP
#define HELLO_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string hello() {

    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    string result;

    for (const string& word : msg)
    {
        result += word + " ";
        cout << result;
    }
    cout << endl;

    return result;
}
#endif
