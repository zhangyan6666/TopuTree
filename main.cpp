#include "graph.h"
#include "label.h"
#include "head.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

void testQueryTime();

int main(int argc, char *argv[])
{
    testQueryTime();
    return 0;
}

void testQueryTime()
{
    int *queryPairs = new int[QUERYNUM];

    for(int i = TESTSTART; i <= TESTEND; ++i){

       // FILE *infile = fopen("/Users/haiyanzhang/desktop/DAG_Datasets/0.txt", "r");
        FILE *infile = fopen((strDir[0] + strFileName[i]).data(), "r");

        if (!infile)
        {
            cout << "Error: Cannot open in "  << endl;
            return;
        }
        //initGraph();             //--------delete
        readGraph(infile);
        fclose(infile);

        cout << strFileName[i] << " "; //<< " " << endl;
        //zeroVertex();
        // outZeroVertex();


        //INDEX
        initIndex();
        toPuSort();
        orderGraph();
      // outGraph();
        computerInterval();

        cout<<" vertexNum: "<<vertexNum<<" edgeNum: "<<edgeNum;
        cout<<" nonTreeEdgeNum: "<<nonTreeNum<<" nonTreeVertexNum "<<nonTreeVertexNum<<" zeroInandOut "<<zeroInOutDegree<<endl;
        // outInterval();




//        int sidT, tidT, ret;
//        FILE *queryf = NULL;
//
//        queryf = fopen("/Users/haiyanzhang/desktop/DAG_Datasets/test_query.txt", "r");
//
//        if (!queryf)
//        {
//            cout << "Error: Cannot open query "  << endl;
//            return;
//        }
//
//        int ttt = 0;
//        //cout << " start read query" << endl;
//        while ((ret = fscanf(queryf, "%d", &sidT)) != EOF)
//        {
//            ret = fscanf(queryf, "%d", &tidT);
//            queryPairs[ttt++] = sidT;
//            queryPairs[ttt++] = tidT;
//        }
//        fclose(queryf);
//        double startTime, endTime;
//        int allReach = 0;
//        startTime = get_wall_time();
//        for (int qu = 0; qu < QUERYNUM; )
//        {
//            sidT = queryPairs[qu++];
//            tidT = queryPairs[qu++];
//
//            if (query(sidT, tidT))
//            {
//                allReach++;
//
//            }
//        }
//        endTime  = get_wall_time();
//
//        cout << " allReach " << allReach<<" " ;
//        cout << " queryTime "<<(endTime - startTime) * 1000<<endl;


 //       delete []queryPairs;


    }
}


