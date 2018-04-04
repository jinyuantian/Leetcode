class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0)
                    q.push(make_pair(i, j));
            }
        }
        while(q.size()){
            int n = q.size();
            while(n > 0){
                n--;
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(isValid(rooms, i+1, j)){
                    rooms[i+1][j] = rooms[i][j]+1;
                    q.push(make_pair(i+1, j));
                }
                if(isValid(rooms, i-1, j)){
                    rooms[i-1][j] = rooms[i][j]+1;
                    q.push(make_pair(i-1, j));
                }
                if(isValid(rooms, i, j+1)){
                    rooms[i][j+1] = rooms[i][j]+1;
                    q.push(make_pair(i, j+1));
                }
                if(isValid(rooms, i, j-1)){
                    rooms[i][j-1] = rooms[i][j]+1;
                    q.push(make_pair(i, j-1));
                }
            }
        }
    }

    bool isValid(vector<vector<int>>& rooms, int i, int j){
        return i >=0 && i < rooms.size() && j >=0 && j < rooms[0].size() && rooms[i][j] == INT_MAX;
    }
};

// class Solution {
// public:
//     void wallsAndGates(vector<vector<int>>& rooms) {
//         if(rooms.empty() || rooms[0].empty()) return;
//         int m = rooms.size(), n = rooms[0].size();
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(rooms[i][j] == 0)
//                     paint(rooms, i, j, 0);
//             }
//         }
//     }

//     void paint(vector<vector<int>>& rooms, int i, int j, int dis){
//         if(i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size() || rooms[i][j] == -1 || rooms[i][j] < dis)
//             return;
//         rooms[i][j] = dis;
//         paint(rooms, i, j+1, dis+1);
//         paint(rooms, i, j-1, dis+1);
//         paint(rooms, i+1, j, dis+1);
//         paint(rooms, i-1, j, dis+1);
//     }
// };
