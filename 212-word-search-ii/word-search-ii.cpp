class Node {
    private:
        Node* links[26];
        bool flag = false;
        bool isWordFound = false;
    
    public:
        bool containsKey(char ch) {
            return (links[ch - 'a'] != nullptr);
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setIsEnd() {
            this -> flag = true;
        }

        bool getIsEnd() {
            return this -> flag;
        }

        void setIsWordFound() {
            this -> isWordFound = true;
        }

        bool getIsWordFound() {
            return this -> isWordFound;
        }
};

class Trie {
    private:
        Node* root;
    
    public:
        Trie() {
            root = new Node();
        }

        Node* getRoot() {
            return this -> root;
        }

        void insert(string &word) {
            Node* node = root;
            for(char &ch: word) {
                if(!node -> containsKey(ch)) {
                    node -> put(ch, new Node());
                }
                node = node -> get(ch);
            }
            node -> setIsEnd();
        }

        void search(int row, int col, vector<vector<int>> &vis, string &str, Node* node, 
            vector<vector<char>> &board, int m, int n, vector<string> &ans) {
            if(node == nullptr) return;
            vis[row][col] = 1;
            str += board[row][col];

            if(node -> getIsEnd() && !node -> getIsWordFound()) {
                ans.push_back(str);
                // This will make sure we aren't inserting duplicate words into our list.
                node -> setIsWordFound();
            }

            int dx[] = {+1, 0, -1, 0};
            int dy[] = {0, -1, 0, +1};

            for(int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];
                if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    char ch = board[x][y];
                    if(node -> containsKey(ch)) {
                        search(x, y, vis, str, node -> get(ch), board, m, n, ans);
                    }
                }
            }

            // While backtracking we need to remove current path traces, so that new valid words can be formed without any restriction.
            str.pop_back();
            vis[row][col] = 0;
        }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string &word: words) trie.insert(word);

        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        vector<string> ans;
        Node* node = trie.getRoot();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(node -> containsKey(board[i][j])) {
                    string str = "";
                    trie.search(i, j, vis, str, node -> get(board[i][j]), board, m, n, ans);
                }
            }
        }

        return ans;
    }
};