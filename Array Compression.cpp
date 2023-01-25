const int N = 2e5+5;
int L[N], R[N];
void array_compression()
{
    set<int> Set;
    for(int i=1; i<=n; i++)
    {
        cin >> L[i] >> R[i];
        Set.insert(L[i]);
        Set.insert(R[i]);
        Set.insert(R[i]+1);
    }
    map<int, int> Map, key;
    int idx = 0;
    for(auto x: Set) Map[x] = ++idx;
    for(int i=1; i<=n; i++)
    {
        L[i] = Map[L[i]];
        R[i] = Map[R[i]];
    }
}
