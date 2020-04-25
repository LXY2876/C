#include<stdio.h> 
#include<math.h> 
#include <stdlib.h>
int route_step[20]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
struct point{                                     //表示坐标点的结构体
  char x;
  char y;
};
struct  point route[20]={{-1,-1}};                  //用点的结构体的数组构成一条临时路径
char my_map[9][11]={                              //将原地图转90度得到本地图。x:0-9,；y:0-11
  {0,0,0,0,0,0,0,0,0,0,0},                        //0：墙
  {0,6,6,-2,-1,-3,-1,-2,6,6,0},                   //6：可走；-1、-2、-3：对方收集区
  {0,5,6,9,6,6,6,9,6,4,0},                        //5：己方出发区；9：黄色环；4：对方出发区
  {0,5,9,6,6,7,6,6,9,4,0},                        //7：己方增益环
  {0,6,6,9,6,9,6,9,6,4,0},
  {0,5,9,6,6,8,6,6,9,4,0},                        //8：对方增益环
  {0,5,6,9,6,6,6,9,6,4,0},
  {0,6,6,2,1,3,1,3,6,6,0},                        //1、2、3：己方收集区
  {0,0,0,0,0,0,0,0,0,0,0},
};

void find_1(int x,int y,int aim_x,int aim_y) ;
int weight(int x,int y,int aim_x ,int aim_y);


int main(){
int i=2,s,index,d=2;   //d用于储存方向
printf("%d",my_map[1][2]);
return 0;
} 
void find_1(int x,int y,int aim_x,int aim_y) {
int a,b,c,min; 
char s1,s2,step,i ; 
while(route_step[0]==-1){
s1=(aim_x-x)/abs(aim_x-x);  s2=(aim_y-y)/abs(aim_y-y);
if (x==aim_x) s1=0;    
else if (y==aim_y) s2=0;
if (x==aim_x){
   	a=weight(x-1,y,aim_x,aim_y);
	b=weight(x+1,y,aim_x,aim_y);
	c=weight(x,y+s2,aim_x,aim_y);
    min=a<b ? a : ( c<b ? c : b );
    if(min==1000) route_step[0]=0;
    else if(min==a && min==b ){ x=(rand()%2==1?1:-1)+x;}
	else {x=x+(min==a)*(-1)+(min==b)*1;y=y+(min==c)*s2; }	
}else if (y==aim_y){
   	a=weight(x,y-1,aim_x,aim_y);
	b=weight(x,y+1,aim_x,aim_y);
	c=weight(x+s1,y,aim_x,aim_y);
    min=a<b ? a : ( c<b ? c : b );
    if(min==1000) route_step[0]=0;
    else if(min==a && min==b ){ y=(rand()%2==1?1:-1)+y;}
	else {x=x+(min==c)*s1;y=y+(min==a)*(-1)+(min==b)*1; }	
}else{
    a=weight(x+s1,y,aim_x,aim_y);
    b=weight(x,y+s2,aim_x,aim_y);
    min=a<b?a:b;
    if(min==1000) route_step[0]=0;
    else if(min==a && min==b ){
    	if(rand()%2==0) x=x+s1;
    	else y=y+s2;
	}
	else {x=x+(min==a)*s1;y=y+(min==b)*s2; }	
}  

}
}
int weight(int x,int y,int aim_x ,int aim_y){
	char s1,s2;
	int value;
	s1=(aim_x-x)/abs(aim_x-x);  s2=(aim_y-y)/abs(aim_y-y);
	if (x==aim_x) s1=0;    
    else if (y==aim_y) s2=0;
	if (x==aim_x && my_map[x][y+s2]!=6 && my_map[x+s1][y]!=6 && my_map[x-s1][y]!=6)
	  value=1000;
	else if (y==aim_y && my_map[x+s1][y]!=6 && my_map[x][y+s2]!=6 && my_map[x][y-s2]!=6)
	   value=1000;
    else if (x!=aim_x && y!=aim_y && my_map[x+s1][y]!=6 && my_map[x][y+s2]!=6)
       value=1000; 
    else
      value=abs(aim_x-x)+abs(aim_y-y);	
    
return value;
}
