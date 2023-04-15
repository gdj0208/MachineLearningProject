//
//  main.cpp
//  MachineLearningProject
//
//  Created by 구동준 on 2023/04/15.
//

/*
 선형함수 머신러닝 프로그램
 1. 선형 함수는 1차 함수로 설정되어있음
 2. 1차 함수 1개가 주어진다.
 3. 해당 1차 함수 주변에 여러 데이터들이 주어짐
    -> 예를 들어 y = x + 1일 경우 (1,2),(2,2.9),(3, 3.3),(4, 5.3)
 4. 이러한 데이터들을 통해서 경사하강 방식을 통해 예측함수의 파라미터를 구함
 5. 예측함수들의 변화 과정을 보여주고 마지막 데이터의 x값보다 1 더 큰 x값에 대해 예측되는 y값을 출력함
 */

#include "mainHeader.h"
#include "MachineLearning.hpp"


int main() {
    /*--- 기본 설정 ---*/
    srand(time(NULL));
    
    /*--- 변수 선언 ---*/
    Learner* machineLearner = new Learner;
    
    /*--- 메인 메쏘드 활성화 ---*/
    machineLearner->run();
    
    /*--- 동적 할당 해제 ---*/
    delete machineLearner;
}
