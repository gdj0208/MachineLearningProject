//
//  MachineLearning.cpp
//  MachineLearningProject
//
//  Created by 구동준 on 2023/04/15.
//

#include "MachineLearning.hpp"

Learner::Learner(){
    makeAnswerFunction();
    pushAllData();
}
void Learner::run(){
    printAllData();             // 정답 함수와 데이터들 출력
    getCostFunc();              // 비용함수 구하기
    resetParameter();           // 파라미터 재설정
    hx->printThis();            // 예측 함수 출력
    cout << "x : " << dataNum + 1 << endl <<
    "y : " << hx->retPreFunc(dataNum + 1) << endl;
}
void Learner::makeAnswerFunction(){
    // 무작위로 데이터가 주변에 분포할 함수의 기울기와 y0를 구함
    incline = rand() % inclineRange;
    startNum = rand() % startNumRange;
}
void Learner::pushAllData(){
    // 모든 데이터 값을 넣음
    // 오차 범위는 -1 ~ +₩
    for(int i = 0; i < dataNum; i++){
        data.push_back(Data(i+1,incline*(i+1) + startNum + 0.1*(rand()%10)));
    }
}
void Learner::printAllData(){
    cout << "y = " << incline << "x + " << startNum << endl;
    
    for(iter = data.begin(); iter != data.end(); iter++){
        cout << "data {x:" << iter->x << " y:" << iter->y << "}" <<endl;
    }
}
void Learner::getCostFunc(){
    // 비용 함수 계산
    costFunc = 0;
    for(iter = data.begin(); iter != data.end(); iter++){
        costFunc += pow(hx->retPreFunc(iter->x), 2);
    }
    costFunc /= 2*dataNum;
}
void Learner::resetParameter(){
    double tmp;
    while(1){
        hx->Dw0 = hx->w0;
        hx->Dw1 = hx->w1;
        
        // 변화된 파라미터 임시저장
        tmp = 0;
        for(iter = data.begin(); iter != data.end(); iter++){
            tmp += hx->retPreFunc(iter->x) - iter->y;
        }
        hx->tmp0 = hx->w0 - learnigSpeed/dataNum*tmp;
        
        tmp = 0;
        for(iter = data.begin(); iter != data.end(); iter++){
            tmp += (hx->retPreFunc(iter->x) - iter->y)*iter->x;
        }
        hx->tmp1 = hx->w1 - learnigSpeed/dataNum*tmp;
        
        // 변화된 파라미터 완전 저장
        hx->w0 = hx->tmp0;
        hx->w1 = hx->tmp1;
        
        // 변화된 예측함수 출력
        hx->printThis();
        
        // 두 파라미터의 변화량이 0.0001 미만이면 최신화 그만
        if(abs(hx->Dw0 - hx->w0) < 0.0001 && abs(hx->Dw1 - hx->w1) < 0.0001) {break;}
    }
}
