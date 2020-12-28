// main.cpp
#include <sqlite3.h>
#include <iostream>
#include <nlohmann/json.hpp>

using std::cout;
using std::endl;

/* Build manually with,
mkdir build
cd build
cmake ..
make
 */

int main()
{
    cout<<"starting app"<<endl;
    cout<< sqlite3_libversion()<<endl;

    nlohmann::json j;
    return 0;
}