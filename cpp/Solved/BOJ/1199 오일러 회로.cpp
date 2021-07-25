#include <iostream>
#include <vector>

using namespace std;

int n;
int adj[1001][1001] = { 0 };


void getEurlarCircuit(int here, vector<int>& circuit)
{
	for (int there = 0; there < n; ++there)
		while (adj[here][there] > 0)
		{
			adj[here][there]--;
			adj[there][here]--;
			getEurlarCircuit(there, circuit);
		}
	circuit.push_back(here + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> adj[i][j];
		}
	}

	bool ok = true;
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
		{
			sum += adj[i][j];
		}
		if (sum % 2 == 1)
		{
			ok = false;
			break;
		}
	}
	vector<int> circuit;
	if (ok)
	{
		getEurlarCircuit(0, circuit);
		for (int i = 0; i < circuit.size(); i++)
		{
			cout << circuit[i] << ' ';
		}
	}
	else
	{
		cout << -1;
	}
}