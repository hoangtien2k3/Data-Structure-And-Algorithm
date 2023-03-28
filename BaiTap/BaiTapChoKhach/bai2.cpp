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


// BFS (Breadth-first search) : duyệt theo chiều rộng của đồ thị (áp dụng thuật toán duyệt theo chiều rộng vào đây)
int bfs(Point start, Point end, Queue* queue) {
    init_queue(queue);
    enqueue(queue, start);
    maze[start.x][start.y] = 1;
    int distance = 0;
    while (!is_queue_empty(queue)) {
    int size = 0;
    Node* current = queue->front; // gán con trỏ current bằng con trỏ front, để danh sách không bị thay đổi khi thực hiện tính toán
	    while (current != NULL) { // nếu current != NULL thì hàm nhảy vào hàm vòng lặp
		    size++; // tăng size lên 1 đơn vị
		    current = current->next; // con trỏ dịch duyển một nút
		}
	    for (int i = 0; i < size; i++) {
	        Point p = dequeue(queue);
	        if (p.x == end.x && p.y == end.y) {
	            maze[start.x][start.y] = 2;
	            return distance;
	        }
	        Point neighbors[] = {{p.x-1, p.y}, {p.x+1, p.y}, {p.x, p.y-1}, {p.x, p.y+1}}; // xet tọa độ
	        for (int j = 0; j < 4; j++) {
	            Point n = neighbors[j]; // gán giá trị Point
	            if (is_valid(n)) {
	                enqueue(queue, n); // gọi tới hàm enqueue xuống
	                maze[n.x][n.y] = 1; // gán tạo độ điểm đó là 1(nghĩa là đã được duyệt qua)
	            }
	        }
	    }
	    distance++; // tăng distance lên 1 đơn vị
	}
    maze[start.x][start.y] = 2; // lệnh gán
    return -1;  // No path found
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
