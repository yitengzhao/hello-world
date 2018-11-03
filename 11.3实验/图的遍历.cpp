#include<iostream>
#include<queue>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

//图的邻接矩阵存储表示
typedef struct
{
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;

//邻接矩阵创建无向图
int LocateUG(AMGraph G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}
int CreateUG(AMGraph &G)
{
	cout << "邻接矩阵创建无向图" << endl;
	cout << "输入总定点数和总边数" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "请依次输入点的信息：" << endl;
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	for (int k = 0; k < G.arcnum; k++)
	{
		char v1, v2;
		cin >> v1 >> v2;
		int i = LocateUG(G, v1);
		int j = LocateUG(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return 1;
}

//无向图DFS
bool visited_AMUG_DFS[MVNum];
void DFS_AMUG(AMGraph G, int v)
{
	cout << v;
	visited_AMUG_DFS[v] = true;
	for (int w = 0; w < G.vexnum; w++)
	{
		if ((G.arcs[v][w] != 0) && (!visited_AMUG_DFS[w]))
			DFS_AMUG(G, w);
	}
}

//无向图BFS
bool visited_AMUG_BFS[MVNum];
int First_AMGU(AMGraph G,int u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.arcs[u][i] != 0&&visited_AMUG_BFS[i]==false)
		{
			return i;
		}
	}
	return -1;
}
int Next_AMGU(AMGraph G, int u, int w) {
	//返回v相对于w的下一个邻接点
	int i;
	for (i = w; i < G.vexnum; ++i) {
		if (G.arcs[u][i] == 1 && visited_AMUG_BFS[i] == false)
			return i;
	}
	return -1;
}//NextAdjVex
void BFS_AMUG(AMGraph G,int v)
{
	queue<int> q;
	cout << v;
	visited_AMUG_BFS[v] = true;
	q.push(v);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int w = First_AMGU(G, u); w >= 0; w = Next_AMGU(G, u, w))
		{
			if (!visited_AMUG_BFS[w])
			{
				cout << w;
				visited_AMUG_BFS[w] = true;
				q.push(w);
			}
		}
	}
}


//有向图临界矩阵
int CreateG(AMGraph &G)
{
	cout << "邻接矩阵创建有向图" << endl;
	cout << "输入总定点数和总边数" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "请依次输入点的信息：" << endl;
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	for (int k = 0; k < G.arcnum; k++)
	{
		char v1, v2;
		cin >> v1 >> v2;
		int i = LocateUG(G, v1);
		int j = LocateUG(G, v2);
		G.arcs[i][j] = 1;
	}
	return 1;
}

//有向图DFS
bool visited_AMG_DFS[MVNum];
void DFS_AMG(AMGraph G, int v)
{
	cout << v;
	visited_AMG_DFS[v] = true;
	for (int w = 0; w < G.vexnum; w++)
	{
		if ((G.arcs[v][w] != 0) && (!visited_AMG_DFS[w]))
			DFS_AMG(G, w);
	}
}
//有向图BFS
bool visited_AMG_BFS[MVNum];
int First_AMG(AMGraph G, int u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.arcs[u][i] != 0 && visited_AMG_BFS[i] == false)
		{
			return i;
		}
	}
	return -1;
}
int Next_AMG(AMGraph G, int u, int w) {
	//返回v相对于w的下一个邻接点
	int i;
	for (i = w; i < G.vexnum; ++i) {
		if (G.arcs[u][i] == 1 && visited_AMG_BFS[i] == false)
			return i;
	}
	return -1;
}//NextAdjVex
void BFS_AMG(AMGraph G, int v)
{
	queue<int> q;
	cout << v;
	visited_AMG_BFS[v] = true;
	q.push(v);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int w = First_AMG(G, u); w >= 0; w = Next_AMG(G, u, w))
		{
			if (!visited_AMG_BFS[w])
			{
				cout << w;
				visited_AMG_BFS[w] = true;
				q.push(w);
			}
		}
	}
}

//邻接表无向图
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode
{
	VerTexType data;
	ArcNode *firstarc;
}VNode, AdjList[MVNum];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

int LocateUDG(ALGraph G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (v == G.vertices[i].data)
			return i;
	}
	return -1;
}
//创建无向图
int CreateUDG(ALGraph &G)
{
	cout << "请输入总顶点数和总边数：" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "依次输入顶点值：" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; k++)
	{
		char v1, v2;
		cin >> v1 >> v2;
		int i = LocateUDG(G, v1);
		int j = LocateUDG(G, v2);
		ArcNode *p1=new ArcNode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
		ArcNode *p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return 1;
}

bool visited_DFS_AL[MVNum];
void DFS_AL(ALGraph G, int v)
{
	cout << v;
	visited_DFS_AL[v] = true;
	ArcNode *p = new ArcNode;
	p = G.vertices[v].firstarc;
	while (p != NULL)
	{
		char w = p->adjvex;
		if (!visited_DFS_AL[w])
			DFS_AL(G, w);
		p = p->nextarc;
	}
}

bool visited_BFS_AL[MVNum];

void BFS_AL(ALGraph G, int v)
{
	cout << v;
	visited_BFS_AL[v] = true;
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		ArcNode *p = new ArcNode;
		p = G.vertices[u].firstarc;
		while (p != NULL)
		{
			if (!visited_BFS_AL[p->adjvex])
			{
				cout << p->adjvex;
				visited_BFS_AL[p->adjvex] = true;
				q.push(p->adjvex);
			}
			p = p->nextarc;
		}
	}
}

