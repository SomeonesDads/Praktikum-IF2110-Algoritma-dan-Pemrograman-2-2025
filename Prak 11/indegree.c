#include <stdio.h>
#include "graph.h"

void displayadj(Graph G){
    printf("\n");
    AdrNode p = G.first;
    while(p != NULL){
        int v = p->id;
        AdrAdjNode p2 = p->trail;
        int n = p->nPred;
        printf("%d: ", v);
        if(p2 != NULL){
        while(p2!=NULL){
            // printf("%d\n", i);
            int u = p2->succId;
            printf("%d, ", u);
            if(p2->next != NULL) p2 = p2->next;
            else p2 = NULL;
        }};
        printf("\n");
        if(p->next != NULL) p = p->next;
        else p = NULL;
    }
}   
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    // Graph g;
    int a; scanf("%d", &a);
    // CreateGraph(a, &g);
    int dict[n][2];
    dict[0][0] = a;
    dict[0][1] = 0;
    for(int i = 1; i < n; i++){
        // AdrNode temp;
        scanf("%d", &a);
        dict[i][0] = a;
        dict[i][1] = 0;
        // insertNode(&g, a, &temp);    
    }
    for(int i = 0; i < m; i++){
        int a, b; scanf("%d %d", &a, &b);
        int index;
        for(int i = 0; i < n; i++){
            if (dict[i][0] == b) index = i;
        }
        dict[index][1]++;
    }
    for(int i = 0; i< n; i++) printf("%d %d\n",dict[i][0], dict[i][1]);
    // printf("a");
    // displayadj(g);
    return 0;
}