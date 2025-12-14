#include <stdio.h>
#include "graph.h"

/*
Dengan menggunakan ADT Graf yang telah berikan, carilah common neighbors dari dua node yang diberikan. Common neighbors dari node A dan node B adalah node yang ditunjuk oleh node A dan node B. 

Format Masukan 
    Baris pertama berisi dua bilangan bulat N (1 <=N <= 100) dan M (0 <= M<= 500), 
    yaitu banyaknya node dan edge di graf M.
    baris berikutnya setiap baris berisi dua bilangan bulat u dan v, 
    yang merepresentasikan edge berarah dari node u ke node v.
    Baris terakhir berisi dua bilangan bulat Adan B(1 <= u, v, A, B <= N), yaitu dua node yang akan dicari common neighbors-nya.

Format Keluaran
    Output seluruh node yang merupakan common neighbors node A dan B dipisahkan spasi 
    dalam urutan kemunculannya pada adjacency list node A
    Jika tidak terdapat common neighbors, output '0'.


Contoh
Input	Output	
4 8
1 2
1 3
1 4
2 1     4
2 3
3 1
3 4
4 2
1 3

Penjelasan 
Graf yang terbentuk:
- node 1 menunjuk ke: 2, 3, 4
- node 2 menunjuk ke: 1, 3
- node 3 menunjuk ke: 1, 4
- node 4 menunjuk ke: 2

Node 1 dan 3 sama-sama menunjuk node 4
*/
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
/// 

///  
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Graph g;
    CreateGraph(1, &g);
    for(int i = 2; i <= n; i++){
        AdrNode temp;
        insertNode(&g, i, &temp);
    }
    for(int i = 0; i < m; i++){
        int a, b; scanf("%d %d", &a, &b);
        insertEdge(&g, a, b);
    }
    // printf("a");
    // displayadj(g);
    int a, b; scanf("%d %d", &a, &b);
    AdrAdjNode p1 = searchNode(g, a)->trail;
    int none = 1;
    int isFirst = 1;
    while(p1 != NULL){
        if(searchEdge(g, b, p1->succId) != NULL){
            if(isFirst) printf("%d", p1->succId);
            else printf(" %d", p1->succId);
            isFirst = 0;
            none = 0;
        }
        if(p1->next != NULL) p1 = p1->next;
        else p1 = NULL;
    }
    // i0;nt i = 2;
    // i/=
    if(none) printf("0");
    printf("\n");   
    return 0;
}