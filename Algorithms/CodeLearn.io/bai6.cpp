
/*
    Cho số tự nhiên product
    Hãy tìm số nguyên dương nhỏ nhất (lớn hơn 0) mà tích các chữ số của số đó bằng product. 
    Nếu không có số thỏa mãn, trả ra -1.
    Ví dụ
    Với product = 12, thì kết quả digitsProduct(product) = 26;
    Với product = 19, thì kết quả digitsProduct(product) = -1. 
    Đầu vào/đầu ra:
    [Thời gian chạy] 0.5 giây
    [Đầu vào] integer product 
    Điều kiện:
    0 ≤ product ≤ 600.
    [Đầu ra] integer
*/

#include<iostream>
#include<cmath>

int digitsProduct(int product)
{
    if (product == 1) return 1;
    if (product == 0) return 10;
    int ans = 0;
    for (int i = 9; i >= 2; i--){ // tại sao lại duyệt từ 9->2 mà không phải là từ 2->9 nguyên nhân để lấy ra số có chữ số bé nhất( lấy ra số lớn xong đó đảo ngược lại)
        while(product % i == 0){
            ans = ans * 10 + i; // VD: product = 12 => ans = 60 phải luộn ngược lại thành 26
            product /= i;
        }
    }

    int ans2 = 0;
    while(ans != 0) {
        ans2 = ans2 * 10 + (ans % 10); // đảo ngược lại số ans trên
        ans /= 10;
    }
    
    return (product == 1) ? ans2 : -1;
}


int main() {
    int product;
    std::cout << "Enter the product digits: ";
    std::cin >> product;

    std::cout << digitsProduct(product);

    return 0;
}