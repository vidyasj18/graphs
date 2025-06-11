#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        int xk,yk;
        int xq,yq;
        cin >> a >> b;
        cin >> xk >> yk;
        cin >> xq >> yq;
        
        if((abs(xk-xq)!=a && abs(yk-yq)!=b) || (abs(xk-xq)!=b && abs(yk-yq)!=a)) {
            cout << 0 << endl;
        }

        int count = 0;
        int x;
        int y;
        int x1;
        int y1;


        if((x = a+xk) && (y = yq-b)) {
            count++;
        }

        if((x1 = b+yk) && (y1 = xq-a)) {
            count++;
            if(x1==x && y1==y) {
                count--;
            }
        }

        cout << count << endl;
    }
}