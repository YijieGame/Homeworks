void UFset() // 初始化 
{
    for (int i = 0; i < n; i ++)
        parent[i] = -1;
} 
int Find(int x)  // 查找并返回结点x所属集合的根结点 
{
    int s;    // 查找位置 
    for (s = x; parent[s]>=0; s = parent[s]);  // 注意这里的 ; 
    while (s != x)   // 优化方案 -- 压缩路径，使后续的查找 
    {
        int tmp = parent[x];
        parent[x] = s;
        x = tmp;
    }
    return s;
}
// R1和R2是两个元素，属于两个不同的集合，现在合并这两个集合
void Union (int R1, int R2)
{
    // r1位R1的根结点，r2位R2的根结点
    int r1 = Find(R1), r2 = Find(R2);
    int tmp = parent[r1] + parent[r2];   // 两个集合的结点个数之和（负数） 
    // 如果R2所在树结点个数 > R1所在树结点个数
    // 注意parent[r1]和parent[r2]都是负数
    if(parent[r1] > parent[r2])    // 优化方案 -- 加权法则 
    {
        parent[r1] = r2;        // 将根结点r1所在的树作为r2的子树（合并） 
        parent[r2] = tmp;       // 跟新根结点r2的parent[]值 
    }
    else
    {
        parent[r2] = r1;         // 将根结点r2所在的树作为r1的子树（合并） 
        parent[r1] = tmp;        // 跟新根结点r1的parent[]值 
    } 
}