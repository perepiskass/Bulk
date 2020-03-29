#include "bulk.h"


//-----checkDilimiter------------------------------------------
    void Bulk::checkDilimiter(std::string& str)
    {
        if (str == "{")
        {
            if(checkD.first) ++checkD.second;
            else
            {
                bulk.clear();
                checkD.first = true;
                ++checkD.second;
            }
            
        }
        else if (str == "}")
        {
            if (checkD.second) --checkD.second;
        }
    }

//-----writeToFile---------------------------------------------
    void Bulk::writeFile()
    {
        std::ofstream out;
        auto timeUNIX = this->time.count();
        std::string path = "bulk"+ std::to_string(timeUNIX) + ".log";
        out.open(path);
        if (out.is_open(),std::ios::app)
        {
            out << "bulk: ";
            for(auto& str : this->bulk)
            {
                if(str==this->bulk[0]) out << str;
                else out << ", " << str;
            }
        }
        out.close();
    }
//-----clearData-----------------------------------------------
    void Bulk::clearData()
    {
        bulk.clear();
        checkD.first = false;
        checkD.second = 0;
        countTry = count;
    }
//-----Constructor---------------------------------------------
    Bulk::Bulk(int count):count(count),countTry(count)
    {

    }

//-----setData--------------------------------------------------
    void Bulk::setData(std::string&& str)
    {
        checkDilimiter(str);
        if(checkD.first)
        {
            if (str!="{" && str!="}")
            {
                if(bulk.size() == 0) time = std::chrono::seconds(std::time(NULL));
                bulk.emplace_back(str);
            }
            else if (!checkD.second)
            {
                printData();
            }
        }
        else
        {
            if (str!="{" && str!="}" && countTry)
            {
                if(bulk.size() == 0) time = std::chrono::seconds(std::time(NULL));
                bulk.emplace_back(str);
                --countTry;
            }
            if(!countTry)
            {
                printData();
            }
        }
        
    }

//-----printData---------------------------------------------
    void Bulk::printData()
    {
        std::cout << "bulk: ";
        for(auto& str : bulk)
        {
            if(str==bulk[0]) std::cout << str;
            else std::cout << ", " << str;
        }
        std::cout << std::endl;
        //std::cout << time.count() << std::endl;
        writeFile();
        clearData();
    }
//-----getQuantity-------------------------------------------
    int Bulk::getQuantity()
    {
        return bulk.size();
    }

