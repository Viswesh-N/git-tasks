#include <iostream>
using namespace std;
int a[5][5];
int cnt=0;
int th=0;
int degree(int x,int th)
{
    if(x==21)
    th+=0;
    else
    if(x==23)
    th+=180;
    else
    if(x==32)
    th=-90;
    else
    if(x==12)
    th+=90;
    if(th<0)
    th+=360;
    return th;

}
void bot_move(int new_move)
{
    th=degree(move,-th);
    if(th==0)
    //go straight
    if(th==180)
    //back
    if(th==90)
    //right
    if(th==270)
    //left
}
void print(int x,int y)
{
    if(x!=5)
    cout<<"moved to ("<<y<<","<<x<<")\n\n";
    else
    cout<<"final matrix:\n\n";
    int i,j;
    cout<<"+---------+\n";
    for(i=0;i<5;i++)
    {
        cout<<"|";
        for(j=0;j<5;j++)
        {
            if(i==x&&j==y)
            cout<<"@";
            else
            if(a[i][j]>0)
            cout<<"1";
            else
            if(a[i][j]<0)
            cout<<"#";
            else
            cout<<" ";
            cout<<"|";
        }
        cout<<"\n";
        if(i==4)
        break;
        cout<<"|-+-+-+-+-|\n";
    }
    cout<<"+---------+\n\n\n";
}
int check(int x, int y,int b)
{
    if(x!=4)
    {
        if(a[x+1][y]==b)
        return 32;
    }
    if(y!=4)
    {
        if(a[x][y+1]==b)
        return 23;
    }
    if(x!=0)
    {
        if(a[x-1][y]==b)
        return 12;
    }
    if(y!=0)
    {
        if(a[x][y-1]==b)
        return 21;
    }
    return 0;
}

int done1()
{
    int chk=1;
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            /*if(a[i][j]>0&&check(i,j,0)>=0)
            return 0;*/
            /*if(a[i][j]<2&&a[i][j]>0)
            check=0;*/
            if(a[i][j]==0 && check(i,j,1)!=0)
            chk=0;
        }
    }
    return chk;
}

void move(int x, int y)
{
    int i=0,xn,yn;
    a[x][y]++;
    while(1)
    {
        int chk=check(x,y,i);
        if(chk!=0)
        {
            xn=x+chk/10-2;
            yn=y+chk%10-2;
            if(i==0)
            a[x][y]=1;
            break;
        }
        else
        a[x][y]++;
        i++;
    }
    //if(done())
    //return;
    if(done1())
    {
        //cout<<"qwert";
        return;
    }
    cnt++;
    print(xn,yn);
    move(xn,yn);
}
int main()
{ 
    int bx,by,i,j;
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    a[i][j]=0;
    for(i=0;i<5;i++)
    {
        while(1)
        {
            cin>>bx>>by;
            if(by==0&bx==0)
            {
                cout<<"Invalid";
            }
            else
            break;
        }
        a[by][bx]=-1;
    }
    print (0,0);
    move(0,0);
    print (5,5);
    cout<<"steps"<<cnt<<"\n";
    return 0;
} 
