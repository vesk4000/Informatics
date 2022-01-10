/*
02.03.2018, 10.10.2020
*/
#include <bits/stdc++.h>
#define MAXN 1000
#define MAXE 10000
#define endl '\n'

using namespace std;

struct Edge
{
    int to;                 /// № на втория край на реброто (първият е индексът на поредния елемент от вектора)
    int nom;                /// № на реброто
    Edge (int d, int n)
    {
        to = d;
        nom = n;
    }
};

vector<Edge> E[MAXN];       /// вектор с ребрата
stack <int> tmp;            /// помощен стек
stack <int> way;            /// стек за пътя
bool used[MAXE] = {0};      /// масив с информация кои ребра са посетени
int n;                      /// брой върхове
int m;                      /// брой ребра

void Euler (int beg);
void dfs(int beg);
void input();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    int brOdd = 0, beg = 0;
    for ( int i = 0; i < n; i++ )
    {
        if ( E[i].size() & 1 )
        {
            brOdd++;
            beg=i;
        }
    }
    cout << "brOdd = " << brOdd << endl;

    if ( brOdd && brOdd != 2 ) cout << "There's no Euler cycle!" << endl;
    else
    {
        cout << "beg = " << beg+1 << endl;

        if ( brOdd == 2 ) cout << "Euler path: ";
        else cout << "Euler Cycle: ";

        Euler(beg);
    }
    return 0;
}

void dfs(int beg)
{
    tmp.push(beg);
    for(size_t i=0; i<E[beg].size(); i++)
    {
        Edge edge = E[beg][i];
        if( !used[edge.nom] )
        {
            used[ edge.nom ] = true;
            dfs( edge.to );
            break;
        }
    }
}

void Euler (int beg)
{
    dfs(beg);                                           /// пускаме dfs от стартовия еръх

    while ( !tmp.empty() )
    {
        int topV = tmp.top();
        //  tmp.pop();   /// НЕ тук!!!

        bool found = false;
        for ( size_t i = 0; i < E[topV].size(); i++ )  /// търси непосетени ребра, свързани с поредния връх
        {
            Edge edge = E[topV][i];
            if ( !used[edge.nom] )
            {
                found = true;
                used[edge.nom] = true;
                dfs(edge.to);
                break;                                  /// работи и без този break
            }
        }
        if ( !found )
        {
            way.push(topV);
            tmp.pop();                                  /// ТРЯБВА ДА Е ТУК, А НЕ ГОРЕ!!!!
        }
    }

    while(!way.empty())                                 /// извежда Ойлеровия път
    {
        cout << way.top()+1 << " ";
        way.pop();
    }
    cout << endl;
}

void input()
{
    int b, e;
    cin >> n >> m;
    for (int nom = 0; nom < m; nom++ )
    {
        cin >> b >> e;
        E[b-1].push_back( Edge(e-1,nom) );
        E[e-1].push_back( Edge(b-1,nom) );
    }
}


/**

===========================

  5
 / \
4---3
|\ /|
| \ |
|/ \|
1---2
INPUT:  PLIK - EULER PATH
5 8
1 2
1 3
1 4
2 3
2 4
3 4
3 5
4 5

OUTPUT:
2
beg = 2
Euler path: 2 1 3 2 4 3 5 4 1
===========================

1---4
|   |
2---3
|\ /|
| \ |
|/ \|
5   6
INPUT: EULER CICLE
6 8
1 2
1 4
2 3
2 5
2 6
3 4
3 5
3 6
OUTPUT:
brOdd = 0
beg = 1
Euler Cycle: 1 2 3 5 2 6 3 4 1

Systedite
1: 2, 4
2: 1, 3, 5, 6
3: 2, 4, 5, 6
4: 1, 3
5: 3
6: 2, 3

===========================
     6
    / \
   1 - 5
  / \ / \
 /   2   \
3 --------4
INPUT: EULER CYCLE
6 7
1 2
1 3
1 5
1 6
2 5
3 4
4 5
OUTPUT:
brOdd = 2
beg = 6
Euler path: 6 1 2 5 1 3 4 5
===========================

4---3
|\ /|
| \ |
|/ \|
1---2
INPUT: Not found EULER CYCLE
4 6
1 2
1 3
1 4
2 3
2 4
3 4
OUTPUT:
4
There's no Euler cycle!

===========================

3 ----- 2
|\     /|\
| \   / | \
|   6   |  5
| /   \ | /
|/     \|/
4 ----- 1
INPUT:
6 10
3 2
3 4
3 6
2 1
2 5
2 6
1 4
1 5
3 6
4 6
OUTPUT:
brOdd = 2
beg = 4
Euler path: 4 3 2 1 4 6 3 6 2 5 1

или (от първия връх с нечетна степен)
brOdd = 2
beg = 1
Euler path: 1 2 3 4 1 5 2 6 3 6 4

*/
