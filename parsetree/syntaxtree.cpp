 #include <vector>
 #include "syntaxtree.h"

SyntaxTree::SyntaxTree() {
    head = new Node();
    curNode = head;
    size = 0;
}

void SyntaxTree::startExpression() {
    curNode = curNode->addChild(NULL);
}

void SyntaxTree::addTerminal(Token* token) {
    curNode->addChild(token);
    size++;
}

void SyntaxTree::endExpression() {
    curNode = curNode->getParent();
}

TreeIterator::TreeIterator (SyntaxTree* t) {
    tree = t;
    iter = tree->head;
    curLevel = 0;
    indices.push_back(0);
    lastFlag = false;
}

Token* TreeIterator::getPostorder() {
    return NULL;
}

Token* TreeIterator::getPreorder() {
    // lastFlag is a flag that is used so getCurrentLevel returns the
    // correct level. This is necessary because if we just read the last
    // child of the node iter is pointing to, iter gets moved up a level
    // and curLevel gets decremented. However, the actual level we were on
    // doesn't change until NEXT time through. See how this is used in the
    // getCurrentLevel() method in the .h file.
    lastFlag = false;

    // If there are no nodes in the tree or the head node is a terminal,
    // something is wrong. Just return null. Also will fail when we are done
    // with the traversal.
    if(iter != NULL && iter->getData() == NULL) {
        Node* child = iter->getChild(indices.back());
        // If getData() doesn't return null, we have a leaf node with actual
        // data to return.
        if(child->getData() != NULL) {
            Token* ret = child->getData();

            // Now we have use a stack to keep track of all the indices in the
            // children arrays of all the nodes we are at. If we had a normal
            // traversal function that did something to every node, we would not
            // need such a stack. However, since we are returning nodes one at a
            // time, we need to keep track of "where we are" on each node's children.

            // Increment top of stack so we will return next child next time.
            int back = indices.back();
            indices.pop_back();
            indices.push_back(back + 1);

            // If we are returning the last child of the current node, we are done with
            // this branch and need to move the iterator up a level to keep going with
            // the traversal.
            if(indices.back() >= iter->getNumChildren()) {
                indices.pop_back();
                int back = indices.back();
                indices.pop_back();
                indices.push_back(back + 1);
                iter = iter->getParent();
                curLevel--;
                // special case where we don't want curLevel to "actually" go up till next time
                lastFlag = true;
            }
            return ret;
        }
        // We are on on interior node, so move down a level and try again to
        // find a leaf.
        else {
            indices.push_back(0);
            iter = child;
            curLevel++;
            return getPreorder();
        }
    }
    return NULL;
}

void TreeIterator::reset() {
    iter = tree->head;
    curLevel = 0;
}

Node::Node() {
    parent = NULL;
    data = NULL;
    numChildren = 0;
}

Node::Node(Token* tok, Node* par) {
    parent = par;
    data = tok;
    numChildren = 0;
}

Node* Node::addChild(Token* tok) {
    Node* newNode = new Node(tok, this);
    children.push_back(newNode);
    numChildren++;
    return newNode;
}
