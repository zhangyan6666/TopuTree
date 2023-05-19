//
// Created by HAI YAN ZHANG on 2023/4/8.
//

#ifndef TOPU_TREE_HEAD_H
#define TOPU_TREE_HEAD_H
#include <string>

using namespace std;



#define FILENUM 23
#define TESTSTART 0
#define TESTEND 23
#define QUERYNUM 20

static string strFileName[FILENUM] = {

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

   //     "Email-EuAll.txt",

        "uniprot22m.txt",

        "uniprot100m.txt",

        "uniprot150m.txt",

     //   "WikiTalk.txt",

      //  "soc-LiveJournall.txt",

     //   "web-Google.txt",

        "10cit-Patent.txt",

        "10citeseerx.txt",

        "05cit-Patent.txt",

        "05citeseerx.txt",

        "citeseerx.txt",

      //  "dbpedia.txt",

     //   "govwild.txt",

        "cit-Patents.txt",

     //   "go_uniprot.txt",

     //   "10go-uniprot.txt",

      //  "twitter.txt",

     //   "web-uk.txt",

        };



static string queryFile[FILENUM] = {

        "0",

        "amaze",

        "human",

        "agrocyc",

        "ecoo",

        "vchocyc",

        "mtbrv",

        "kegg",

        "xmark",

        "nasa",

        "go",

        "citeseer",

        "pubmed",

        "yago",

        "arxiv",

     //   "Email-EuAll",

        "uniprot22m",

        "uniprot100m",

        "uniprot150m",

        "WikiTalk",

        "twitter",

        "soc-LiveJournall",

        "web-Google",

        "go_uniprot",

        };

static string strDir[4] = {

        "/Users/haiyanzhang/desktop/DAG_Datasets/",

        "-50-50",

        "-rand",

        "/Users/haiyanzhang/desktop/queryFile/",


};

#endif //TOPU_TREE_HEAD_H
