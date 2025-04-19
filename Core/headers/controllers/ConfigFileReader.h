//
// Created by siulo on 29/12/2024.
//

#ifndef DHMS_CONFIGFILEREADER_H
#define DHMS_CONFIGFILEREADER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <fstream>
#include <algorithm>
#include <wchar.h>

using namespace std;

struct ConfigObject{
    wstring persistenceMode;
};

class ConfigFileReader{
private:
    wstring string2wstring(const string &str){
        wstring result(&str[0], &str[str.size()]);
        return result;
    };

public:
    ConfigFileReader(){};

    ConfigObject getDefault(){
        ConfigObject out;
        out.persistenceMode = L"LIST";

        return out;
    };

    ConfigObject read_config(string fileName){
        ConfigObject out = this->getDefault();

        std::string str;
        // std::ifstream is RAII, i.e. no need to call close
        std::ifstream cFile(fileName);
        if(cFile.is_open()){
            while(!cFile.eof()){
                while(getline(cFile,str)){
                    std::string::size_type begin = str.find_first_not_of("\f\t\v");
                    //Skips blank lines
                    if(begin == std::string::npos)
                        continue;
                    //Skips #
                    if(std::string("#").find(str[begin]) != std::string::npos)
                        continue;
                    std::string firstWord;
                    try{
                        firstWord = str.substr(0, str.find(" "));
                    }
                    catch (std::exception &e){
                        firstWord = str.erase(str.find_first_of(" "), str.find_first_not_of(" "));
                    }
                    std::transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::toupper);
                    if(firstWord == "PERSISTENCE_MODE")
                        out.persistenceMode = string2wstring(str.substr(str.find(" ")+1, str.length()));
                }
            }
        }
        return out;
    }
};

#endif //DHMS_CONFIGFILEREADER_H
