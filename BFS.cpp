//Membuat fungsi untuk membangun binary search tree (BST)
#define ll long long
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

//inialisasi variabel
int vis[20]={0};
vector<int>node[20]; //untuk menunjukkan urutan data dan untuk meletakkan size dari graph

void bfs(queue<int>x);

int main()
{
	//proses input jumlah data binary search tree
	int insert;
	cout<<"Masukkan Jumlah Data : "; cin>>insert;
	cout<<endl;
	
	//proses input nilai data elemen binary seacrh tree
	while(insert--)
	{
		int a,b;
		//masukkan data dengan cara a b untuk menyambungkan arah proses binary tree kemudian saat berlanjut ke insert data selanjutnya masukkan nilai data b sebelumnya
		cout<<"Masukkan Nilai Data (a b) : "; cin>>a>>b;
		//adjensi a>>b untuk menyambungkan data a pada b
		node[a].push_back(b);
	}
	
	/*  Proses data binary search tree dengan operasi bfs atau breadth first search.
	proses operasi dilakukan dengan menggunakan queue untuk menyimpan data binary tree 
	yang kemudian dilakukan proses operasi hingga data dalam queue habis */
	
	//deklarasi queue untuk memunculkan int x dalam operasi 
	queue<int> x;
	
	for(int i=0;i<5;i++)
	{
		//proses pengecekan semua nodes untuk dapat diproses ke queue sehingga proses bfs dapat dilakukan
		if (!vis[i])
		{
			x.push(i);
			vis[i]=1;
			bfs(x);
		}
	}
}

//proses operasi bfs dengan melakukan deklarasi untuk memunculkan x
void bfs(queue<int>x)
{
	cout<<"Output : ";
	//proses operasi dengan memunculkan satu per satu tiap nilai data yang diproses dari dalam queue
	while(x.size())
	{
		int z=x.front();
		x.pop();
		cout<<z<<" "; 
		for (int i=0;i<node[z].size();i++)
		{
			if (!vis[node[z][i]])
			{
				x.push(node[z][i]);
				vis[node[z][i]]=1;
			}
		}
	}
}
