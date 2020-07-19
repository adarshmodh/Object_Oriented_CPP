/*
    queue = []
    queue.append((sr, sc, 0))
    seen = set()
    seen.add((sr, sc))

    while queue:
        r, c, depth = queue.pop()
        if r == tr and c == tc: return depth
        for (nr, nc) in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
            if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] == 1 and (nr, nc) not in seen:
                queue.append((nr, nc, depth + 1))
                seen.add((nr, nc))
    return -1
*/

#include <iostream>
#include <vector>
#include <queue> 
#include <unordered_set> 


using namespace std;

int shortestCellPath(vector<vector<int>>& grid, int sr, int sc, int tr, int tc)
{
  int row = grid.size();
  int col = grid[0].size();
  
  queue<pair<int, int>> q;
  q.push(make_pair(sr,sc));
  vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
  
  while(!q.empty()){
      auto curr = q.front();
      int x = curr.first, y = curr.second;
      
      if( x == tr && y == tc) 
        return grid[x][y]-1;
      
      for(auto direction : directions){
          int nx = x + direction[0];
          int ny = y + direction[1];
          if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1){
              q.push(make_pair(nx,ny));
              grid[nx][ny] = grid[x][y] + 1;
          }
      }
      q.pop();
  }

  return -1;
}


int main() 
{
  vector<vector<int> > grid{ { 1, 1, 1, 1 }, 
                             { 0, 0, 0, 1 }, 
                             { 1, 0, 1, 1 } };

  int sr = 0, sc = 0, tr = 2, tc = 0;
  int output = shortestCellPath(grid, sr,sc,tr,tc);
  cout << output << endl;
	return 0;
}
