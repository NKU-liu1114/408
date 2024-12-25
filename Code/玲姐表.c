#define MAXNUM 10

typedef struct ArcNode{
    int nextnum;
    struct ArcNode * next;
}ArcNode;
typedef struct VexNode{
    char vex;
    ArcNode* head;
}VexNode;
typedef struct Graph{
    VexNode v[MAXNUM];
    int vexnum;
    int arcnum;
}Graph;