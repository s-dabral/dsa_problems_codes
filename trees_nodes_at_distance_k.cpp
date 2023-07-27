#include<bits/stdc++.h>
using namespace std;


//Function to calculate nodes which are present at distance k from the given node

/* 
    Approach used:

    -> Firstly, find the parent of all the nodes and push them into a map ds
    -> After then , from the starting node, move in all the 3 directions (ie, left, right and parent) at same time.
    -> While moving, start counter intially from 0
    -> Keep a visited queue to keep track of all the visited nodes.
    -> When counter will be equal to distance k, all the nodes present in the given queue will be the required answer


*/


class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track, target); 
        
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};