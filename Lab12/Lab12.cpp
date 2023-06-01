#include <iostream>
using namespace std;



int  dijkstra (int G[6][6], int n, int startnode, int endnode){
    int cost[6][6], distance[6], pred[6];
    int visited[6], count, mindistance, nextnode, i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INT16_MAX;
            else
                cost[i][j]=G[i][j];
    for(i=0;i<n;i++){
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1){
        mindistance=INT16_MAX;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i]){
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }
    for(i=0;i<n;i++)
        if(i==endnode){
            cout<<"\nDistance of node "<<i<<" ="<<distance[i];
            cout<<"\nPath="<<i;
            j=i;
            do{
                j=pred[j];
                cout<<"<-"<<j;
            }while(j!=startnode);
    }
    cout<<endl;
    return distance[endnode];
};


void getAverageDistances( int costs[6],int G[6][6]){
    for (int i=0; i< 6;i++){
        int sum=0;
        cout<< "finding distances from " << i<< " vertex"<<endl;
        for ( int j=0; j<6;j++){
            sum+=dijkstra(G, 6,i,j);
        }
        costs[i]=sum/5;
    };

    for ( int i=0; i< 6; i++){
        cout<<" i= "<< i<<" , average " << costs[i]<<endl;
    }


}
int  main(){
  
    int G[6][6] ={
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };
    dijkstra(G, 6,0,2);
    int costs[6]={0,0,0,0,0};
    getAverageDistances(costs,G);
    return 0;

    
};