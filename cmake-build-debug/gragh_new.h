//
// Created by HAI YAN ZHANG on 2023/5/19.
//

#ifndef TOPU_TREE_GRAGH_NEW_H
#define TOPU_TREE_GRAGH_NEW_H

#include <iostream>
#include <fstream>

using namespace std;


struct EDGE{
    int start;
    int degree;
};

class gragh{
private:
    int vertexNum;
    int edgeNum;
    EDGE *outEdge;
    EDGE *inEdge;
    int *edge;
    int *edgeR;
    int zeroInOutDegree;           //出度和入度均为0的顶点个数

public:
    void initGraph();
    void readGraph(FILE *);
    void reverse();
    void zeroVertex();
    void destroyGraph();
    void outGraph();
    int get_vetexNum();
    int get_edgeNum();
};

int gragh::get_vetexNum() {
    return vertexNum;
}

int gragh::get_edgeNum() {
    return edgeNum;
}

void gragh::initGraph()
{
    outEdge = new EDGE[vertexNum];
    inEdge = new EDGE[vertexNum];
    inDegree = new int[vertexNum];
    edge = new int[edgeNum];
    edgeR = new int[edgeNum];
    zeroInDegree = new int[vertexNum ];
    zeroOutDegree = new int[vertexNum ];

}

void gragh::readGraph(FILE *inFile)
{
    fscanf(inFile, "%d", &vertexNum);
    fscanf(inFile, "%d", &edgeNum);
    initGraph();

    for (int i = 0; i < vertexNum ; ++i)//--------在new的时候初始化，或者查看默认初始化是否0
        {
        inEdge[i].degree = 0;
        }

    int m = 0, sid, degree, tid;
    while (fscanf(inFile, "%d", &sid) != EOF)
    {
        fscanf(inFile, "%d", &degree);
        outEdge[sid].start = m;
        outEdge[sid].degree = degree;

        for (int i = 0; i < degree; ++i)
        {
            fscanf(inFile, "%d", &tid);
            inEdge[tid].degree++;
            edge[m++] = tid;
        }
    }
    //reverse();
    zeroVertex();
}

void gragh::reverse()
{
    int sum = 0, i;
    for (i = 0; i < vertexNum; ++i)
    {
        inEdge[i].start = sum;
        sum += inEdge[i].degree;
    }

    int endPOI, curEdge, e;
    for (i = 0; i < vertexNum; ++i)
    {
        e = outEdge[i].start;
        endPOI = e + outEdge[i].degree;
        for (; e < endPOI; ++e)
        {
            curEdge = edge[e];
            edgeR[inEdge[curEdge].start++] = i;
        }
    }
    sum = 0;
    for (i = 0; i < vertexNum; ++i)
    {
        inEdge[i].start = sum;
        sum += inEdge[i].degree;
    }
}

void gragh::zeroVertex()
{
    int zeroIn = 0;
    int zeroOut = 0;
    zeroInOutDegree = 0;
    for (int i = 0; i < vertexNum; ++i)
    {
        if (0 == outEdge[i].degree)
        {
            if (0 != inEdge[i].degree)
            {
                zeroOutDegree[++zeroOut] = i;
            }
            else
            {
                zeroOutDegree[++zeroOut] = i;
                zeroInDegree[++zeroIn] = i;
                zeroInOutDegree++;
            }
        }
        else if (0 == inEdge[i].degree)
        {
            zeroInDegree[++zeroIn] = i;
        }
    }
    zeroInDegree[0] = zeroIn;
    zeroOutDegree[0] = zeroOut;
}

void gragh::outZeroVertex(){
    int temp;
    for (int i = 1; i <= zeroInDegree[0]; i++) {
        temp = zeroInDegree[i];
        cout<<"indegree is zero "<<temp<<" "<<endl;
    }
}

void gragh::destroyGraph()
{
    delete []inEdge;
    delete []outEdge;
    delete []inDegree;
    delete []edge;
    delete []edgeR;
    delete []zeroInDegree;
    delete []zeroOutDegree;

}

void gragh::outGraph()
{
    int start, end;
    for (int i = 0; i < vertexNum; ++i)
    {
        start = outEdge[i].start;
        end = start + outEdge[i].degree;
        while (start < end)
        {
            cout << endl << i << "->" << edge[start++];
        }
    }

    //    cout << endl << "reverse graph" << endl;
    //    for (int i = 0; i < vertexNum; ++i)
    //    {
    //        cout << endl << i;
    //        start = inEdge[i].start;
    //        end = start + inEdge[i].degree;
    //        while (start < end)
    //        {
    //            cout << endl << i << "->" << edgeR[start++];
    //        }
    //    }
}

bool gettimeofday(timeval *pTimeval, void *pVoid);

double get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * .000001;
}


bool gettimeofday(timeval *pTimeval, void *pVoid) {
    return false;
}

#endif //TOPU_TREE_GRAGH_NEW_H
