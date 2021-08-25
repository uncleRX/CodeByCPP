//
//  main.cpp
//  命名空间
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>

using namespace std;

namespace IroTeam
{
    void echo()
    {
        cout << "IroTeam first_space" << endl;
    }
}

namespace DTTeam
{
    void echo()
    {
        cout << "DTTeam first_space" << endl;
    }
}

//嵌套命名空间
namespace space1 {

    void echo()
    {
        cout << "space1 first_space" << endl;
    }
    namespace space2 {
        void echo()
        {
            cout << "space2 first_space" << endl;
        }
    }
}

//using namespace IroTeam;
using namespace space1::space2;
//using namespace std;

int main(int argc, const char * argv[]) {

    echo();
//    DTTeam::echo();
    return 0;
}
