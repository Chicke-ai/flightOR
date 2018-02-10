//
//  random.hpp
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

#pragma once

#ifndef random_hpp
#define random_hpp

#include <stdio.h>
#include "basic.hpp"

// 随机数类
class Random
{
public:
    //
    // 摘要:
    //     初始化随机数种子，并清除随机数坏点。
    static void Initialize();
    //
    // 摘要:
    //     得到给定范围内的随机数。
    //
    // 参数:
    //   min:
    //     随机数的最小值。
    //
    //   max:
    //     随机数的最大值。
    //
    // 返回结果:
    //     一个在大于等于min，小于等于max的随机数。
    static int GetRandom(int min, int max);
    //
    // 摘要:
    //     得到一个0到1之间的随机数（小数），包括0和1。
    //
    // 返回结果:
    //     一个大于等于0，小于等于1的小数。
    static double GetRandom();
    //
    // 摘要:
    //     获取一个随机序列。
    //
    // 参数:
    //   lengthOfSeq:
    //     随机序列的长度。
    //
    // 返回结果:
    //     一个长度为lengthOfSeq的随机序列，序列中元素取值为0, 1, 2, ..., lengthOfSeq - 1。
    static vector<int> GetRandomSequence(int lengthOfSeq);
};

#endif /* random_hpp */
