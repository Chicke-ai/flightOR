//
//  random.cpp
//  FlightScheduling
//
//  Created by Jiang,Chao(AIP) on 18/2/6.
//  Copyright © 2018年 Jiang,Chao(AIP). All rights reserved.
//

/*
 <remark>=========================================================
 /// <summary>
 /// 机场停机位资源分配优化_随机数类
 /// </summary>
 ===========================================================</remark>
 */

#include "random.hpp"

void Random::Initialize()
{
    srand(unsigned(time(0)));//以当前时间作为随机数种子
    GetRandom();//随机数生成的时候，第一个数为坏点，清除掉
}

int Random::GetRandom(int min, int max)
{
    //rand(）是函数库中的函数，作用是产生一个1到RAND_MAX之间的整数
    return (int)(min + (max - min + 1) * rand() / (RAND_MAX + 1.0));
}

double Random::GetRandom()
{
    return (rand() / (RAND_MAX + 0.0));
}

vector<int> Random::GetRandomSequence(int lengthOfSeq)
{
    vector<int> randomSeq(lengthOfSeq);
    
    //初始化
    for (int i = 0; i < lengthOfSeq; i++)
    {
        randomSeq[i] = i;
    }
    
    //两两交换
    for (int i = 0; i < lengthOfSeq; i++)
    {
        int firstPos = GetRandom(0, lengthOfSeq - 1);
        int secondPos = GetRandom(0, lengthOfSeq - 1);
        int temp = randomSeq[firstPos];
        randomSeq[firstPos] = randomSeq[secondPos];
        randomSeq[secondPos] = temp;
    }
    
    return randomSeq;
}
