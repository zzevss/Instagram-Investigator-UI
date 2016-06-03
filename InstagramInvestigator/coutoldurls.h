#ifndef COUTOLDURLS_H
#define COUTOLDURLS_H
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
#endif // COUTOLDURLS_H



int countUrlsBase()
{
    int baseVectorElemCount = 0;
    std::vector<std::string> _linesVfile;

    ifstream ifs("base_url_list.db");
    for (std::string line; std::getline( ifs, line ); /**/ )
       _linesVfile.push_back( line );
    ifs.close();

    //remember count vector element
    baseVectorElemCount = _linesVfile.size();


    return (baseVectorElemCount);
}
