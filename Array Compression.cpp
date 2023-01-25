void array_compression()
{
    set<int> Set;
    for(int i=1; i<=n; i++)
    {
        Set.insert(l[i]);
        Set.insert(r[i]);
        Set.insert(r[i]+1);
    }
    map<int, int> Map;
 
    for(auto u: Set) Map[u] = ++idx;
    for(int i=1; i<=n; i++)
    {
        l[i] = Map[l[i]];
        r[i] = Map[r[i]];
    }
}
