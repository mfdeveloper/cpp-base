#pragma once

#include <iostream>
#include <vector>
#include <string>

std::string hello()
{

    std::vector<std::string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    std::string result;

    for (const std::string& word : msg)
    {
        result += word + " ";
        std::cout << result;
    }
    std::cout << std::endl;

    return result;
}
