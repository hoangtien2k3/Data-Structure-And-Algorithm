
/*
    Tham lam (hay háu ăn) là một trong những phương pháp thiết kế thuật toán phổ biến nhất. 
    Nếu bạn đã đọc truyện dân gian, có một câu chuyện như thế này: trên một mâm có nhiều 
    món, món ngon nhất sẽ được ăn trước, ăn xong sẽ chuyển sang món ngon thứ hai và tiếp 
    tục. đến món thứ ba,…


    Nhiều thuật toán nổi tiếng được thiết kế dựa trên những ý tưởng tham lam, chẳng hạn như 
    thuật toán cây bao trùm tối thiểu của Dijkstra, thuật toán cây bao trùm tối thiểu của 
    Kruskal, v.v.

    Thuật toán tham lam là một thuật toán tối ưu hóa tổ hợp.

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


#include<iostream>
#include<algorithm>
using namespace std;

void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}

int a[100001];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	quickSort(a, 0, n-1);
	int k = 1;
	int max = 0;
	for (int i = n-1; i >= 0; i--){
		if (a[i] + k > max){
			max = a[i] + k;
		}
		k = k + 1;
	}
	cout << max;
	return 0;
}