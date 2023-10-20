/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<NestedInteger>::iterator itr;
    vector<NestedInteger>::iterator end;

    stack<vector<NestedInteger>::iterator> stkitr;
    stack<vector<NestedInteger>::iterator> stkend;

    NestedIterator(vector<NestedInteger> &nestedList) {
        itr = nestedList.begin();
        end = nestedList.end();
    }

    int next() {
        int val;

        val = itr->getInteger();
        itr++;

        return val;
    }

    bool hasNext() {
        if(itr!=end) {
            if(itr->isInteger()) {
                return true;
            }
            else {
                stkitr.push(itr);
                stkend.push(end);

                vector<NestedInteger>& tmp = itr->getList();
                itr = tmp.begin();
                end = tmp.end();

                return hasNext();
            }
        }
        else if(!stkitr.empty()) {
            itr = stkitr.top();
            end = stkend.top();

            itr++;

            stkitr.pop();
            stkend.pop();

            return hasNext();
        }
        else {
            return false;
        }

    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */