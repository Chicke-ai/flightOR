////
////  main3_greedy.cpp
////  FlightScheduling
////
////  Created by Jiang,Chao(AIP) on 18/3/6.
////  Copyright © 2018年 Jiang,Chao(AIP). All rights reserved.
////
//
//#include <iostream>
//
//#include "flight.hpp"
//#include "gatePosition.hpp"
//#include "bestSolution.hpp"
//
//
//
//void solveByCplex();
//bool isSubset(vector<int>, vector<int>);
//
//int main()
//{
//#pragma region 调试使用
//    //////////////////////////////////////////////////////////////////////////
//    {
//        Flight::s_mapSetOfFlight;
//        GatePosition::s_mapSetOfGatePosition;
//        Road::s_mapSetOfRoad;
//        BestSolution::m_solution;
//    }
//    ////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//#pragma region 初始化数据
//    ////////////////////////////////////////////////////////////////////////
//    //    clock_t start, finish, time1, time2;
//    time_t start, finish, time1, time2;
//    double duration1, duration2, duration3, duration4, duration5, duration6, duration7;
//    //    start = clock();							//开始计时(总)
//    //    time1 = clock();
//    time(&start);
//    time(&time1);
//    Flight::readData();
//    GatePosition::readData();
//    Flight::initNumberCount();
//    Road::initRoad();
//    GatePosition::initBeConflict();
//    time(&time2);
//    //    time2 = clock();
//    //    duration1 = (time2 - time1) / (double)CLOCKS_PER_SEC;
//    //    cout << "Clocks_per_sec: " << CLOCKS_PER_SEC << endl;
//    //    cout << "初始化数据用时 : " << duration1 << " 秒" << endl;	//显示花费时间
//    cout << "初始化数据用时 : " << difftime(time2, time1) << " 秒" << endl;	//显示花费时间
//    ////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//    for (static map<string, Flight *>::iterator iter = Flight::s_mapSetOfFlight.begin(); iter != Flight::s_mapSetOfFlight.end(); iter++)
//    {
//        if (iter->second->m_inTime_t == -1 || iter->second->m_outTime_t == -1)
//        {
//            cout << "error";
//        }
//    }
//    for (static map<string, Flight *>::iterator iter = Flight::s_mapSetOfwrongFlight.begin(); iter != Flight::s_mapSetOfwrongFlight.end(); iter++)
//    {
//        if (iter->second->m_inTime_t == -1 || iter->second->m_outTime_t == -1)
//        {
//            cout << "error";
//        }
//    }
//    
//#pragma region 获得航班可以使用的所有机位
//    ////////////////////////////////////////////////////////////////////////
//    time1 = clock();
//    Flight::GetFeasibleGatePosition();
//    time2 = clock();
//    duration2 = (time2 - time1) / (double)CLOCKS_PER_SEC;
//    cout << "获得所有航班可用机位用时 : " << duration2 << " 秒" << endl;	//显示花费时间
//    ////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//#pragma region 获得机位可以停放的所有航班
//    ////////////////////////////////////////////////////////////////////////
//    time1 = clock();
//    GatePosition::GetFeasibleFlight();
//    time2 = clock();
//    duration3 = (time2 - time1) / (double)CLOCKS_PER_SEC;
//    cout << "获得机位可以停放的所有航班用时 : " << duration3 << " 秒" << endl;	//显示花费时间
//    ////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//#pragma region 输出cplex求解所需输入
//    //////////////////////////////////////////////////////////////////////////;
//    {
//        time1 = clock();
//        string str = "NMR.txt";
//        ofstream NM(str.c_str());
//        NM << Flight::s_flightCount << " " << GatePosition::s_gatePositionCount << " " << Road::s_roadCount << " " << Flight::s_nemberCount << endl;
//        NM << "[";
//        int i = 0;
//        for (map<string, Road *>::iterator iter = Road::s_mapSetOfRoad.begin(); iter != Road::s_mapSetOfRoad.end(); iter++)
//        {
//            if (iter->first == "无限制" || iter->first == "")
//                NM << 0;
//            else
//                NM << 1;
//            i++;
//            if (i == Road::s_roadCount)
//                NM << "]";
//            else
//                NM << ",";
//        }
//        NM.close();
//        Flight::printTime();
//        GatePosition::PrintFeasibleFlight();
//        GatePosition::PrintDistance();
//        Flight::printRoadTime();
//        Road::printGatePositionToRoad();
//        Flight::printConflictFlight();
//        Flight::printNumberOfFlight();
//        GatePosition::PrintConflictFlight();
//        GatePosition::PrintTemporaryMeasures();
//        GatePosition::PrintConflictGatePosition();
//        GatePosition::PrintInfluenceGatePosition();
//        time2 = clock();
//        duration4 = (time2 - time1) / (double)CLOCKS_PER_SEC;
//        cout << "输出cplex求解所需输入用时 : " << duration4 << " 秒" << endl;	//显示花费时间
//    }
//    ////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//#pragma region CPLEX求解
//    //////////////////////////////////////////////////////////////////////////
//    //    time1 = clock();
//    time(&time1);
//    solveByCplex();
//    time(&time2);
//    //    time2 = clock();
//    //    duration5 = (time2 - time1) / (double)CLOCKS_PER_SEC;
//    //    cout << "CPLEX求解用时 : " << duration5 << " 秒" << endl;	//显示花费时间
//    cout << "CPLEX求解用时 : " << difftime(time2, time1) << " 秒" << endl;	//显示花费时间
//    ////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//#pragma region 打印结果
//    //////////////////////////////////////////////////////////////////////////
//    time1 = clock();
//    BestSolution::updateValueByCplexSolver();
//    BestSolution::deleteWrongValue();
//    BestSolution::heuristicForUndistributed();
//    BestSolution::updateBestValue();
//    BestSolution::printBestResult();
//    string str = "";
//    ostringstream oss;
//    oss << BestSolution::m_objValue;
//    str = oss.str();
//    string result = "usedTimeWhenBestResult=" + str + ".txt";
//    ofstream fout(result.c_str());
//    time2 = clock();
//    duration6 = (time2 - time1) / (double)CLOCKS_PER_SEC;
//    cout << "存储结果到csv文件用时 : " << duration6 << " 秒" << endl;	//显示花费时间
//    //////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//#pragma region 统计花费时间
//    //////////////////////////////////////////////////////////////////////////
//    finish = clock();								//终止计时(总)
//    duration7 = duration1 + duration2 + duration3 + duration4 + duration5 + duration6;
//    cout << "程序总用时 : " << duration7 << " 秒" << endl;	//显示花费时间
//    //////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//#pragma region 输出各段时间到文件
//    //////////////////////////////////////////////////////////////////////////
//    fout << "初始化数据用时 : " << duration1 << " 秒" << endl;	//显示花费时间
//    fout << "获得所有航班可用机位用时 : " << duration2 << " 秒" << endl;	//显示花费时间
//    fout << "获得机位可以停放的所有航班用时 : " << duration3 << " 秒" << endl;	//显示花费时间
//    fout << "输出cplex求解所需输入用时 : " << duration4 << " 秒" << endl;	//显示花费时间
//    fout << "CPLEX求解用时 : " << duration5 << " 秒" << endl;	//显示花费时间
//    fout << "存储结果到csv文件用时 : " << duration6 << " 秒" << endl;	//显示花费时间
//    fout << "程序总用时 : " << duration7 << " 秒" << endl;	//显示花费时间
//    ////////////////////////////////////////////////////////////////////////
//#pragma endregion
//    
//    system("pause");
//    return 0;
//}
//
//void solveByCplex()
//{
//    // 定义CPLEX环境
//    IloEnv env;
//    
//    try {
//        // i航班号，j停机位，k滑道号
//        int i, j, k;
//        // 权重
//        int parameter1 = 10;
//        int parameter2 = 3;
//        int parameter3 = 3;
//        int parameter4 = 1;
//        int parameter5 = 1;
//        
//        // 从文件中读取数据
//        ifstream f("NMR.txt");									// 航班数量(N)、停机位数量(M)、滑道数量(R)、旅客数、滑道是否为无限制(1*R)
//        ifstream flightTime("flightTime.txt");					// 航班进港时间(1*N)、出港时间(1*N)
//        ifstream feasibleFlightFile("feasibleFlight.txt");			// 航班-机位可否停放(N*M)
//        ifstream distanceFile("distance.txt");					// 机位为近机位1或远机位0(1*M)
//        ifstream flightRoadTime("flightRoadTime.txt");			// 航班进港时进入滑道时间(1*N)、进港时离开滑道时间(1*N)、出港时进入滑道时间(1*N)、出港时离开滑道时间(1*N)
//        ifstream gatePositionToRoadFile("gatePositionToRoad.txt");	// 机位-滑入滑道对应(M*R)、机位-推出滑道对应(M*R)
//        ifstream conflictFlightFile("conflictFlight.txt");			// 滑道时间上冲突的航班(N*N)，不考虑安排的滑道及机位。分别打印航班A与航班B，滑入滑道冲突、推出滑道冲突、滑入与推出、推出与滑入
//        ifstream numberOfFlightFile("numberOfFlight.txt");			// 每架航班的旅客数量(1*N)
//        ifstream temporaryMeasuresFile("temporaryMeasures.txt");	// 机位是否为临时措施，是临时措施为1，不是为0(1*M)
//        ifstream conflictGatePositionFile("conflictGatePosition.txt");	// 不能同时使用的机位(M*M)，若不能同时使用则为1
//        ifstream influenceGatePositionFile("influenceGatePosition.txt");	// 所影响滑入的机位(M*M)，所影响滑出的机位(M*M)，若影响为1
//        
//        // 定义已知常量
//        IloInt N, M, R;										// 航班数量(N)、停机位数量(M)、滑道数量(R)
//        IloInt allNumber;										// 总旅客人数
//        IloIntArray _tin(env);									// 航班进港时间(1*N)
//        IloIntArray _tout(env);								// 航班出港时间(1*N)
//        IloArray<IloIntArray> _feasibleFlight(env);				// 航班-机位可否停放(N*M)
//        IloIntArray _distance(env);								// 机位为近机位1或远机位0(1*M)
//        IloIntArray _tComeBegin(env);							// 航班进港时进入滑道时间(1*N)
//        IloIntArray _tComeEnd(env);								// 航班进港时离开滑道时间(1*N)
//        IloIntArray _tGoBegin(env);								// 航班出港时进入滑道时间(1*N)
//        IloIntArray _tGoEnd(env);								// 航班出港时离开滑道时间(1*N)
//        IloArray<IloIntArray> _gatePositionToInRoad(env);			// 机位-滑入滑道对应(M*R)
//        IloArray<IloIntArray> _gatePositionToOutRoad(env);			// 机位-推出滑道对应(M*R)
//        IloArray<IloIntArray> _conflictFlightInIn(env);			// 滑道时间上冲突的航班(N*N)，不考虑安排的滑道及机位，滑入滑道冲突
//        IloArray<IloIntArray> _conflictFlightOutOut(env);			// 滑道时间上冲突的航班(N*N)，不考虑安排的滑道及机位，推出滑道冲突
//        IloArray<IloIntArray> _conflictFlightInOut(env);			// 滑道时间上冲突的航班(N*N)，不考虑安排的滑道及机位，滑入与推出冲突
//        IloArray<IloIntArray> _conflictFlightOutIn(env);			// 滑道时间上冲突的航班(N*N)，不考虑安排的滑道及机位，推出与滑入冲突
//        IloIntArray _noLimit(env);								// 滑道是否为无限制(1*R)
//        IloIntArray _numberOfFlight(env);						// 每架航班的旅客数量(1*N)
//        IloIntArray _temporaryMeasures(env);						// 机位是否为临时措施，是临时措施为1，不是为0(1*M)
//        IloArray<IloIntArray> _conflictGatePosition(env);			// 不能同时使用的机位(M*M)，若不能同时使用则为1
//        IloArray<IloIntArray> _influenceGatePositionIn(env);		// 所影响滑入的机位(M*M)，若影响则为1
//        IloArray<IloIntArray> _influenceGatePositionOut(env);		// 所影响滑出的机位(M*M)，若影响则为1
//        
//        vector<pair<int, int>> arrangedFlights = vector<pair<int, int>>(); // 已经安排好的航班
//        
//        
//        // 第一个是读文件函数名，后面是赋值给常量
//        f >> N >> M >> R >> allNumber >> _noLimit;
//        flightTime >> _tin >> _tout;
//        feasibleFlightFile >> _feasibleFlight;
//        distanceFile >> _distance;
//        flightRoadTime >> _tComeBegin >> _tComeEnd >> _tGoBegin >> _tGoEnd;
//        gatePositionToRoadFile >> _gatePositionToInRoad >> _gatePositionToOutRoad;
//        conflictFlightFile >> _conflictFlightInIn >> _conflictFlightOutOut >> _conflictFlightInOut >> _conflictFlightOutIn;
//        numberOfFlightFile >> _numberOfFlight;
//        temporaryMeasuresFile >> _temporaryMeasures;
//        conflictGatePositionFile >> _conflictGatePosition;
//        influenceGatePositionFile >> _influenceGatePositionIn >> _influenceGatePositionOut;
//        
////        int position[M]; // 机位的最后一个航班号
////        for (j = 0; j < M; j++)
////        {
////            position[j] = -1;
////        }
//        map<int, vector<int>> positionFlightMap = map<int, vector<int>>(); // 机位里面已经安排的航班情况
//        for (j = 0; j < M; j++) {
//            vector<int> flights = vector<int>();
//            positionFlightMap.insert(make_pair(j, flights));
//        }
//        
//        // 定义决策变量输出
//        // X[i][j]:航班i占用停机位j
//        IloArray<IloBoolArray> X(env, N);
//        for (i = 0; i < N; i++)
//        {
//            X[i] = IloBoolArray(env, M);
//            for (j = 0; j < M; j++)
//            {
//                X[i][j] = 0;
//            }
//        }
//        // YIN[i][k]:航班i占用滑入滑道k
//        IloArray<IloBoolArray> YIN(env, N);
//        for (i = 0; i < N; i++)
//        {
//            YIN[i] = IloBoolArray(env, R);
//            for (k = 0; k < R; k++)
//            {
//                YIN[i][k] = 0;
//            }
//        }
//        // YOUT[i][k]:航班i占用推出滑道k
//        IloArray<IloBoolArray> YOUT(env, N);
//        for (i = 0; i < N; i++)
//        {
//            YOUT[i] = IloBoolArray(env, R);
//            for (k = 0; k < R; k++)
//            {
//                YOUT[i][k] = 0;
//            }
//        }
//        
//        // 贪心算法获取初始解
//        for (i = 0; i < N; i++)
//        {
//            cout << "安排航班：" << i << endl;
//            int value = -10;
//            int bestPosition = -1;
//            
//            for (j = 0; j < M; j++) {
//                int conflict = 0;
//                cout << "检测机位：" << j << endl;
//                // 先判断机位是否符合安排条件
//                if (_feasibleFlight[i][j] == 1){
//                    vector<int> flights = positionFlightMap[j];
//                    cout << "flights size: " << flights.size() << endl;
////                    if (flights.size() > 0 && (_tin[i] - _tout[flights[flights.size()-1]]) * (_tin[flights[flights.size()-1]] - _tout[i]) > 0) {
////                        conflict = 1;
////                    }
//                    for (int i2 = 0; i2 < flights.size(); i2++) {
//                        cout << "i2: " << i2 << endl;
//                        cout << "flights[i2]: " << flights[i2] << endl;
//                        if ((_tin[i] - _tout[flights[i2]]) * (_tin[flights[i2]] - _tout[i]) > 0)
//                        {
//                            conflict = 1;
//                            break;
//                        }
//                    }
//                    // 此机位下航班冲突，不能停放
//                    if (conflict == 1) {
//                        continue;
//                    }
//                    
//                    // 判断是否会和冲突机位冲突
//                    for (int j2 = 0; j2 < M; j2++) {
//                        if (_conflictGatePosition[j][j2] == 1 || _conflictGatePosition[j2][j]) {
//                            vector<int> flights = positionFlightMap[j2];
//                            for (int i2 = 0; i2 < flights.size(); i2++) {
//                                cout << "i2: " << i2 << endl;
//                                cout << "flights[i2]: " << flights[i2] << endl;
//                                if ((_tin[i] - _tout[flights[i2]]) * (_tin[flights[i2]] - _tout[i]) > 0)
//                                {
//                                    conflict = 1;
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                    // 此机位下航班冲突，不能停放
//                    if (conflict == 1) {
//                        continue;
//                    }
//                    
//                    // 判断是否会和影响滑入机位冲突
//                    for (int j2 = 0; j2 < M; j2++) {
//                        if (_influenceGatePositionIn[j][j2] == 1 || _influenceGatePositionIn[j2][j] == 1) {
//                            vector<int> flights = positionFlightMap[j2];
//                            for (int i2 = 0; i2 < flights.size(); i2++) {
//                                cout << "i2: " << i2 << endl;
//                                cout << "flights[i2]: " << flights[i2] << endl;
//                                if ((_tin[i] - _tout[flights[i2]]) * (_tin[flights[i2]] - _tout[i]) > 0)
//                                {
//                                    conflict = 1;
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                    // 此机位下航班冲突，不能停放
//                    if (conflict == 1) {
//                        continue;
//                    }
//                    
//                    // 判断是否会和影响滑出机位冲突
//                    for (int j2 = 0; j2 < M; j2++) {
//                        if (_influenceGatePositionOut[j][j2] == 1 || _influenceGatePositionOut[j2][j]) {
//                            vector<int> flights = positionFlightMap[j2];
//                            for (int i2 = 0; i2 < flights.size(); i2++) {
//                                cout << "i2: " << i2 << endl;
//                                cout << "flights[i2]: " << flights[i2] << endl;
//                                if ((_tin[i] - _tout[flights[i2]]) * (_tin[flights[i2]] - _tout[i]) > 0)
//                                {
//                                    conflict = 1;
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                    // 此机位下航班冲突，不能停放
//                    if (conflict == 1) {
//                        continue;
//                    }
//                    
//                    // 计算如果安排进此机位是否会有滑道冲突
//                    int roadConflict = 0;
//                    for (int k = 0; k < arrangedFlights.size(); k++) {
//                        for (int r = 0; r < R; r++) {
//                            if (_gatePositionToInRoad[arrangedFlights[k].second][r] == 1 && _gatePositionToInRoad[j][r] == 1 &&
//                                ((_tin[i] - _tout[arrangedFlights[k].first]) * (_tin[arrangedFlights[k].first] - _tout[i]) > 0))
//                            {
//                                roadConflict = 1;
//                                break;
//                            }
//                        }
//                        if (roadConflict == 1) {
//                            break;
//                        }
//                    }
//                    // 计算若安排进此机位所获取的价值
//                    int valueJ = 3 * _distance[j]/(double)N + 3 * X[i][j] * _numberOfFlight[i]/(double)(IloSum(_numberOfFlight)) - _temporaryMeasures[j]/(double)N - roadConflict/(double)N;
//                    if (valueJ > value) {
//                        bestPosition = j;
//                        value = valueJ;
//                    }
//                }
//            }
//            if (bestPosition > -1) {
//                X[i][bestPosition] = 1;
//                arrangedFlights.push_back(make_pair(i, bestPosition));
//                positionFlightMap[bestPosition].push_back(i);
////                position[bestPosition] = i;
//            }
//        }
//        
//        for (i = 0; i < N; i++)
//        {
//            vector<int> resultTemp;
//            for (j = 0; j < M; j++)
//            {
//                resultTemp.push_back(X[i][j]);
//            }
//            // 赋值到BestSolution的m_solution变量里面，用于之后的后处理
//            BestSolution::m_solution.push_back(resultTemp);
//        }
//        cout << endl;
//    }
//    
//    catch (IloException& ex) {
//        cerr << "Error: " << ex << endl;
//    }
//    catch (...) {
//        cerr << "Error" << endl;
//    }
//    env.end();
//}
