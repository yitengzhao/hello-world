#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

typedef struct
{
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;
typedef char **HuffmanCode;

//存放字符
int a[120] = { 0 };

//从本地文件中读入信息
void ReadChars(string &data)
{
	ifstream infile;
	infile.open("SourceFile.txt");
	if (!infile)
		cout << "文件打开失败！" << endl;
	else
		cout << "文件打开成功！" << endl;
	infile >> data;
	cout << "读入文件成功！" << endl;
	infile.close();
}


void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
	int min_1, min_2;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0)
		{
			min_1 = i;
			break;
		}
	}
	for (int j = 1; j <= n; j++)
	{
		if (HT[j].parent == 0 && HT[min_1].weight > HT[j].weight)
			min_1 = j;
	}
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0 && i != min_1)
		{
			min_2 = i;
			break;
		}
	}
	for (int j = 1; j <= n; j++)
	{
		if (HT[j].parent == 0 && j != min_1)
		{
			if (HT[j].weight < HT[min_2].weight)
				min_2 = j;
		}
	}
	s1 = min_1;
	s2 = min_2;
}

//创建一个哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT, int n,int s[])
{
	int m, s1, s2;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		HT[i].weight = s[i - 1];
	}

	for (int i = n + 1; i <= m; i++)
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//进行哈夫曼编码
void CreatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
	char *cd;
	HC = new char*[n + 1];
	cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++)
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0)
		{
			start--;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}

int main()
{
	HuffmanTree HT;
	HuffmanCode HC;

	string data;		//存放字符数
	ReadChars(data);
	int n = data.length();
	int n2=0;
	for (int i = 0; i < n; i++)
	{
		int tem = (int)data[i];
		a[tem]++;
	}

	int s[26];			//存放字母出现概率
	char char_[26];		//存放字母
	int k = 0;
	int k2 = 0;
	for (int i = 65; i <= 90; i++)
	{
		if (a[i] != 0)
		{
			s[k++] = int(a[i] * 100 / n);
			char_[k2++] = char(i);
		}
		else
		{
			s[k++] = 0;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (s[i] != 0)
			n2++;
	}
	CreateHuffmanTree(HT, n2,s);
	CreatHuffmanCode(HT, HC, n2);

	ofstream outfile;
	outfile.open("Code.txt");

	for (int i = 1; i <= n2; i++)
	{
		outfile << char_[i - 1] << " ";
		outfile << HC[i] << endl;
	}
	cout << "编码写入成功！" << endl;
	outfile.close();
	return 0;
}
