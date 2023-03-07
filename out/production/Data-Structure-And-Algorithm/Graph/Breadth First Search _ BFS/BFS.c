// Giải Thuật Duyệt Theo Chiều Rộng.
/*
    - Breadth First Search là một thuật toán đệ quy để tìm kiếm tất cả các đỉnh của đồ thị 
      hoặc cấu trúc dữ liệu dạng cây. 

    * KHÁI NIỆM:
        BFS tiêu chuẩn sẽ thực hiện chia mỗi đỉnh của biểu đồ:
            + 1. Đã được duyệt.
            + 2. Không được duyệt.

        
        Cách thuật toán hoạt động như sau:

            + Bắt đầu bằng cách đặt bất kỳ một trong các đỉnh của biểu đồ ở phía cuối 
            của hàng đợi.

            + Lấy phần tử đầu tiên của hàng đợi và thêm nó vào danh sách đã truy cập.

            + Tạo danh sách các nút liền kề của đỉnh đó. Thêm những nút mà không có 
            trong danh sách đã truy cập vào phía sau hàng đợi.
            
            + Tiếp tục lặp lại bước 2 và 3 cho đến khi hàng đợi trống rỗng.


*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 40

struct queue
{
    int element[MAX];
    int front;
    int rear;
};

struct queue *create_queue();
void add_element_into_queue(struct queue *q, int);
int remove_element_from_queue(struct queue *q);
void print(struct queue *q);
int isEmpty(struct queue *q);
void print_queue(struct queue *q);

struct node
{
    int vertex;
    struct node *next;
};

struct node *create_node(int);

struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *traversed;
};

// Giải thuật BFS
void bfs(struct Graph *graph, int start_vertex)
{
    struct queue *q = create_queue();

    graph->traversed[start_vertex] = 1;
    add_element_into_queue(q, start_vertex);

    while (!isEmpty(q))
    {
        print_queue(q);
        int currentVertex = remove_element_from_queue(q);
        printf("%d Da Duoc Duyet\n", currentVertex);

        struct node *temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->traversed[adjVertex] == 0)
            {
                graph->traversed[adjVertex] = 1;
                add_element_into_queue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

struct node *create_node(int v)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

struct Graph *create_graph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->traversed = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->traversed[i] = 0;
    }

    return graph;
}

void add_edge(struct Graph *graph, int src, int dest) 
{
    struct node *new_node = create_node(dest);
    new_node->next = graph->adjLists[src];
    graph->adjLists[src] = new_node;
    new_node = create_node(src);
    new_node->next = graph->adjLists[dest];
    graph->adjLists[dest] = new_node;
}

struct queue *create_queue()
{
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void add_element_into_queue(struct queue *q, int value)
{
    if (q->rear == MAX - 1)
        printf("\nHang Doi Day!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->element[q->rear] = value;
    }
}

int remove_element_from_queue(struct queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Hang Doi Rong");
        item = -1;
    }
    else
    {
        item = q->element[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            printf("Dat Lai Hang Doi ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void print_queue(struct queue *q)
{
    int i = q->front;
    if (isEmpty(q))
    {
        printf("Hang Doi Rong. ");
    }
    else
    {
        printf("\nCac Phan Tu Trong Hang Doi La: ");
        for (i = q->front; i < q->rear + 1; i++)
        {
            printf("%d ", q->element[i]);
        }
    }
}

int main()
{
    struct Graph *graph = create_graph(6);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 5);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 4, 5);
    bfs(graph, 1);
    return 0;
}