//
//  PredictFunc.cpp
//  MachineLearningProject
//
//  Created by 구동준 on 2023/04/15.
//

#include "PredictFunc.hpp"

PredictFunc::PredictFunc(){
    w0 = 0;
    w1 = 0;
}
void PredictFunc::printThis(){
    cout << "h(x) = " << w0 << " + "<< w1 << "x"  << endl;
}
double PredictFunc::retPreFunc(double x){
    return w1 * x + w0;
}
