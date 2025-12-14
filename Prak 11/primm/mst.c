#include "graph.h"
#include <limits.h>
#include <stdio.h>

#define MAX_NODES 100

/*
Silakan lengkapi file mst.c berikut menggunakan prim's algorithm. Silakan lakukan pengujian dengan menggunakan test.in dan expected output nya adalah test.out

Prim's Algorithm

Step 1: Mulai dari node pertama.
Step 2: Ulangi step 3-5 sampai seluruh node terjangkau.
Step 3: Cari seluruh simpul dari titik-titik yang sudah terjangkau.
Step 4: Cari simpul paling minimum.
Step 5: Tambahkan simpul terpilih ke MST.
Step 6: Selesai. Yeay.


Test Case


Masukan 	Keluaran
5
7
0 1 2 3 4
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
	Building MST using Prim's Algorithm (starting from first node):
----------------------------------------------------------
Edge 1: Node 0 -- Node 1 (weight: 2)
Edge 2: Node 1 -- Node 2 (weight: 3)
Edge 3: Node 1 -- Node 4 (weight: 5)
Edge 4: Node 0 -- Node 3 (weight: 6)
----------------------------------------------------------
Total MST Weight: 16
6
9
0 1 2 3 4 5
0 1 4
0 2 3
1 2 1
1 3 2
2 3 4
2 4 5
3 4 1
3 5 6
4 5 2
	Building MST using Prim's Algorithm (starting from first node):
----------------------------------------------------------
Edge 1: Node 0 -- Node 2 (weight: 3)
Edge 2: Node 2 -- Node 1 (weight: 1)
Edge 3: Node 1 -- Node 3 (weight: 2)
Edge 4: Node 3 -- Node 4 (weight: 1)
Edge 5: Node 4 -- Node 5 (weight: 2)
----------------------------------------------------------
Total MST Weight: 9



Notes:

- apabila ada edge yang memiliki bobot sama, maka pastikan node yang lebih awal yang diutamakan.
*/


/* Count number of nodes in graph */
int countNodes(Graph g) {
    int cnt = 0;
    AdrNode p = g.first;
    while (p != NULL) {
        cnt++;
        p = NEXT(p);
    }
    return cnt;
}

/* Get node ID by index (0-based)
 * return -1 if index invalid
 */
int getNodeIdByIndex(Graph g, int index) {
    if (index < 0) return -1;
    int i = 0;
    AdrNode p = g.first;
    while (p != NULL && i < index) {
        p = NEXT(p);
        i++;
    }
    if (p == NULL) return -1;
    return ID(p);
}

/* Find index (0-based) of node by ID
 * return -1 if id not found
 */
int findNodeIndex(Graph g, int nodeId) {
    int idx = 0;
    AdrNode p = g.first;
    while (p != NULL) {
        if (ID(p) == nodeId) return idx;
        p = NEXT(p);
        idx++;
    }
    return -1;
}

/* Get weight of edge from u to v; return -1 if not exist */
int getEdgeWeight(Graph g, int u, int v) {
    AdrNode node = searchNode(g, u);
    if (node == NULL) return -1;

    AdrAdjNode adj = TRAIL(node);
    while (adj != NULL) {
        if (SUCC_ID(adj) == v) return WEIGHT(adj);
        adj = NEXTSUCC(adj);
    }
    return -1;
}

/* Pick min key among unvisited vertices.
   Tie-break: smaller node ID. */
static int pickMinKeyIndex(Graph g, int key[], boolean visited[], int n) {
    int bestIdx = -1;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (key[i] == INT_MAX) continue;

        if (bestIdx == -1) {
            bestIdx = i;
        } else if (key[i] < key[bestIdx]) {
            bestIdx = i;
        } else if (key[i] == key[bestIdx]) {
            int idI = getNodeIdByIndex(g, i);
            int idB = getNodeIdByIndex(g, bestIdx);
            if (idI < idB) bestIdx = i;
        }
    }
    return bestIdx;
}

/* Prim's Algorithm - always starts from first node (index 0) */
void primMST(Graph g) {
    int n = countNodes(g);
    if (n <= 0) {
        printf("Graph is empty!\n");
        return;
    }
    if (n > MAX_NODES) {
        printf("Too many nodes (max %d)!\n", MAX_NODES);
        return;
    }

    boolean visited[MAX_NODES];
    int parent[MAX_NODES];
    int key[MAX_NODES];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
        key[i] = INT_MAX;
    }

    /* start from first node in list */
    key[0] = 0;

    int totalWeight = 0;
    int edgeNo = 0;

    printf("Building MST using Prim's Algorithm (starting from first node):\n");
    printf("----------------------------------------------------------\n");

    for (;;) {
        int uIdx = pickMinKeyIndex(g, key, visited, n);
        if (uIdx == -1) break;          

        visited[uIdx] = true;

        if (parent[uIdx] != -1) {
            int uId = getNodeIdByIndex(g, uIdx);
            int pId = getNodeIdByIndex(g, parent[uIdx]);
            int w   = key[uIdx];

            edgeNo++;
            printf("Edge %d: Node %d -- Node %d (weight: %d)\n", edgeNo, pId, uId, w);
            totalWeight += w;
        }

        int uId = getNodeIdByIndex(g, uIdx);
        AdrNode uNode = searchNode(g, uId);
        if (uNode == NULL) continue;

        AdrAdjNode adj = TRAIL(uNode);
        while (adj != NULL) {
            int vId = SUCC_ID(adj);
            int w   = WEIGHT(adj);

            int vIdx = findNodeIndex(g, vId);
            if (vIdx != -1 && !visited[vIdx]) {
                if (w < key[vIdx]) {
                    key[vIdx] = w;
                    parent[vIdx] = uIdx;
                } else if (w == key[vIdx]) {
                    int curParIdx = parent[vIdx];
                    int newParId = getNodeIdByIndex(g, uIdx);
                    int curParId = (curParIdx == -1) ? INT_MAX : getNodeIdByIndex(g, curParIdx);
                    if (newParId < curParId) parent[vIdx] = uIdx;
                }
            }

            adj = NEXTSUCC(adj);
        }
    }

    printf("----------------------------------------------------------\n");
    printf("Total MST Weight: %d\n", totalWeight);
}


int main() {
    Graph g;
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    int firstNode;
    scanf("%d", &firstNode);
    CreateGraph(firstNode, &g);

    for (int i = 1; i < n; i++) {
        int nodeId;
        scanf("%d", &nodeId);
        AdrNode temp;
        insertNode(&g, nodeId, &temp);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        insertEdge(&g, u, v, w);
        insertEdge(&g, v, u, w); // undirected
    }

    primMST(g);
    return 0;
}
