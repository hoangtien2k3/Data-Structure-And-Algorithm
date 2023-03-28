#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 50


// set cứng một mảng cho trước
int maze[][5] = {
	    {3, 0, 0, 0, 0},
	    {0, 1, 1, 1, 0},
	    {0, 1, 2, 1, 0},
	    {0, 1, 0, 0, 0},
	    {0, 0, 0, 0, 0}
	};
int rows = 5, cols = 5; // rows: số hàng, cols số cột


// tạo một struct Point có 2 thuộc tính là tọa độ x và y
typedef struct {
    int x;
    int y;
} Point;

// tạo một struct Node với 2 thuộc tính là data (dữ liệu) và Node *next là phần con trỏ
typedef struct Node {
    Point data;
    struct Node *next;
} Node;

// tạo struct Queue gồm có con trỏ đầu *front và con trỏ cuối là *rear ( để quản lý danh sách )
typedef struct {
    Node *front;
    Node *rear;
} Queue;


// khởi tạo giá trị ban đầu cho con trỏ *front và *rear là NULL(nghĩa là nó chưa trỏ vào đâu cả)
void init_queue(Queue *q) {
    q->front = q->rear = NULL;
}

// hàm này kiểm tra xem danh sách có rỗng hay không
bool is_queue_empty(Queue *q) {
    return q->front == NULL;
}

// hàm này dùng để thêm phần tử vào trong danh sách Queue
void enqueue(Queue *q, Point data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data; // cập nhật giá trị data
    new_node->next = NULL; // con trỏ trỏ vào giá trị NULL Pointer 
    if (is_queue_empty(q)) { // nếu danh sách rỗng
        q->front = q->rear = new_node;  // gán giá trị cho nó
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}


// hàm này cũng có chức năng giống hàm trên
Point dequeue(Queue *q) {
    Point data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

// hàm này thì dùng để kiểm tra xem điểm đó có thỏa mãm không(trả về true nếu thoải mãn yêu cầu bài toán đặt ra)
bool is_valid(Point p) {
    return p.x >= 0 && p.x < rows && p.y >= 0 && p.y < cols && maze[p.x][p.y] != 1;
}


// Hàm BFS sẽ tìm kiếm đường đi ngắn nhất từ điểm bắt đầu "start" đến điểm kết thúc "end" trên một ma trận "maze". 
// Hàm này trả về độ dài đường đi ngắn nhất hoặc giá trị -1 nếu không tìm thấy đường đi.
int bfs(Point start, Point end, Queue* queue) {
    init_queue(queue);              // Hàm "init_queue" được sử dụng để khởi tạo hàng đợi trống.
    enqueue(queue, start);          // Thêm điểm bắt đầu "start" vào hàng đợi 
    
    maze[start.x][start.y] = 1;     // và đánh dấu nó là đã duyệt qua (giá trị 1 trên ma trận "maze").
    int distance = 0;               // Khởi tạo biến "distance" để đếm số bước đi trong đường đi ngắn nhất từ "start" đến "end".
    while (!is_queue_empty(queue)) {    // Tiếp tục thực hiện vòng lặp cho đến khi hàng đợi trống.
        int size = 0;

        // Tính toán số lượng phần tử trong hàng đợi bằng cách duyệt từ đầu đến cuối danh sách liên kết. 
        Node* current = queue->front; 
	    while (current != NULL) { 
		    size++;                     // Biến "size" được sử dụng trong vòng lặp tiếp theo để chỉ số lượng phần tử cần duyệt trong hàng đợi ở mỗi lần lặp.
		    current = current->next;     // Dịch con trỏ current sang phần tử kế tiếp trong danh sách liên kết.
		}

        // Đoạn code này có nhiệm vụ lấy ra các điểm hàng xóm của điểm hiện tại đang được xét, đánh dấu các 
        // điểm hàng xóm đã được duyệt qua và thêm các điểm hàng xóm chưa duyệt vào trong queue.
	    for (int i = 0; i < size; i++) {    // Vòng lặp for duyệt qua từng điểm trong queue, được lưu trữ dưới dạng một danh sách liên kết. 
	        Point p = dequeue(queue);       // Mỗi lần duyệt qua một điểm, ta sẽ lấy điểm đó ra khỏi queue bằng hàm dequeue.
	        if (p.x == end.x && p.y == end.y) { // Sau đó, ta kiểm tra xem điểm đó có trùng vị trí với điểm kết thúc hay không.
	            maze[start.x][start.y] = 2;     // Nếu có, ta đánh dấu điểm bắt đầu là đã tìm được đường đi
	            return distance;                // trả về khoảng cách từ điểm bắt đầu đến điểm hiện tại thông qua biến distance.
	        }

            // Nếu điểm hiện tại không phải là điểm kết thúc, ta tạo một mảng 4 điểm hàng xóm của điểm hiện tại và kiểm tra xem từng điểm hàng xóm có 
            // hợp lệ không (không được vượt quá kích thước của ma trận và chưa được duyệt trước đó).
	        Point neighbors[] = {{p.x-1, p.y}, {p.x+1, p.y}, {p.x, p.y-1}, {p.x, p.y+1}}; 
	        for (int j = 0; j < 4; j++) {
	            Point n = neighbors[j]; // gán giá trị Point
	            if (is_valid(n)) {  // Nếu điểm hàng xóm hợp lệ, ta thêm điểm hàng xóm vào queue bằng hàm enqueue
	                enqueue(queue, n);  // gọi tới hàm enqueue xuống
	                maze[n.x][n.y] = 1; // đánh dấu điểm đó là đã được duyệt qua bằng cách gán giá trị của điểm đó trong ma trận maze bằng 1.
	            }
	        }
	    }

	    distance++; // Tăng biến distance lên 1 đơn vị.
        // Quá trình lặp lại cho đến khi queue rỗng hoặc tìm được đường đi.
	}

    maze[start.x][start.y] = 2; // Gán giá trị 2 vào tọa độ đầu tiên để cho biết rằng nó đã được duyệt qua.
    return -1;  // No path found (Trả về -1 nếu không tìm thấy đường đi từ điểm bắt đầu đến điểm kết thúc.)
}


// hàm này để in ra ma trận thêm vào
void print_maze() {
	printf("A = { ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\t%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("    };\n\n");
}

int main() {
	Queue q;
    Queue* queue = &q;

    // lối vào và lối ra của đồ thị
    Point entrance = {-1, -1}; // điểm bắt đầu
    Point exit = {-1, -1}; // điểm kết thúc
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 2) { 
                entrance.x = i; // gán giá trị
                entrance.y = j; 
            } else if (maze[i][j] == 3) {
                exit.x = i; // gán giá trị
                exit.y = j;
            }
        }
    }

    if (entrance.x == -1 || entrance.y == -1) { // check điều kiện
        printf("Entrance not found\n"); // in ra màn hình và return 1(kết thúc chương trình)
        return 1;
    }
    if (exit.x == -1 || exit.y == -1) {
        printf("Exit not found\n");
        return 1;
    }

    printf("Maze:\n");
    print_maze();

    int shortest_path = bfs(entrance, exit, queue); // gọi hàm bên trên xuống, nó sẽ trả về kết quả
    if (shortest_path == -1) { // nếu kết quả là -1, thì nhảy vào lệnh if
        printf("No path found\n");
    } else { // ngược lại thì nhảy vào else và in ra màn hình
        printf("Shortest path: %d\n", shortest_path);
    }

    // giải phóng vùng nhớ
    Node *current_node = queue->front;
    while (current_node != NULL) {
        Node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}
