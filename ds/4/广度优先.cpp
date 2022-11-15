/**
 * 广度优先搜索
 * @param Vs 起点
 * @param Vd 终点
 */
bool BFS(Node& Vs, Node& Vd){
 queue<Node> Q;
 Node Vn, Vw;
 int i;
 
 //初始状态将起点放进队列Q
 Q.push(Vs);
 hash(Vw) = true;//设置节点已经访问过了！
 
 while (!Q.empty()){//队列不为空，继续搜索！
  //取出队列的头Vn
  Vn = Q.front();
 
  //从队列中移除
  Q.pop();
 
  while(Vw = Vn通过某规则能够到达的节点){
   if (Vw == Vd){//找到终点了！
    //把路径记录，这里没给出解法
    return true;//返回
   }
 
   if (isValid(Vw) && !visit[Vw]){
    //Vw是一个合法的节点并且为白色节点
    Q.push(Vw);//加入队列Q
    hash(Vw) = true;//设置节点颜色
   }
  }
 }
 return false;//无解
}