#ifndef ADDURLLIST_H
#define ADDURLLIST_H
#endif // ADDURLLIST_H
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;


void addUrl(std::vector<std::string> _vector)
{
    bool findElem = false;
    std::vector<std::string> _linesVfile;

    ifstream ifs("base_url_list.db");
    for (std::string line; std::getline( ifs, line ); /**/)
       _linesVfile.push_back( line );

    ifs.close();


//-----compearing read and get string vectors
    for(int i = 0; i<_vector.size(); i++)
    {
        findElem = false;
        for(int j = 0; j<_linesVfile.size(); j++)
        {
            if(strcmp(_linesVfile[j].c_str(),_vector[i].c_str()) == 0)
            {
                findElem = true;
                break;
            }
        }
        if(!findElem)
        {

            _linesVfile.push_back(_vector[i]);
        }
    }

//recording to file updated vector
    fstream fileUrl;
    fileUrl.open("base_url_list.db");
    for(int i = 0; i < _linesVfile.size(); ++i)
    {
        fileUrl <<_linesVfile[i].c_str();
        fileUrl <<"\n";
    }
    fileUrl.close();
}
