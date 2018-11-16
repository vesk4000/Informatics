#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int> msMerge(vector <int> q1, vector <int> q2)
{
	vector <int> res;
	while(q1.size() != 0 || q2.size() != 0)
	{
		if(q1.size() == 0)
		{
			res.push_back(q2.front());
			q2.erase(q2.begin());
		}
		else if(q2.size() == 0)
		{
			res.push_back(q1.front());
			q1.erase(q1.begin());
		}
		else if(q2.front() < q1.front())
		{
			res.push_back(q2.front());
			q2.erase(q2.begin());
		}
		else
		{
			res.push_back(q1.front());
			q1.erase(q1.begin());
		}
	}
	return res;
}

vector <int> mergeSort(vector <vector <int> > qs)
{
	vector <vector <int> > result;
	for(int i = 0;i < qs.size(); i += 2)
	{
		vector <int> mergeResult;
		if(i != qs.size() - 1)
			mergeResult = msMerge(qs[i], qs[i + 1]);
		else
		{
			vector <int> empt;
			mergeResult = msMerge(qs[i], empt);
		}
		result.push_back(mergeResult);
	}
	if(result.size() == 1)
		return result[0];
	else
		return mergeSort(result);
}

int main()
{
	vector <int> q;
	int n;
	cin >> n;
	for(int i = 0;i < n; ++i)
	{
		int a;
		cin >> a;
		q.push_back(a);
	}
	vector <vector <int> > qi;
	vector <int> nq = q;
	while(nq.size())
	{
		vector <int> tq;
		tq.push_back(nq[0]);
		nq.erase(nq.begin());
		qi.push_back(tq);
	}

	vector <int> result;
	result = mergeSort(qi);
	for(int i = 0;i < result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
