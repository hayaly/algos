#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class UnionFind
{
	public:
		UnionFind(int n);
		void unite(int p, int q);
		bool connected(int p, int q);
		void print();
		
	private:
		vector<int> m_points;
};

int main()
{
	int n = 0;
	cin >> n;
	
	UnionFind uf = UnionFind(n);
	
	for (int i = 0; i < 5; i++ )
	{
		string line;
		getline(cin, line);
		
		int points[2] = {0};
		int ptIndex = 0;
		char *p = strtok(const_cast<char*>(line.c_str()), " ");
		while (p)
		{
			points[ptIndex++] = *p - '0';
			p = strtok(NULL, " ");
		}
		
		if (!uf.connected(points[0], points[1]))
		{
			uf.unite(points[0], points[1]);
			//cout << points[0] << " " << points[1] << endl;
		}
	}
	
	uf.print();
	
	return 0;
}

UnionFind::UnionFind(int n)
{
	for (int i = 0; i < n; ++i)
	{
		m_points.push_back(i);
	}
}

void UnionFind::unite(int p, int q)
{
	int pid = m_points[p];
	int qid = m_points[q];
	
	for (int i = 0; i < m_points.size(); ++i)
	{
		if (m_points[i] == qid) m_points[i] = pid;
	}
}

bool UnionFind::connected(int p, int q)
{
	if (m_points[p] == m_points[q])
	{
		return true;
	}
	
	return false;
}

void UnionFind::print()
{
	cout << endl;
	
	for (int i = 0; i < m_points.size(); ++i)
	{
		cout << m_points[i] << " ";
	}
}