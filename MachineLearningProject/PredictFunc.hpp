//
//  PredictFunc.hpp
//  MachineLearningProject
//
//  Created by 구동준 on 2023/04/15.
//

#ifndef PredictFunc_hpp
#define PredictFunc_hpp

#include "mainHeader.h"
#define dataNum 50          // 데이터 개수

/*--- 예측함수 ---*/
class PredictFunc{
public:
    PredictFunc();
    
    double w0, w1;          // 각 파라미터
    double tmp0, tmp1;      // 각 파라미터를 잠깐 저장하는 변수
    double Dw0, Dw1;        // 각 파라미터의 변화율
    
    void printThis();       // 비용함수 출력
    double retPreFunc(double x);    // 예측함수 반환
private:
};

#endif /* PredictFunc_hpp */
