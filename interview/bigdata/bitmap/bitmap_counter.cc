/*
* Judage if there are duplicates in 2.5 billion numbers or more
*/

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

char *g_bitmap=NULL;   //位图空间
int g_size=0;         //位图大小

bool bitmap_init(int size); //初始化位图
bool bitmap_set(int index);  //设置数字index在位图中的位置
bool bitmap_get(int index);  //判断数字index在位图中是否出现
void bitmap_free();

int main(int argv,char **argc)
{
 bitmap_init(8);
 bitmap_set(2);
 bitmap_set(6);
 bitmap_set(2);

 for(int j=0;j<100;j++)
  bitmap_set(j);

 for(int i=0;i<100;i++)
 {
  if(bitmap_get(i))
   cout<<i<<endl;
 }

 return 0;
}

bool bitmap_init(int size)
{
 g_bitmap=(char *)malloc(((2*size)/8+1)*sizeof(char)); //分配空间，注意多分配了一个空间（+1）

 if(g_bitmap==NULL)
  return 0;

 g_size=(2*size)/8 + 1;

 memset(g_bitmap, 0x0, g_size);

 return 1; 
}

bool bitmap_set(int index)
{
 int quo = (2*index)/8;
 int remainder = (2*index)%8;
 unsigned char x = (0x3<<remainder);

 if(quo > g_size-1)         //判断是否越界
  return 0;
 if(quo==g_size-1&&remainder>0)
  return 0;

 x&=g_bitmap[quo];    //取相应的两位

 if(x==0x0)          //判断index对应的位置是否已经写入，并对其修改
  g_bitmap[quo]|=(0x1<<remainder);
 else if(x==(0x1<<remainder))
  g_bitmap[quo]+=(0x1<<remainder);
 else
  ;
 return 1;
}

bool bitmap_get(int index)
{
 int quo=(2*index)/8;
 int remainder=(2*index)%8;
 unsigned char x=(0x3<<remainder);
 if(quo>g_size-1)
  return 0;
 if(quo==g_size-1&&remainder>0)
  return 0;
 x&=g_bitmap[quo];
 unsigned char res=(0x1<<remainder);
 res&=x;
 return res>0?1:0;
}

void bitmap_free()
{
 free(g_bitmap);
 return ;
}
