
/*
    ! 1. Cấu trúc dữ liệu đồ thị:

    + Đồ thị là một cặp các tập hợp (V, E), trong đó V là tập các đỉnh và E là tập các cạnh
    mà kết nối với các cặp điểm.


    + Các đối tượng được nối liền nhau được biểu diễn bởi các điểm được gọi 
    là các đỉnh (vertices), và các link mà kết nối các đỉnh với nhau được gọi 
    là các cạnh (edges).


    => Đồ Thị là một cặp các tập hợp (V, E), trong đó V là tập các đỉnh 
    và E là tập các cạnh mà kết nối các cặp điểm



    ! 2. Một số khái niệm cơ bản:
        + Đỉnh (Vertex)
        + Cạnh (Edge)


    - Đỉnh kề nhau:
        hai đỉnh được gọi là kề nhau nếu chúng kết nối với nhau thông qua một cạnh.
    
    - Đường:
        đường biểu diễn một dãy các cạnh giữa hai đỉnh.



    ! 3. Giải thuật tìm kiếm theo chiều sâu (Depth First Search):
        là giải thuật duyệt, hoặc tìm kiếm trên một cây, hoặc một đồ thị và sử dụng ngăn xếp (Stack)
        để ghi nhớ đỉnh liền kề để bắt đầu việc tìm kiếm



    ! 4. giải thuật tìm kiếm theo chiều rộng (Breadth First Search):
        là giải thuật duyệt theo chiều rộng, qua một đồ thị theo chiều rộng và sử dụng hàng đợi
        (Queue) để ghi nhớ đỉnh liền kề để bắt đầu việc tìm kiếm.



    ! 5. Sự khác nhau giữa (Depth First Search và Breadth First Search):

        + DFS giải quyết bài toán theo cách đào sâu nhất có thể từ 1 đỉnh
        + BFS là duyệt tất cả các đỉnh liền kề với các đỉnh đang duyệt, ở đây là độ sâu va độ
        rộng của thuật toán.


*/

