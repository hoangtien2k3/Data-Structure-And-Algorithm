
//! Divide And Conquer: Chia để trị
/*
    
    + Phương pháp chia để trị (Divide and Conquer) là một phương pháp quan trọng trong việc thiết kế các giải thuật. 
    Ý tưởng của phương pháp này khá đơn giản và rất dễ hiểu: Khi cần giải quyết một bài toán, ta sẽ tiến hành chia 
    bài toán đó thành các bài toán con nhỏ hơn. Tiếp tục chia cho đến khi các bài toán nhỏ này không thể chia thêm 
    nữa, khi đó ta sẽ giải quyết các bài toán nhỏ nhất này và cuối cùng kết hợp giải pháp của tất cả các bài toán 
    nhỏ để tìm ra giải pháp của bài toán ban đầu.


    Ex:
    
    + Quick Sort và Merge Sort: là hai thuật toán điển hình cho giải thuật  chia đê trị

    ! CÁC BƯỚC CỦA THUẬT TOÁN CHIA ĐÊ TRỊ:

        + bước 1: chia nhỏ (divide)
                chia nhỏ bài toán lớn thành các bài toán con
        
        + bước 2: giải bài toán con (conquer)
                giải các bài toán con đã được chia nhỏ ra
        
        + bước 3: kết luận lời giải (Merge)
                chúng ta sẽ kết hợp chúng một cách đệ quy để tìm ra giải pháp cho bài toán ban đầu.


    ! HẠN CHẾ CỦA THUẬT TOÁN CHI ĐỂ TRỊ:

        + làm sao để tách các bài toán lớn thành các bài toán con. Bời vì các bài toán con được giải
        với các phương pháp khác nhau nên sẽ rất phức tạp.

        + Việc kết hợp các bài toán con được thực hiện đó như thế nào.

*/
/*
        ! So sánh:
         * Thuật toán tham lam và thuật toán quy hoạch động.

        Thuật toán tham lam là một thuật toán tìm kiếm chọn giải pháp tối ưu cục bộ ở mỗi bước với hy 
        vọng tìm ra giải pháp tối ưu toàn cục.
        Thuật toán Lập trình động tối ưu hóa các vấn đề gối nhau.

         * Thuật toán chia để trị và Thuật toán quy hoạch động:

        Chia để trị là sự kết hợp các giải pháp của các bài toán con để tìm ra lời giải của bài toán ban đầu.
        Thuật toán Lập trình Động sử dụng kết quả của bài toán con và sau đó cố gắng tối ưu hóa bài toán lớn hơn. 
        Thuật toán Lập trình Động sử dụng phương pháp Ghi nhớ để ghi nhớ kết quả của các bài toán con đã giải.

*/

/*
    ! SỰ KHÁC NHAU GIỮA QUY HOẠCH ĐỘNG VÀ CHIA ĐỂ TRỊ:
    - Hai điểm khác nhau khá rõ giữa Quy hoạch động và Chia để trị. 
        + Đầu tiên, chia để trị chỉ xử lý bài toán theo chiều từ trên xuống (top-down). 
        Và các bài toán con được thực hiện một cách độc lập

        + Trong khi quy hoạch động hỗ trợ cả hai chiều (top-down và bottom-up). 
        Nhưng các bài toán con lại không được thực hiện một cách độc lập, thay vào đó kết quả 
        của bài toán con này sẽ được lưu và sử dụng cho các bài toán con tương tự.

*/



/*
    Cho một dãy gồm n số nguyên và một số nguyên x. 
    Hãy đếm xem trong dãy có bao nhiêu phần tử có giá trị x.
    
*/

#include<bits/stdc++.h>
using namespace std;

int count(int *arr, int l, int r, int x) {
    if (l == r) {
        if (arr[l] == x || arr[r] == x) {
            return 1;
        } else return 0;
    } else {
        int mid = (l + r) / 2;
        return count(arr, l, mid, x) + count(arr, mid + 1, r, x);
    }
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x; cin >> x;
    cout << count(arr, 0, n - 1, x);
    delete arr;
    return 0;
}


