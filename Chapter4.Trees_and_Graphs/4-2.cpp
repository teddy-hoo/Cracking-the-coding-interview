/**
 * Chapter 4  --  4.2
 * Given a directed graph, design an algorithm to find out whether there is a
 * route between two nodes.
 */

/**
 * Author: Teddy
 * Date: 28-01-2015 
 */

/**
 * Analysis:
 * DFS solution: recursively search in the graph until the target node is found
 * or all nodes are traveled.
 * BFS solution: general BFS, is beter than DFS, simpler to implement.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Directed Graph
 */
struct DGNode{
    int val;
    vector<DGNode *> neighbors;
    bool visited;
    DGNode(int val): val(val), visited(false) {}
};

/**
 * DFS solution
 */
bool recursion(DGNode *source, int target){

    if(source->val == target){
        return true;
    }
    
    source->visited = true;

    vector<DGNode *> neighbors = source->neighbors;
    for(int i = 0; i < neighbors.size(); i++){
        if(neighbors[i]->visited){
            continue;
        }
        if(recursion(neighbors[i], target)){
            return true;
        }
    }

    return false;

}
bool DFS(DGNode *source, int target){

    if(source == NULL){
        return false;
    }

    return recursion(source, target);
}

bool BFS(DGNode *source, int target){

    if(source == NULL){
        return false;
    }

    queue<DGNode *> q;
    q.push(source);

    while(!q.empty()){
        DGNode *cur = q.front();
        q.pop();
        if(cur->val == target){
            return true;
        }
        cur->visited = true;
        vector<DGNode *> neighbors = cur->neighbors;
        for(int i = 0; i < neighbors.size(); i++){
            if(!neighbors[i]->visited){
                q.push(neighbors[i]);
            }
        }
    }

    return false;
}

/**
 * Main function
 * normal case, edge case.
 * use a graph like below, the "*" denote the direction
 * 1 --* 2 --* 3
 * |     *     |
 * *     |     *
 * 4 --* 5 --* 6
 */

void resetNodes(DGNode *one, DGNode *two, DGNode *three,
                DGNode *four, DGNode *five, DGNode *six){
    one->visited   = false;
    two->visited   = false;
    three->visited = false;
    four->visited  = false;
    five->visited  = false;
    six->visited   = false;
}

int main(){

    DGNode *one   = new DGNode(1);
    DGNode *two   = new DGNode(2);
    DGNode *three = new DGNode(3);
    DGNode *four  = new DGNode(4);
    DGNode *five  = new DGNode(5);
    DGNode *six   = new DGNode(6);

    one->neighbors.push_back(two);
    one->neighbors.push_back(four);
    two->neighbors.push_back(three);
    three->neighbors.push_back(six);
    four->neighbors.push_back(five);
    five->neighbors.push_back(two);
    five->neighbors.push_back(six);

    cout << "DFS result of 1 and 5: " << DFS(one, 5) << endl;
    resetNodes(one, two, three, four, five, six);
    cout << "BFS result of 1 and 5: " << BFS(one, 5) << endl;
    resetNodes(one, two, three, four, five, six);

    cout << "DFS result of 1 and 7: " << DFS(one, 7) << endl;
    resetNodes(one, two, three, four, five, six);
    cout << "BFS result of 1 and 7: " << BFS(one, 7) << endl;
    resetNodes(one, two, three, four, five, six);

    return 0;
}
