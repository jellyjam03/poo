#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

struct compar
{
	bool operator() (const pair<string, int>& a, const pair<string, int>& b)
	{
		return a.second < b.second || a.second == b.second && a.first > b.first;
	}
};

char sep[] = " .,;?!()[]{}";

string s;
map<string, int> M;
pair <string, int> aux;
priority_queue<pair<string, int>, vector<pair<string, int> >, compar> Q;

map<string, int>::iterator it;

int i, j;

int main()
{
	//cin.getline(s);
	getline(cin, s);

	for (i = 0; i < s.size(); i++)
		if ('A' <= s[i] && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';

	for (i = s.find_first_not_of(sep), j = s.find_first_of(sep); i != -1;)
	{
		if (j == -1) j = s.size();
		aux.first = s.substr(i, j - i);
		aux.second = 0;
		M.insert(aux);
		M[aux.first]++;
		i = s.find_first_not_of(sep, j + 1);
		j = s.find_first_of(sep, i + 1);
	}

	for (it = M.begin(); it != M.end(); it++)
	{
		aux.first = it->first;
		aux.second = it->second;
		Q.push(aux);
	}

	while (!Q.empty())
	{
		cout << Q.top().first << " => " << Q.top().second << '\n';
		Q.pop();
	}

	return 0;
}