//有向图
int LocateDG(ALGraph G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (v == G.vertices[i].data)
			return i;
	}
	return -1;
}
//创建有向图
int CreateDG(ALGraph &G)
{
	cout << "请输入总顶点数和总边数：" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "依次输入顶点值：" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{

		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; k++)
	{
		char v1, v2;
		cin >> v1 >> v2;
		int i = LocateDG(G, v1);
		int j = LocateDG(G, v2);
		ArcNode *p1 = new ArcNode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
	}
	return 1;
}

//最小生成树
struct {
	VerTexType Head;						
	VerTexType Tail;						
	ArcType lowcost;						
}Edge[(MVNum * (MVNum - 1)) / 2];
int Vexset[MVNum];
int LocateVex(AMGraph G, VerTexType v) {
	//确定点v在G中的位置
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vexs[i] == v)
			return i;
	return -1;
}
void CreateUDN(AMGraph &G) {
	//采用邻接矩阵表示法，创建无向网G 
	int i, j, k;
	cout << "请输入总顶点数，总边数，以空格隔开:";
	cin >> G.vexnum >> G.arcnum;						
	cout << endl;

	cout << "输入点的名称，如a" << endl;

	for (i = 0; i < G.vexnum; ++i) {
		cout << "请输入第" << (i + 1) << "个点的名称:";
		cin >> G.vexs[i];                        		
	}
	cout << endl;
	for (i = 0; i < G.vexnum; ++i)                		
		for (j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	cout << "输入边依附的顶点及权值，如a b 6" << endl;
	for (k = 0; k < G.arcnum; ++k) {						
		VerTexType v1, v2;
		ArcType w;
		cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
		cin >> v1 >> v2 >> w;                           
		i = LocateVex(G, v1);  j = LocateVex(G, v2);	
		G.arcs[i][j] = w;								
		G.arcs[j][i] = G.arcs[i][j];					
		Edge[k].lowcost = w;
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
	}
}

void Sort(AMGraph G) {
	int m = G.arcnum - 2;
	int flag = 1;
	while ((m > 0) && flag == 1) {
		flag = 0;
		for (int j = 0; j <= m; j++) {
			if (Edge[j].lowcost > Edge[j + 1].lowcost) {
				flag = 1;

				VerTexType temp_Head = Edge[j].Head;
				Edge[j].Head = Edge[j + 1].Head;
				Edge[j + 1].Head = temp_Head;


				VerTexType temp_Tail = Edge[j].Tail;
				Edge[j].Tail = Edge[j + 1].Tail;
				Edge[j + 1].Tail = temp_Tail;

				ArcType temp_lowcost = Edge[j].lowcost;
				Edge[j].lowcost = Edge[j + 1].lowcost;
				Edge[j + 1].lowcost = temp_lowcost;
			}
		}
		--m;
	}
}

void MiniSpanTree_Kruskal(AMGraph G) {
	
	int i, j, v1, v2, vs1, vs2;
	Sort(G);                 							
	for (i = 0; i < G.vexnum; ++i)     					
		Vexset[i] = i;
	for (i = 0; i < G.arcnum; ++i) {
     
		v1 = LocateVex(G, Edge[i].Head);     			
		v2 = LocateVex(G, Edge[i].Tail);     			
		vs1 = Vexset[v1];       						
		vs2 = Vexset[v2];       						
		if (vs1 != vs2) {         						
			cout << Edge[i].Head << "-->" << Edge[i].Tail << endl;		
			for (j = 0; j < G.vexnum; ++j)      			
				if (Vexset[j] == vs2) Vexset[j] = vs1;	
		}
	}
}
//输入数据
/*//无向图输入
5 6
a b c d e
a b a d b c b e c d c e


//有向图输入
4 5
a b c d
a b a c c d d a b a

//最小生成树
6 10
a b c d e f
a b 6
a c 1
a d 5
b c 5
c d 5
b e 3
c e 6
c f 4
d f 2
e f 6
*/
int main()
{
	
	AMGraph G;
	ALGraph G2;
	cout << "1、无向图邻接矩阵\n2、有向图临界矩阵\n3、无向图邻接表\n4、有向图邻接表\n5、Kruskal最小生成数算法" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		//无向图邻接矩阵

		CreateUG(G);
		cout << "DFS遍历无向图(从第一个顶点开始遍历)：" << endl;
		DFS_AMUG(G, 0);
		cout << endl;
		cout << "BFS遍历无向图(从第一个顶点开始遍历)：" << endl;
		BFS_AMUG(G, 0);
		cout << endl;
		break;
	case 2:
		//有向图临界矩阵
		CreateG(G);
		cout << "DFS遍历有向图(从第一个顶点开始遍历)：" << endl;
		DFS_AMG(G, 0);
		cout << endl;
		cout << "BFS遍历有向图(从第一个顶点开始遍历):" << endl;
		BFS_AMG(G, 2);
		cout << endl;
		break;
	case 3:
		
		CreateUDG(G2);
		cout << "DFS遍历无向图(从第一个顶点开始遍历)：" << endl;
		DFS_AL(G2, 0);
		cout << endl;
		cout << "BFS遍历无向图(从第一个顶点开始遍历)：" << endl;
		BFS_AL(G2, 0);
		break;
	case 4:
		CreateDG(G2);
		cout << "DFS遍历有向图(从第一个顶点开始遍历)：" << endl;
		DFS_AL(G2, 0);
		cout << endl;
		cout << "BFS遍历有向图(从第一个顶点开始遍历)：" << endl;
		BFS_AL(G2, 0);
		break;
	case 5:
		CreateUDN(G);
		cout << endl;
		cout << "无向网G创建完成！" << endl;
		cout << endl;
		MiniSpanTree_Kruskal(G);
		break;
	}
	



	return 0;
}