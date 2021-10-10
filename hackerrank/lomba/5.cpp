#include<iostream>
#include<vector>
#include<stdbool.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;

bool selamat(ull lompat, vector<ull> &n, ull post){
//    cout<<lompat<<" "<<post<<"\n";
    ull next = n[post] + lompat;
    
    for(unsigned i = post + 1; i < n.size(); i++){
        if (next == n[i]){
            if ( next == n[n.size()-1] )
                return true;
            else {
                if (lompat > 1){
                    if ( selamat(lompat-1, n, i) )
                        return true;
                }
                if ( selamat(lompat, n, i) )
                    return true;
                if ( selamat(lompat+1, n, i) )
                    return true;
            }
            break;
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
      
    ull t,x,first;
    vector <ull> n;
    cin >> t;
    for (ull i = 0; i < t; i++) {
        cin>>x;
        n.push_back(x);
    }
    first = n[1] - n[0];
    
    if (first == 1){
      if (selamat(first, n, 0))
        cout << "Pemain sirkus selamat\n";
      else
        cout << "Panggil ambulans\n";
    }
    else
        cout << "Panggil ambulans\n";
      
    return 0;
}