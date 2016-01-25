
#include <iostream>
#include <jni.h>
#include "SalesMan.h"

using namespace std;

#define INFINITY 9999
#define MATRIX_SIZE 10

JNIEXPORT jint JNICALL Java_SalesMan_my_1dijkestras(JNIEnv *env, jobject jobj,jobjectArray jobjarray, jint jint_numcities, jint jint_src, jint jint_dst){
    
int i;
int j;
int num_cities;
int src;
int dst;
int distances[MATRIX_SIZE][MATRIX_SIZE];

num_cities=jint_numcities;
src=jint_src;
dst=jint_dst;
    
    int arraylength = env -> GetArrayLength(jobjarray);
    jintArray dim=  (jintArray)env->GetObjectArrayElement(jobjarray, 0);
    int arraysize = env -> GetArrayLength(dim);
    int **localarray;
    localarray = new int*[arraylength];
    for(int i=0; i<arraylength;i++){
        jintArray oneDim= (jintArray)env->GetObjectArrayElement(jobjarray, i);
        jint *element=env->GetIntArrayElements(oneDim, 0);
        localarray[i] = new int[arraysize];
        for(int j=0; j<arraysize;j++) {
            localarray[i][j]= element[j];
        }
    }

    cout<<"The Distance Matrix is \n";
    for(int i=0;i<arraysize;i++){
        for(int j=0;j<arraysize;j++){
            distances[i][j]= localarray[i][j];
            cout<<"\t"<<distances[i][j];
        }
        cout<<"\n";
    }

int shortest_distance;
int distance_of_node[MATRIX_SIZE];
int visited_node[MATRIX_SIZE];
int actual_path[MATRIX_SIZE];
int vertex;
int min_dist;
int swipe_vertex;
int shortest_path[MATRIX_SIZE];
int cost;
int min_dist_flag;
cost=0;
min_dist_flag=0;

    /* Initializing the vertexes with O values with INFINITY */
for(int i=0;i<num_cities;i++){
    for(int j=0;j<num_cities;j++){
        if(distances[src][j]!=0)
        {
            distance_of_node[i]=distances[src][j];
            actual_path[j]=src;
        }
        else
        {
            distance_of_node[j]=INFINITY;
            actual_path[j]=0;
        }
    }
}
    
visited_node[src]=1;
distance_of_node[src]=0;
while(visited_node[dst]!=1)
{
    int min;
    int i;
    int min_index;
    min=INFINITY;
    for(i=0;i<num_cities;i++)
    {
        if(visited_node[i]!=1 && min>distance_of_node[i])
        {
                min=distance_of_node[i];
                min_index=i;
        }
    }
    
    min_dist=min_index;
    visited_node[min_dist]=1;
    for(i=0;i<num_cities;i++)
    {
        if(visited_node[i]!=1 && distances[i][min_dist]!=0){
           if((distance_of_node[min_dist]+ distances[i][min_dist])<distance_of_node[i])
        {
                    distance_of_node[i]=distance_of_node[min_dist]+distances[i][min_dist];
                    actual_path[i]=min_dist;
        }
    }
}

shortest_distance = distance_of_node[dst];
return shortest_distance;
}
