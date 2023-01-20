
#include<bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *next;
};

bool empty(Node *top) {
    return top == NULL;
} 

Node *makeNode(string x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void push(Node* &top, string x) {
    Node *temp = makeNode(x);
    if (top == NULL) {
        top = temp;
    } else {
        temp->next = top;
        top = temp;
    }
}

void pop(Node* &top) {
    if (top == NULL) 
        return;
    top = top->next;
}

string getTop(Node *top) {
    return top->data;
}

int main() {
    Node *top = NULL;

    string s;
    cout << "Emter this String: ";
    getline(cin, s);
    stringstream ss(s);
    string word;
    while(ss >> word) {
        push(top, word);
    }
    
    while(!empty(top)) {
        cout << getTop(top) << " ";
        pop(top);
    }

    return 0;
}





//! Cách khác dùng trong C/C++
// d. đảo ngược các từ trong chuỗi.
char *daoNguocTuCoTrongChuoi(char *S) {
    char *ketQua = (char*) malloc(sizeof(char) * (strlen(S)));
    int j = 0;
    int dem = 0;
    for(int i = strlen(S) - 1; i >= 0; i--){
        dem++;
        if (S[i] == ' '){
            for(int k = i; k < i + dem; k++) { // (i + dem) = strlen(S);
                ketQua[j++] = S[k + 1]; 
            }
            ketQua[j - 1] = ' ';
            dem = 0;
        }
        if (i == 0){
            for(int k = i; k < i + dem; k++){
                ketQua[j++] = S[k];
            }
        }
    }
    ketQua[strlen(S)] = '\0';
    return ketQua;
}



