
#include  <iostream>
using namespace std;

long long count(char c,string x){
    long long Count=0;
    for (long long i=0;i<x.length(); i++){
        if (x[i]==c){
            Count++;
        }
    }
    return Count;

}

long long max(long long x,long long y){
    if (x<y){
        return y;
    }
    else {
        return x;
    }
}


long long sushi(){
    cout<<"type of sushi:";
    string sushi;
    cin>>sushi;
    long long d,e,f,g,h,i,r;
    cin>>d>>e>>f;
    cin>>g>>h>>i;
    cin>>r;
    if ((d < 1 || d > 100) || (e < 1 || e > 100) || (f < 1 || f > 100) ||
    (g < 1 || g > 100) || (h < 1 || h > 100) || (i < 1 || i > 100) ||
    (r < 1 || r > 1e12)) {
    cout<<"not in range"<<endl;
    return 0;
    } 
    long long x,y,z;
    x=count('B',sushi);
    y=count('S',sushi);
    z=count('C',sushi);
    
    long long low=0,high=r+100;

    for (; low <= high;) {
    long long middle = low + (high - low) / 2;
    long long w = 0;
    long long r1 = max(x * middle - d, w);
    long long r2 = max(y * middle - e, w);
    long long r3 = max(z * middle - f, w);
    long long price = r1 * g + r2 * h + r3 * i;
    if (price <= r)
        low = middle + 1;
    else
        high = middle - 1;
}

    cout<<high;
    return 0;

}

int main(){
    sushi();
    return 0;
}