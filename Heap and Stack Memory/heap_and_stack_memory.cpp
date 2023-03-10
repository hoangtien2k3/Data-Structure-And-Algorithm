
/*
    => Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và 
    lưu trữ trong RAM khi chương trình được thực thi.


    ! KHẢ NGĂNG LƯU TRỮ CỦA VÙNG NHỚ STACK VÀ HEAP

    + Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền 
    vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình 
    được biên dịch.


    + Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được 
    cấp phát động bởi các hàm malloc - calloc - realloc (trong C) hoặc từ 
    khóa new (trong c++, c#, java,...).



    ! KÍCH THƯỚC VÙNG NHỚ:
    
    + STACK thì vùng nhớ là cố định, và nó tùy thuộc vào hệ điều hành.

    + HEAP thì là vùng nhớ động nên nó sẽ không có định, và có thể tăng hoặc giảm 
    để đáp ứng nhu cầu sử dụng.



    ! ĐẶC ĐIỂM VÙNG NHỚ:

    + STACK là vùng nhớ được quản lý bởi hệ điều hành. Khi thực hiện xong công việc thì
    vùng nhớ STACK sẽ tự động được hủy.

    + HEAP là vùng nhớ được quản lý bới lập trình viên nên sẽ không tự động hủy được.
    Vì thế nên phải tự hủy bằng tay(bằng cơm).



    ! LỖI XẢY RA:

    + STACK là vùng nhớ của hệ điều hành. nên có khả năng vượt quá khả năng lưu trữ
    STACK OVERFLOW

    + HEAP nếu liên tục cấp phát vùng nhớ mà không giải phóng thì có thể xảy ra tràn
    HEAP OVERFLOW . Và nếu bạn ban khởi tạo vùng nhớ quá lớn.



    ! KHI NÀO SỬ DỤNG VÙNG NHỚ HEAP VÀ KHI NÀO SỬ DỤNG CÙNG NHỚ STACK:

    + Sử dụng STACK khi bạn biết được kích thước vùng nhớ. Và ngược lại thì 
    sử dụng vùng nhớ HEAP. 


*/

#include <iostream>
using namespace std;

void main(){

    int a = 3; //Dữ liệu biến a sẽ được lưu trong bộ nhớ Stack
    
    int *b = new int[10]; // Dữ liệu của con trỏ b sẽ được lưu trong bộ nhớ Heap
    
}

