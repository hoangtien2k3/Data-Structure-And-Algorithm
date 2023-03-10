
// Quay lui xâu nhị phân có độ dài N: (X1, X2, X3...XN)

#include <iostream>
using namespace std;
 
int N, x[100];
 
void in(int x[]){
    for (int i = 1; i <= N; i++)
        cout << x[i];
    cout << endl;
}
 
void deQuy(int i){
    // duyệt các khả năng xảy ra ... đó chính là 0 và 1
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == N) {
            in(x);
        } else {
            deQuy(i + 1);
        }
    }
}
 
int main(){
    system("cls");
    
    cout << "Nhap vao N: ";
    cin >> N;
    deQuy(1);

    system("pause");
    return 0;
}