class Solution {
public:
    int ROW; 
    int COL;
    vector<vector<int>> directions = {
        {-1,0},{0,1},{1,0},{0,-1}  
    };
    bool DFS(vector<vector<int>>& grid, int row, int col){
        if(row<0 || row>=ROW || col<0 || col>=COL || grid[row][col] == 1){
            return false;
        }
        if(row == ROW-1){
            return true;
        }
        grid[row][col] = 1;
        for(auto &dir : directions){
            int new_row = dir[0]+row;
            int new_col = dir[1]+col;
            if(DFS(grid,new_row,new_col)){
                return true;
            }
        }
        return false;
    };
    bool canCross(vector<vector<int>>& cells, int mid){
        // make a grid and fill with water till day = mid and then run dfs/bfs for every col in 0th row until you reach to the bottom of the grid i.e last row 
        vector<vector<int>> grid(ROW,vector<int>(COL));
        // filling with water = 1
        for(int i=0; i<=mid; i++){
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }
        // now run dfs or bfs for all the cols in top 0th row until you reavh the bottom
        for(int j=0; j<COL; j++){
            if(grid[0][j] == 0 && DFS(grid, 0, j)){
                return true;
            } 
        }
        return false;
    };
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;  
        int l = 0;
        int r = cells.size()-1;
        int lastDay = 0;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(canCross(cells,mid)){
                lastDay = mid+1;
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return lastDay;
    };
};