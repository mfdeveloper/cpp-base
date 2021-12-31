#include "Resource.h"

void Resource::cancel()
{
    m_cancel.store(true);
}

void Resource::request(std::function<void(std::string status)> callback) 
{
    std::string status = "Started";

    for (int i = 0; i <= 10000; i++)
    {
        if (m_cancel.load())
        {
            status = "Canceled";
            break;
        }
        
        std::cout << "Value: " << i << std::endl;
    }

    if (!m_cancel.load())
    {
        status = "Completed";
    }

    callback(status);
}
