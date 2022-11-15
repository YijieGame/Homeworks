#defineINFINITY 65535
typedefint status;
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "string.h"
#define maxlen 10
typedefstruct
{
 char vexs[maxlen][maxlen];/*顶点信息集合,我们用它来存入顶点名字*/
 int vexnum,arcnum;/*顶点数和边数*/
 int arcs[maxlen][maxlen];/*邻接矩阵*/
}graph;
//定位输入节点的名称
intLocateVex(graph G,char u[maxlen]
{
int i;
for(i=0;i<G.vexnum;++i)
       if(strcmp(u,G.vexs[i])==0)
              return i;
       return -1;
}
voidprim(graph &g)/*最小生成树*/
{
  int i,j,k,min,w,flag;
  int lowcost[maxlen];/*权值*/
  int closet[maxlen];/*最小生成树结点*/
  char va[maxlen],vb[maxlen];
  //初始化邻接矩阵
  //printf("请输入顶点数和边数：\n");
 //scanf("%d%d",&g.vexnum,&g.arcnum);
  g.vexnum=6;
  g.arcnum=10;
  printf("请输入顶点信息(我们这里指名字)：\n");
  for(int j=0;j<g.vexnum;j++)
       scanf("%s",g.vexs[j]);
  for(i=0;i<g.vexnum;++i)
       for(j=0;j<g.vexnum;++j)//初始化邻接矩阵
       {
       g.arcs[i][j]=INFINITY;  //任意两个顶点间距离为无穷大。
       }//for
         /*
printf("请输入%d条弧的弧尾 弧头 权值（以空格为间隔)\n",g.arcnum);
       for(k=0;k<g.arcnum;++k)
       {
      scanf("%s%s%d%*c",va,vb,&w);//用%*c吃掉回车符
       i=LocateVex(g,va);  //注意，这里定义的是char va[5]，也就是说va是首地址
       j=LocateVex(g,vb);
       g.arcs[i][j]=w; //无向网
         g.arcs[j][i]=w; //无向网
       }//for
              */     
         g.arcs[0][1]=6;
         g.arcs[1][0]=6;
         g.arcs[0][2]=1;
         g.arcs[2][0]=1;
         g.arcs[0][3]=5;
         g.arcs[3][0]=5;
         g.arcs[1][2]=5;
         g.arcs[2][1]=5;
         g.arcs[1][4]=3;
         g.arcs[4][1]=3;
         g.arcs[2][3]=5;
         g.arcs[3][2]=5;
         g.arcs[2][4]=6;
         g.arcs[4][2]=6;
         g.arcs[2][5]=4;
         g.arcs[5][2]=4;
         g.arcs[3][5]=2;
          g.arcs[5][3]=2;
         g.arcs[4][5]=6;
         g.arcs[5][4]=6;
  printf("最小生成树的边为:\n");
  for(i=1;i<g.vexnum;i++)
   {
     lowcost[i]=g.arcs[0][i];
     closet[i]=1;
    }
  closet[0]=0; //初始v1是属于集合U的，即设它是最小生成树中节点的一员
  j=1;        //V是顶点集合
  for(i=1;i<g.vexnum;i++)
   {
     min=lowcost[j];
     k=i;
     for(j=1;j<g.vexnum;j++)
      if(lowcost[j]<min&&closet[j]!=0)
         {
           min=lowcost[j];
            k=j;   //记录当前要加入集合U的节点号
          }//if 
        if(i==1) flag=0; 
        else flag=closet[k]; //还没有加入集合U的节点的closet[]值是
                              //记录了上一次加入集合U的节点号
        closet[k]=0;         //将刚刚找到的点加入到集合U中
     printf("(%s,%s),",g.vexs[k],g.vexs[flag]);//输出刚刚找到的最小生成树树枝
      for(j=1;j<g.vexnum;j++)
       if(g.arcs[k][j]<lowcost[j]&&closet[j]!=0)
           {
              lowcost[j]=g.arcs[k][j];         //更新lowcost[]的值，且在还没有加入U集合的
                                                        //的closet[]中记录刚刚加入U集合的节点号以备
                                                        //下一循环中输出用
              closet[j]=k;
          }
     }
}

int main()
{
graphg;
prim(g);

return 0;
}