#include<iostream>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include <string>

using namespace std;
#define MAXN 1010
int N,x[MAXN],y[MAXN];
bool visited[MAXN];

const int INF = 1<<28;
const double PI = 3.14159265358979323846;
int sp=0; // start point
double startAngle =0;

double getAngleToPoint(int cp,int np){
    int deltaY =y[np]-y[cp];
    int deltaX =x[np]-x[cp];

    double slope;
    if(deltaX==0) slope =INF;
    else slope = (double)abs(deltaY)/abs(deltaX);

    double angle;
    angle = slope==INF? 90:atan(slope)*180/PI;

    if(deltaX>=0 && deltaY>0) angle+=0;
    if(deltaX<0 && deltaY>=0) angle=180-angle;
    if(deltaX<0 && deltaY<0) angle=180+angle;
    if(deltaX>=0 && deltaY<=0) angle=360-angle;

    if(deltaX==0 && deltaY==0) angle = 360; // to prevent coming to the same position

    return angle;
}
int findNextPoint(int cp){ //current point, turning start angle

    int np=sp;

    for(int i=0;i<N;i++)
         if(cp!=i && getAngleToPoint(cp,i)>=startAngle && getAngleToPoint(cp,i) < getAngleToPoint(cp,np)) np=i;
         else if(cp!=i && getAngleToPoint(cp,i)>=startAngle && getAngleToPoint(cp,i) == getAngleToPoint(cp,np)
                 && abs(x[i]-x[cp])+abs(y[i]-y[cp])>abs(x[np]-x[cp])+abs(y[np]-y[cp])) np=i; // colinear points --> choose the furthest

    startAngle = getAngleToPoint(cp,np);

  //  cout<<cp<<' '<<np<<' '<<startAngle<<endl;
    return np;
}
int main(){
  
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>x[i];cin>>y[i];
    }


    for(int i=0;i<N;i++)
        if(y[i]<y[sp] || (y[i]==y[sp] && x[i]>x[sp]))  sp = i;

    int ans=0;
    int cp=sp; //current point =starting point

    while(true){
       cp=findNextPoint(cp);
       ans++;
       //cout<<cp<<endl;
       if(cp==sp) break; // current point == start poiont => terminate
    }
    cout<<ans<<endl;
    
  
}
