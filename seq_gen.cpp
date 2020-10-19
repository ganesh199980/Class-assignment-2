# include<iostream>
using namespace std;
#include<string>
#include<vector>
int main(){
    int n;
    cout << "size of your name" << endl;
    cin >> n;
    vector <char> name;
    cout << "Name in CAPS" << endl;
    for(int j=0 ; j<n; j++){
        char g;
        cin >> g;
        name.push_back(g);
    }
    vector <char> seq;
    for(int i=0; i<n; i++){
        char test = name[i];
        if(test == 'B') seq.push_back('C');
        else if(test == 'J') seq.push_back('K');
        else if(test == 'O') seq.push_back('P');
        else if(test == 'U') seq.push_back('V');
        else if(test == 'X') seq.push_back('Y');
        else if(test == 'Z') seq.push_back('A');
        else seq.push_back(test);
    }
    cout << " the required sequence is" << endl;
    for(int i=0; i<n; i++){
        cout << seq[i] << " ";
    }
    cout << "\n";
    return 0;
}
