# include<iostream>
using namespace std;
#include<vector>
float set1(char d){
 if (d<=70) return 0.3;
 if (d>=71 && d<=76) return 0.2;
 if (d>=77 && d<=82) return 0.3;
 if (d>=83 && d<=89) return 0.2;
 return 0;
}
float set2(char d){
 if (d<=70) return 0.1;
 if (d>=71 && d<=76) return 0.4;
 if (d>=77 && d<=82) return 0.1;
 if (d>=83 && d<=89) return 0.4;
 return 0;
}
int main(){
    int n;
    cout << "sequence length" <<endl;
    cin >> n;
    vector<char> seq;
    cout << "sequence (IN CAPS) " <<endl;
    for(int i=0; i<n; i++){
        char e;
        cin >> e;
        seq.push_back(e);
    }
    float p1 = 0.45;
    float p2 = 1-p1;
    float p11 = 0.35;
    float p12 = 1-p11;
    float p21 = 0.45;
    float p22 = 1-p21;
    double result[2][n];
    result [0][0] = p1*set1(seq[0]);
    result [1][0] = p2*set2(seq[0]);
    for(int m=1; m<seq.size(); m++){
        result [0][m] = ((result [0][m-1]*p11*set1(seq[m])) + (result [1][m-1]*p21*set1(seq[m])));
        result [1][m] = ((result [0][m-1]*p12*set2(seq[m])) + (result [1][m-1]*p22*set2(seq[m])));
    }
    cout<< "State 1 \n" ;
    for(int e=0; e<n; e++) {
        cout << result [0][e] << " " ;
    }
    cout << "\n" ;
    cout<< "State 2 \n" ;
    for(int e=0; e<n; e++) {
        cout << result [1][e] << " " ;
    }
     cout << "\n" ;
    cout << "Thus, the probability of the observation is " << result [0][n-1] + result [1][n-1] << endl;
    return 0;
}