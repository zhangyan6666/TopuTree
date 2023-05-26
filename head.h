//
// Created by HAI YAN ZHANG on 2023/4/8.
//

#ifndef toPu_TREE_HEAD_H
#define toPu_TREE_HEAD_H
#include <string>

using namespace std;

#define fileNum 23
#define testStart 0
#define testEnd 22
#define QueryNum 2000000

static string strFileName[fileNum] = {

    //    "0.txt",

        "amaze.txt",

        "human.txt",

        "agrocyc.txt",

        "ecoo.txt",

        "vchocyc.txt",

        "kegg.txt",

        "xmark.txt",

        "mtbrv.txt",

        "nasa.txt",

        "go.txt",

        "citeseer.txt",

        "pubmed.txt",

        "yago.txt",

        "arxiv.txt",

        "uniprot22m.txt",

        "uniprot100m.txt",

        "uniprot150m.txt",

        "10cit-Patent.txt",

        "10citeseerx.txt",

        "05cit-Patent.txt",

        "05citeseerx.txt",

        "citeseerx.txt",

     //   "cit-Patents.txt",

        };

static string strDir[2] = {

        "../DAG_Datasets/",
        "../queryFile/query-50-",

};

#endif //toPu_TREE_HEAD_H
