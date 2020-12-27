// main.cpp
#include <sqlite3.h>
#include <iostream>

using std::cout;
using std::endl;

/* Build manually with,
mkdir build
cd build
cmake .. "-DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake"
make
 */

int main()
{
    cout<<"starting app"<<endl;
    cout<< sqlite3_libversion()<<endl;
    return 0;
}