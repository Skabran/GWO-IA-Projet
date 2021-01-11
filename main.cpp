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
    SetUpParams setup{1, 66666, 30, 30};
    Problem prob{30, 4};
    optimizationAlgorithm GWO{prob, setup};
    GWO.lanceEtAffiche();
    return 0;
}
