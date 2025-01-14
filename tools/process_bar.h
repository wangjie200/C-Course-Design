/*
 * @author Yang Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/3/19
 */

#ifndef PROCESS_BAR_H
#define PROCESS_BAR_H

#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#define BLACK "\e[0;30m"
#define YELLOW "\e[1;33m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define NONE "\e[0m"
void process_bar();

void process_bar(char *loding_info)
{
        printf(BLINK"\t\t%s\n"NONE,loding_info);
        char string[4]={'-','/','|','\\'};
        char buf[101]={0};
        int i=0;
        for(;i<=100;i++)
        {
                buf[i]='#';
                printf(BLACK"[%%%d]"NONE,i);
                if(i<=25)
                {
                        printf(YELLOW"[%c]",string[i%4]);
                        printf(YELLOW"[%s]\r",buf);
                }
                else if(i<=50)
                {
                        printf(GREEN"[%c]",string[i%4]);
                        printf(GREEN"[%s]\r",buf);
                }
                else if(i<=75)
                {
                        printf(BLUE"[%c]",string[i%4]);
                        printf(BLUE"[%s]\r",buf);
                }
                else{
                        printf(RED"[%c]",string[i%4]);
                        printf(RED"[%s]\r",buf);
                }
                fflush(stdout);
                usleep(50*1000);
        }
        printf(BLACK"\n"NONE);
        printf("\t\tloading done!\n");
        usleep(2000000);
        //system("clear");
        fflush(stdout);
}

#endif