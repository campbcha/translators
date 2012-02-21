#ifndef SYNTAX_TREE_H
#define SYNTAX_TREE_H

#include <vector>
#include "../lexer/token.h"

/*
This class represents a syntax tree. It has two major functions:

1. You can add tokens to the tree in an preorder fashion. You do this by recursively
adding new expressions as you encounter them and also adding terminals as you
encounter them. For example, say you wanted to create the tree for (+ (* 1 2) 3):

   ...e...
  / / \ \ \
 ( +   e 3 )
    / / \ \ \
   ( *   1 2 )

To add this tree, do the following:
startExpression();
addTerminal(new Token(TAG_OPENPAREN));
addTerminal(new Token(TAG_ADD));
startExpression();
addTerminal(new Token(TAG_OPENPAREN));
addTerminal(new Token(TAG_MULT));
addTerminal(new TypeToken<int>(TAG_INT_LIT, 1));
addTerminal(new TypeToken<int>(TAG_INT_LIT, 2));
addTerminal(new Token(TAG_CLOSEPAREN));
endExpression();
addTerminal(new TypeToken<int>(TAG_INT_LIT, 3));
addTerminal(new Token(TAG_CLOSEPAREN));
endExpression();

2. You can retrieve the tokens in the tree in preorder by creating a TreeIterator class and
passing in the address of your tree. Then you can get the tokens out of the tree by repeatably
calling getPreorder(). This will return null when there are no more tokens left. After this,
you can call reset() to reset the iterator.
*/

// Forward declarations for the SyntaxTree class.
class Node;
class TreeIterator;

class SyntaxTree {
public:
    SyntaxTree();

    // See comments at start of file for how to use these.
    void startExpression();
    void addTerminal(Token* token);
    void endExpression();

    // In C++, friends have full access to your private members.
    // Yes, I know, this is a very standard C++ joke.
    friend class TreeIterator;

private:
    Node* head;     // Head node (top node in tree)
    Node* curNode; // Internal pointer, used to keep track of where to add new nodes.
    int size;      // Current total size of tree.
};

// Iterator for retreiving nodes from a tree in order.
class TreeIterator {
public:
    // Pass in address of tree to constructor.
    TreeIterator(SyntaxTree* t);

    // Get next token in postorder. NOTE: Not implemented yet; will return NULL.
    Token* getPostorder();
    // Get next token in preorder. Returns NULL when there are no more tokens available.
    Token* getPreorder();
    // Get the current "level" of the interator, i.e. number of tree levels below the head.
    int getCurrentLevel() { return lastFlag ? curLevel + 1 : curLevel; } // for printing
    // Reset iterator to start.
    void reset();

private:
    SyntaxTree* tree;
    Node* iter;
    int curLevel;
    std::vector<int> indices; // stack for keeping track of stuff
    bool lastFlag;            // helps getCurrentLevel to return right thing
};

// This is a node inside a SyntaxTree. Should never be instantiated by user.
class Node {
public:
    // Create node with NULL for parent and value.
    Node();
    Node(Token* tok, Node* par = NULL);

    // Add child to node with token value "token".
    Node* addChild(Token* token);

    Token* getData() { return data; }
    Node* getParent() { return parent; }
    int getNumChildren() { return numChildren; }
    Node* getChild(int n) { return children[n]; }

private:
    Node* parent;
    std::vector<Node*> children;
    Token* data;
    int numChildren;
};

#endif
