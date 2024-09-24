#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
int main()
{
  int n,i,j,sum=0;
  int arrv[10], ser[10], start[10], finish[10],wait[10], turn[10];
  float avgturn=0.0,avgwait=0.0;
  start[0]=0;
//clrscr();
  printf("\n Nhap vao so luong tien trinh:");//ENTER THE NO. OF PROCESSES
  scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("\n Nhap vao thoi gian den va thoi gian thuc hien %d: ",i+1);//ENTER THE ARRIVAL TIME AND SERVICE TIME OF PROCESS
    scanf("%d%d",&arrv[i],&ser[i]);
    }
  for(i=0;i<n;i++)
  {
  sum=0;
    for(j=0;j<i;j++)
    sum=sum+ser[j];
  start[i]=sum;
  }
  for(i=0;i<n;i++)
  {
    finish[i]=ser[i]+start[i];
    wait[i]=start[i];
    turn[i]=ser[i]+wait[i];
  }
  
  for(i=0;i<n;i++)
  {
    avgwait+=wait[i] ;
    avgturn+=turn[i];
  }
  avgwait/=n;
  avgturn/=n;
  
  printf("\n TienTrinh\t Den\t ThucHien\t BatDau\t KetThuc Doi\t Luot\t \n");//PROCESS ARRIVAL SERVICE START FINISH WAIT TURN
  for(i=0;i<n;i++)
  {
    printf("\n\tP%d\t%d \t %d \t\t %d \t %d \t %d \t %d \n",i ,arrv[i],   
    ser[i], start[i], finish[i],wait[i],turn[i]);
  }
  printf("\n Thoi Gian Doi Trung Binh = %f tu",avgwait);//AVERAGE WAITING TIME
  printf("\n Thoi Gian Xoay Vong Trung Binh = %f tu \n",avgturn);//AVERAGE TURN AROUND TIME
  //getc();
  return 0;
}