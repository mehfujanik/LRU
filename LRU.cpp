#include<bits/stdc++.h>
#define SIZE 100
using namespace std;
int n, m, block;
int cache[SIZE][SIZE], track[SIZE][SIZE];

void show()
{
    for(int  i = 0; i<block; i++)
    {
        for(int  j = 0; j<n; j++)
            printf("%d\t",cache[i][j]);
        cout<<endl;
    }

   /* for(int  i = 0; i<block; i++)
    {
        for(int  j = 0; j<n; j++)
            printf("%d\t",track[i][j]);
        cout<<"Track"<<endl;
    }*/
}

void hit(int y, int I,int j)
{
    int mn=0;
    for(int i=0;i<n;i++)
                {
                if(track[y][i]>mn)
                    mn=track[y][i];
                }

    cout<<"Hit\n";
    track[y][I]=mn+1;
    show();

}
void miss(int y, int num,int N)
{
    cout<<"Miss\n";
    int cont=0;
    int l,cn=0;
    int mn=10000;
    for(int i=0;i<n;i++)
      {
        if(cache[y][i]==-1){
            cache[y][i]=num;
            track[y][i]=N;
            cont++;
            break;
            }
      }
        if (cont==1)
            {
                show();

             }

        else
            {
                for(int i=0;i<n;i++)
                {
                    if(track[y][i]<mn)
                       {
                        mn=track[y][i];
                        l=i;
                       }

                }
             //  cout<<endl<<mn<<" "<<l<<endl;

              // if(cn==0)
              //  l=0;

            cache[y][l]=num;
            track[y][l]=N;
            show();

           // cout<<" ***************\n\n";
            }


}

void LRU(int num, int N)
{
    int y = num%block;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(cache[y][i]==num)
                {
                hit(y,i,num);
                cnt++;
               // cout<<" ####\n\n";
                break;
                }
    }
    if(cnt==0)
        miss(y,num,N);

}




int main()
{
    scanf("%d%d", &n, &m);
    block = m/n;

    for( int i = 0; i<block; i++)
        for(int  j = 0; j<n; j++)
        {
            cache[i][j] = -1;
            track[i][j] = -1;
        }
    show();
    for( int i = 0; 1; i++)
    {
        int temp;
        cin>>temp;
        if(temp == -1)
            break;
        LRU(temp, i);

    }


    return 0;

}
