#include <iostream>
#include <vector>

using namespace std;

int n;
const int maxn = 10000;///10 000
int m;
int ans;

///Graph
struct neighbourStruct
{
        int v;
        bool h = 0;
};
vector <neighbourStruct> v[maxn];

///DFS
bool used[maxn];
int l;
struct object
{
        int p = 0;
        int h = 0;
};
object o[maxn];
bool h[maxn];

///Functions
void input();
void runDFS();
void DFS(int x);

int main()
{
        input();
        runDFS();
        cout << ans << endl;
        return 0;
}

///Input
void input()
{
        cin >> n >> m;
        for(int i = 0;i < m; ++i)
        {
                int from, to;
                char c;
                cin >> from >> c >> to;
                --from;
                --to;
                neighbourStruct t;
                if(c == 'h')
                        t.h = 1;
                t.v = to;
                v[from].push_back(t);
                t.v = from;
                v[to].push_back(t);
                //cout << from << " " << t.h << " " << to << " " << endl;
        }
        /*for(int i = 0;i < n; ++i)
        {
                for(int j = 0;j < v[i].size(); ++j)
                        cout << i + 1 << " " << v[i][j].h << " " << v[i][j].v + 1 << endl;
        }*/
}

///runDFS
void runDFS()
{
        for(int i = 0;i < n; ++i)
        {
                ///Create new object
                if(!used[i])
                {
                        ++o[l].p;
                        ++o[l].h;
                        h[i] = 1;
                        //used[i] = 1;
                        DFS(i);
                        if(o[l].h < o[l].p - o[l].h)
                                o[l].h = o[l].p - o[l].h;
                        ans += o[l].h;
                }
                ++l;
        }
}

///DFS
void DFS(int x)
{
        //cout << x << endl;
        used[x] = 1;
        for(int i = 0;i < v[x].size(); ++i)
        {
                if(!used[ v[x][i].v ])
                {
                        //used[ v[x][i].v ] = 1;
                        ++o[l].p;
                        if(h[x])
                                h[ v[x][i].v ] = v[x][i].h;
                        else
                                h[ v[x][i].v ] = !v[x][i].h;
                        if(h[ v[x][i].v ])
                                        ++o[l].h;
                        DFS( v[x][i].v );
                }
        }
}
