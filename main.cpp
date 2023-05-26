#include "graph.h"
#include "label.h"
#include "head.h"
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

int main()
{
    for(int i = testStart; i <= testEnd; ++i){

        int *queryPairs = new int[QueryNum];
        FILE *infile = fopen((strDir[0] + strFileName[i]).data(), "r");

        if (!infile)
        {
            cout << "Error: Cannot open in "  << endl;
            return 0;
        }
        readGraph(infile);
        fclose(infile);

         cout << strFileName[i] << " "; //<< " " << endl;
        // outZeroVertex();


        //INDEX
        initIndex();
        toPuSort();
        orderGraph();
      // outGraph();
        computerInterval();

      //  cout<<" vertexNum: "<<vertexNum<<" edgeNum: "<<edgeNum;
      //  cout<<" nonTreeEdgeNum: "<<nonTreeNum<<" nonTreeVertexNum "<<nonTreeVertexNum<<" zeroInAndOut "<<zeroInOutDegree<<endl;
      // outInterval();

        int sidT;
        int tidT;

        FILE *queryFile = fopen((strDir[1] + strFileName[i]).data(), "r");
        if (!queryFile)
        {
            cout << "Error: Cannot open query "  << endl;
            return 0;
        }

        int ttt = 0;
        int temp =0;
        //cout << " start read query" << endl;
        while (fscanf(queryFile, "%d", &sidT) != EOF)
        {
            temp++;
            fscanf(queryFile, "%d", &tidT);
            temp++;
            queryPairs[ttt++] = sidT;
            queryPairs[ttt++] = tidT;
        }
        fclose(queryFile);

        int allReach = 0;
        auto startTime = std::chrono::high_resolution_clock::now();

        for (int qu = 0; qu < QueryNum; )
        {
            vector<bool> visitedDFS(vertexNum, false);
            sidT = queryPairs[qu++];
            tidT = queryPairs[qu++];

            // if (isReachable(sidT, tidT))
            if (DFSReachable(sidT, tidT,visitedDFS))
            {
                allReach++;

            }
        }
       auto endTime = std::chrono::high_resolution_clock::now();
        // 计算时间间隔并转换为毫秒
        std::chrono::duration<double, std::milli> duration = endTime - startTime;
        double queryTime = duration.count();

        cout << " allReach " << allReach<<" " ;
        cout << " queryTime "<<queryTime <<" ms "<<endl;


        delete []queryPairs;
      // destroyIndex();
        destroyGraph();

    }
  return  0;
}


