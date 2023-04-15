//
//  MachineLearning.hpp
//  MachineLearningProject
//
//  Created by 구동준 on 2023/04/15.
//

#ifndef MachineLearning_hpp
#define MachineLearning_hpp

#include "mainHeader.h"
#include "PredictFunc.hpp"
#include <list>

#define inclineRange 5              // 정답 함수 기울기 범위
#define startNumRange 8             // 정답 함수 y0의 범위
#define learnigSpeed 0.001            // 학습상수
//#define dataNum 10                  // 데이터 개수


using namespace std;

/*--- 데이터 ---*/
typedef struct Data{
    double x, y;
    Data(double x, double y){this->x = x; this->y = y;}
}Data;


/*--- 머신러닝 프로그램 전신 ---*/
class Learner{
public:
    Learner();
    
    list<Data>data;
    list<Data>::iterator iter;
    void run();
private:
    int incline;                    // 정답 함수 기울기 (1~3)
    int startNum;                   // 정답 함수 y0 (-3~3)
    double costFunc;                // 비용함수
    
    void makeAnswerFunction();      // 정답 함수 생성
    void pushAllData();             // 데이터 값 생성 및 리스트에 넣기
    void printAllData();            // 모든 데이터 값 출력
    void getCostFunc();             // 비용함수 구하기
    void resetParameter();          // 파라미터 최적화
    
    PredictFunc* hx = new PredictFunc;
};


#endif /* MachineLearning_hpp */
