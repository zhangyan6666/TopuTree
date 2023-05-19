//
// Created by HAI YAN ZHANG on 2023/4/7.
//

#ifndef TOPU_TREE_LABEL_H
#define TOPU_TREE_LABEL_H
#include "graph.h"
#include <set>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

struct NodeIndex
        {
    int left;
    int right;
    int levalValue;
        };

int *topoNum;                //顶点拓扑号
int *rightInterval;          //右区间值
int *leftInterval;           //左区间值
int *visited;                //访问标志
int visitNum = 0;                //访问顺序编号
int *nonTreeVertexMark;             //标记是不是非树顶点
int nonTreeNum;                //非树边的数量
int nonTreeVertexNum ;        //非树边顶点的数量

NodeIndex *nodeLable;         //顶点标签数组
queue<int> q;                //用于拓扑排序的队列q

void initIndex();
void toPuSort();             //计算DAG拓扑序列
void orderGraph();                  //出邻居顶点按照拓扑层从小到大进行排序
void outTopologicalSort();          //输出拓扑结果

void dfsSearch(int node);
void computerInterval();
void outInterval();
void outTree();
void destoryIndex();


bool query(const int &sid, const int &tid);


void initIndex()
{
    topoNum = new int[vertexNum];
    rightInterval = new int[vertexNum];
    leftInterval = new int[vertexNum];
    nodeLable = new NodeIndex[vertexNum];
    nonTreeVertexMark = new int[vertexNum];

    visited = new int[vertexNum];

    for (int i = 0; i < vertexNum; ++i)
    {
        visited[i] = 0;
        nonTreeVertexMark[i] = 0;
        inDegree[i]=inEdge[i].degree;
        nodeLable[i].levalValue = 0;
    }
}

//计算DAG拓扑序列
void toPuSort(){
    int curNode,neighNode;       //当前节点、出邻居节点
    int start,end;
    int temp;
    // 将入度为 0 的节点入队
    for (int i = 1; i <= zeroInDegree[0]; i++) {
        temp = zeroInDegree[i];
        q.push(temp);
        nodeLable[temp].levalValue = 1;    //初始拓扑层数为1
    }

    // BFS 遍历图，将所有可达节点的入度减一
    while (!q.empty()) {
        curNode = q.front();
        q.pop();

        start = outEdge[curNode].start;
        end = outEdge[curNode].degree + start;
        while(start < end)
        {
            neighNode = edge[start++];
            if(0 == (--inDegree[neighNode])){
                q.push(neighNode);
                nodeLable[neighNode].levalValue = nodeLable[curNode].levalValue + 1;
            }

        }
    }
}

void orderGraph(){
    int start, end;
    for(int i = 0; i < vertexNum; i++){
        start = outEdge[i].start;
        end = start + outEdge[i].degree;
        sort(edge + start, edge + end , [&](int a, int b){
            return nodeLable[a].levalValue < nodeLable[b].levalValue;
        });
    }
}

void dfsSearch(int node){
    int start, end;
    int neighNode;
    visited[node] = 1;
    nodeLable[node].left = visitNum++;
    start = outEdge[node].start;
    end = start + outEdge[node].degree;
    while (start < end){
        neighNode = edge[start++];
        if(!visited[neighNode]){
            dfsSearch(neighNode);
        }
        if(nodeLable[node].left > nodeLable[neighNode].left){

            nonTreeNum++;
            if(!nonTreeVertexMark[node]){
                nonTreeVertexMark[node] = 1;
                nonTreeVertexNum++;
            }
            if(!nonTreeVertexMark[neighNode]){
                nonTreeVertexMark[neighNode] = 1;
                nonTreeVertexNum++;
            }

       //  cout<<" non tree "<<node<<" -> " <<neighNode;
        }

    }
    nodeLable[node].right = visitNum++;

}
//计算生成树区间
void computerInterval(){
    nonTreeVertexNum = 0;
    nonTreeNum = 0;
   for(int i = 1; i <= zeroInDegree[0]; i++){
       dfsSearch(zeroInDegree[i]);
   }
}
void outTopologicalSort(){
    for (int i = 0; i < vertexNum; i++)
    {

        cout << endl  << i << " tuPu level is  " << nodeLable[i].levalValue;
    }

}

void outInterval(){
    for (int i = 0; i < vertexNum; i++)
    {

        cout << endl  << i << " left value is  " << nodeLable[i].left<<"  right value is "<<nodeLable[i].right;
    }
}


bool query(const int &sVid, const int &tVid)
{

    if(sVid == tVid)
        return true;
    if(nodeLable[sVid].left < nodeLable[tVid].left &&  nodeLable[tVid].right< nodeLable[sVid].right)     //根据区间判断可达
        return true;
    if(nodeLable[sVid].left < nodeLable[tVid].left)                                          //根据区间过滤不可达
        return false;
    if(nodeLable[sVid].levalValue >= nodeLable[tVid].levalValue)                             //根据拓扑层号过滤不可达
        return false;
    return false;
}

void destoryIndex()
{
    delete[] topoNum;
    delete[] rightInterval;
    delete[] leftInterval;


    delete[] visited;
    delete[] nonTreeVertexMark;
    delete[] nodeLable;

}


#endif //TOPU_TREE_LABEL_H
