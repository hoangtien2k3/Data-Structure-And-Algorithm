
/*
    Cho địa chỉ hai ô trên bàn cờ vua tiêu chuẩn, hãy kiểm tra chúng cùng màu hay khác màu
Ví dụ:
Với cell1 = "A1" và cell2 = "C3", kết quả là chessBoardCellColor(cell1, cell2) = true.
*/

#include<bits/stdc++.h>
using namespace std;

bool chessBoardCellColor(string cell1, string cell2)
{
    return ((cell1[0] + cell2[0] + cell1[1] + cell2[1]) - '0') % 2 ? false : true;
}

int main() {
    string cell1, cell2;
    cin >> cell1 >> cell2;
    if (chessBoardCellColor(cell1, cell2)) 
        cout << "True" << endl;
    else 
        cout << "False" << endl;
}
