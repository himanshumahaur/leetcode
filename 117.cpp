class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        queue<Node*> c;

        if(root) q.push(root);

        while(q.size()) {
            while(q.size()) {
                Node* cur = q.front();
                c.emplace(q.front());
                q.pop();
                if(q.size()) {
                    cur->next = q.front();
                }
                else {
                    cur->next = NULL;
                }
            }
            while(c.size()) {
                if(c.front()->left) q.emplace(c.front()->left);
                if(c.front()->right) q.emplace(c.front()->right);
                c.pop();
            }
        };

        return root;
    }
};