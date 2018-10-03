#include<iostream>
using namespace std;
char matrix[9][9];
char original[9][9];
int i,j;
int main(){
    int randi,randj;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
        {
            matrix[i][j]='-';
            original[i][j]='-';
        }
    }
     for(j=0;j<15;j++)
    {
          matrix[rand()%9+0][rand()%9+0]='*';
    }
    cout<<" ";
    for(int i=0;i<9;i++)
        cout<<" "<<i<<"";
    cout<<"\n";
    for(i=0;i<9;i++){
        cout<<i<<" ";
        for(j=0;j<9;j++)
        {
            cout<<original[i][j]<<" ";
        }cout<<"\n";
    }
    int x,y,flag,countmines,out=0,wincount=0;
    while(1){
        cout<<"Enter the values of x and y :";
        cin>>x;
        cout<<" ";
        cin>>y;
        cout<<"\n";
        if(x<0||y<0||x>8||y>8){
            cout<<"Enter a valid coordinates\n";
            continue;
        }
        if(original[x][y]>='0'){
            cout<<"coordinates already revealed\n";
            continue;
        }
        flag=0,countmines=0,wincount=0;
        for(i=x-1;i<=x+1;i++){
            for(j=y-1;j<=y+1;j++){
                if(i==x&&j==y){
                    if(matrix[i][j]=='*'){
                        cout<<"You lost!!!";
                        out=1;
                    }
                }
                if(i<0||j<0||i>8||j>8){
                    continue;
                }else{
                    if(matrix[i][j]=='*'){
                        flag=1;
                        countmines++;
                    }
                }
            }
        }
        if(out==1){
            original[x][y] = '*';
            cout<<"\n";
             cout<<" ";
            for(int i=0;i<9;i++)
                 cout<<" "<<i<<"";
            cout<<"\n";
            for(i=0;i<9;i++){
                cout<<i<<" ";
                for(j=0;j<9;j++)
                {
                    if(original[i][j]>='0'){
                        cout<<original[i][j]<<" ";
                        continue;
                    }
                    cout<<matrix[i][j]<<" ";
                }cout<<"\n";
            }
            return 0;
        }
        if(flag==1){
           // matrix[x][y]=countmines+'0';
           original[x][y] = countmines+'0';
        }else{
            for(i=x-1;i<=x+1;i++){
                if(i<0||i>8)
                    continue;
            for(j=y-1;j<=y+1;j++){
                   // matrix[i][j]='0';
                if(j<0||j>8){
                    continue;
                }
                if(original[i][j]>='0'){
                    continue;
                }
                    original[i][j]='0';
                    //cout<<i<<j<<" ";
                }
            }
        }
         cout<<" ";
        for(int i=0;i<9;i++)
            cout<<" "<<i<<"";
        cout<<"\n";
        for(i=0;i<9;i++){
            cout<<i<<" ";
            for(j=0;j<9;j++)
            {
                cout<<original[i][j]<<" ";
                if(original[i][j]!='-'||matrix[i][j]=='*'){
                    wincount++;
                }
            }cout<<"\n";
        }
        if(wincount==81){
            cout<<"You Won!!!\n";
            return 0;
        }
    }
    return 0;
}   