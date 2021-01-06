#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "optimizationAlgorithm.h"
#include "Problem.h"
#include "SetUpParams.h"

using namespace std;

int main()
{
    cout<<"balise0"<<endl;
    SetUpParams setup{1, 2000000, 30, 30};
    cout<<"balise1"<<endl;
    Problem prob{30, 1};
    cout<<"balise2"<<endl;
    optimizationAlgorithm GWO{prob, setup};
    cout<<"balise3"<<endl;
    GWO.lanceEtAffiche();
    cout<<"balise4"<<endl;
    return 0;
}
