/*
 * http://blog.csdn.net/forestlight/article/details/6839180
 * http://www.cnblogs.com/dong008259/archive/2012/01/04/2312451.html
 * http://www.cnblogs.com/dong008259/archive/2011/12/14/2286915.html
 */

#include<stdio.h>
#include<string.h>
#include <dirent.h>
#include <time.h>
#include "bloom.h"
long n=0;
unsigned int sax_hash(const char *key)
{
    unsigned int h=0;

    while(*key) h^=(h<<5)+(h>>2)+(unsigned char)*key++;

    return h;
}

unsigned int sdbm_hash(const char *key)
{
    unsigned int h=0;
    while(*key) h=(unsigned char)*key++ + (h<<6) + (h<<16) - h;
    return h;
}

// JS Hash
unsigned int JS_hash(char *str)
{
    unsigned int hash = 1315423911;
 
    while (*str)
    {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }
 
    return (hash & 0x7FFFFFFF);
}

int traverse(char *s,BLOOM *bloom1)
{
    DIR *directory_pointer;
    char current_path[10000];
    char filepath[10000];
    char now[10000];
    struct dirent *entry;
    strcpy(current_path,s);
      if ((directory_pointer=opendir(s))==NULL)
            printf("Error opening!/n");
      else
      {
          while ((entry=readdir(directory_pointer))!=NULL)
            {   
            if(strcmp(entry->d_name,".")!=0&&strcmp(entry->d_name,"..")!=0)    
            {
                if(entry->d_type==4)
                {
                    strcpy(filepath,current_path);
                    strcat(filepath,"/");   
                    strcat(filepath,entry->d_name);
                    traverse(filepath,bloom1);
                }
                else if(entry->d_type==8)
                {
                    strcpy(now,current_path);
                    strcat(now,"/");
                    strcat(now,entry->d_name);
                    n++;
                    printf("%ld/n",n);
                    bloom_add(bloom1,now);
                }
            }
            }
                closedir(directory_pointer);
      }
}

void bloom_set(BLOOM *bloom1)
{
        DIR *directory_pointer;
        char temp[100]="";
        struct dirent *entry;
        if ((directory_pointer=opendir("/"))==NULL)
        printf("Error opening!/n");
        else
          {
          while ((entry=readdir(directory_pointer))!=NULL)
            {   
            if(strcmp(entry->d_name,".")!=0&&strcmp(entry->d_name,"..")!=0)    
            {
                if(entry->d_type==4)
                {   
                    strcpy(temp,"/");
                    strcat(temp,entry->d_name);
                    traverse(temp,bloom1);
                }
                else
                {
                    strcpy(temp,"/");
                    strcat(temp,entry->d_name);
                    bloom_add(bloom1,temp);
                    n++;
                    printf("%ld/n",n);
                }
            }
            }
            closedir(directory_pointer);
          }
}

int main()
{
    BLOOM *bloom;
    char s[200];
    int result;
    if(!(bloom=bloom_create(250000, 3, sax_hash, sdbm_hash,JS_hash)))
    {
            fprintf(stderr, "ERROR: Could not create bloom filter/n");
            return EXIT_FAILURE;
        }
    bloom_set(bloom);
    printf("bloom set successfully!/ninput the file u want to search:/n");
    while(1)
    {
        scanf("%s",s);
        if(strcmp(s,"quit")==0)break;
        result=bloom_check(bloom,s);
        if(result==1)printf("file found!/n");
        else printf("no such file!/n");
    }   
}
