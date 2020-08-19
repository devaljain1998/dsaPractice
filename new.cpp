#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, k;
    cin >> m >> n >> k;

    queue <pair<int, int> > turtle_positions;
    vector<vector<bool> > counted(m, vector<bool>(n, false));
    set<pair<int, int> > turtle_set;

    vector<vector<int> > grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];

            if(grid[i][j]){
                pair <int, int> pos(i, j);
                turtle_positions.push(pos);
            }
        }
    }

    long int c_turtles = 0;

    while(!turtle_positions.empty()){
        pair <int, int> pos = turtle_positions.front();
        turtle_positions.pop();

        int top_left_i = pos.first-1, top_left_j = pos.second-1; bool top_left_flag = true;
        int top_right_i = pos.first-1, top_right_j = pos.second+1; bool top_right_flag = true;
        int bottom_left_i = pos.first+1, bottom_left_j = pos.second-1; bool bottom_left_flag = true;
        int bottom_right_i = pos.first+1, bottom_right_j = pos.second+1; bool bottom_right_flag = true;

        for(int temp_k = 1; temp_k <= k && (top_left_flag || top_right_flag || bottom_left_flag || bottom_right_flag); temp_k++){
            // if(i<=m-1 && j<=n-1){
            //     if(grid[i][j] && !counted[i][j]){
            //         c_turtles++;
            //         counted[i][j] = true;
            //     }
            // }
            // else
            //     break;

            if(top_left_i >= 0 && top_left_j >= 0 && top_left_flag){
                if(grid[top_left_i][top_left_j] && !counted[top_left_i][top_left_j]){
                    c_turtles++;
                    counted[top_left_i][top_left_j] = true;

                    if(!counted[pos.first][pos.second]){
                        counted[pos.first][pos.second] = true;
                        c_turtles++;}

                }
                top_left_i--, top_left_j--;
            }
            else
                top_left_flag = false;

            


            if(top_right_i >= 0 && top_right_j <= n-1 && top_right_flag){
                if(grid[top_right_i][top_right_j] && !counted[top_right_i][top_right_j]){
                    c_turtles++;
                    counted[top_right_i][top_right_j] = true;

                    if(!counted[pos.first][pos.second]){
                        counted[pos.first][pos.second] = true;
                        c_turtles++;}

                }
                top_right_i--, top_right_j++;
            }
            else
                top_right_flag = false;

            


            if(bottom_left_i <= m-1 && bottom_left_j >= 0 && bottom_left_flag){
                if(grid[bottom_left_i][bottom_left_j] && !counted[bottom_left_i][bottom_left_j]){
                    c_turtles++;
                    counted[bottom_left_i][bottom_left_j] = true;

                    if(!counted[pos.first][pos.second]){
                        counted[pos.first][pos.second] = true;
                        c_turtles++;}

                }
                bottom_left_i++, bottom_left_j--;
            }
            else
                bottom_left_flag = false;

            


            if(bottom_right_i <= m-1 && bottom_right_j <= n-1 && bottom_right_flag){
                if(grid[bottom_right_i][bottom_right_j] && !counted[bottom_right_i][bottom_right_j]){
                    c_turtles++;
                    counted[bottom_right_i][bottom_right_j] = true;

                    if(!counted[pos.first][pos.second]){
                        counted[pos.first][pos.second] = true;
                        c_turtles++;}

                }
                bottom_right_i++, bottom_right_j++;
            }
            else
                bottom_right_flag = false;

            

        }
    }

    cout << c_turtles << "\n";

    return 0;
}


/*

struct Node {
    char key;
    Node *left, *right;

    Node(char ch) {
        this.key = ch;
        this.left = this.right = NULL;
    }
}

class BSTOfCharacter {
private:
    Node *root = NULL;
public:
    //Constructor:
    BSTOfCharacter(): {}
    BSTOfCharacter(char ch): root(ch) {}


    bool insert(char ch, Node* current) {

        if (root == nullptr) {
            this->root = new Node(ch);
        } else {
            this->Insert(ch, this->root);
        }
    }

    void Insert(int val, TreeNode*& node) {

        if(val <= node->data){
            if(node->left == nullptr){
                // Make a new node as the left child of this node
                node->left = new Node(val);
            } else{
                // Recursively call Insert() on this node's left child
                this->Insert(val, node->left);
            }
        } else{
            if(node->right == nullptr){
                // Make a new node as the right child of this node
                node->right = new Node(val);
            } else{
                // Recursively call Insert() on this node's right child
                this->Insert(val, node->right);
            }
        }
    }

    void printTree() {
        if (root == NULL) {
            return;
        } else {
            stack <Node*> s(root);

            vector<Node*> node;
            //Loop untill the stack is empty
            while(!s.empty()) {
                top = s.top();
                if (top->left == NULL && top->right == NULL) {
                    nodes.push_back(top);
                    s.pop();
                }
                if (top->right)
                    s.push(s->right)
                if (top->left)
                    s.push(s->left)
            }

            for (auto node : nodes) {
                cout << node->key << " ";
            }
        }
    }



};

*/