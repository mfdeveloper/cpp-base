#pragma once

#include <vector>
#include <functional>
#include <iostream>
#include <atomic>

class Resource
{
private:
    std::atomic<bool> m_cancel {false};
public:
    Resource(/* args */) {}
    ~Resource() = default;

    void cancel();
    void request(std::function<void(std::string status)> callback);
};