//
//  time.hpp
//  FlightScheduling
//
//  Created by Jiang,Chao(AIP) on 18/2/6.
//  Copyright © 2018年 Jiang,Chao(AIP). All rights reserved.
//

/*
 <remark>=========================================================
 /// <summary>
 /// 机场停机位资源分配优化_时间类
 /// </summary>
 ===========================================================</remark>
 */
#pragma once

#ifndef time_hpp
#define time_hpp

#include <stdio.h>
#include "basic.hpp"

#pragma region 新建的类
////////////////////////////////////////////////////////////////////////
class Time;// 时间类

////////////////////////////////////////////////////////////////////////
#pragma endregion

class Time
{
public:
    
#pragma region Functions
    //////////////////////////////////////////////////////////////////////////
    
    //
    // 摘要:
    //     字符串转换为时间变量。
    static time_t StringToDatetime(string str);
    //
    // 摘要:
    //     时间变量转换为字符串。
    static string DatetimeToString(time_t time);
    
    //////////////////////////////////////////////////////////////////////////
#pragma endregion
};

#endif /* time_hpp */
