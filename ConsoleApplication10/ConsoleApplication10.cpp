#include<iostream>
#include<queue>
using namespace std;
constexpr auto ROW = 10;
constexpr auto COL = 10;
struct Point
{
    int x;
    int y;
};
struct queueNode
{
    Point pt;  
    int dist;  
};
bool isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) &&
        (col >= 0) && (col < COL);
}
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };
int BFS(int mat[][COL], Point src, Point dest)
{
    if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
        return -1;
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);
    visited[src.x][src.y] = true;
    queue<queueNode> q;
    queueNode s = { src, 0 };
    q.push(s); 
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            if (isValid(row, col) && mat[row][col] &&
                !visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
    return -1;
}
int main()
{
    int cases;
    Point source;
    Point dest;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> source.x >> source.y;
        cin >> dest.x >> dest.y;
        int mat[ROW][COL];
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                cin >> mat[i][j];
            }
        }
        int dist = BFS(mat, source, dest);
        if (dist != -1)
            cout << "Shortest Path is " << dist;
        else
            cout << "Shortest Path doesn't exist";
    }
    return 0;
}