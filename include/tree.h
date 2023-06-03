// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class Tree {
 public:
    explicit Tree(const std::vector<char>& row) {
        option = new Node;
        option->character_set = '*';
        produce(row);
    }
    Tree& operator[](int n) const {
        return *option->options[n];
    }
    char getCharacter_set() const {
        return option->character_set;
    }
    int getSize() const {
        return option->options.size();
    }

 private:
    struct Node {
    char character_set;
    std::vector<Tree*> options;
    };
    Node* option;
    explicit Tree(char character_set) {
        option = new Node;
        option->character_set = character_set;
    }
    void produce(const std::vector<char>& row) {
        for (int q = 0; q < row.size(); q++) {
            std::vector<char> temp = row;
            option->options.push_back(new Tree(temp[q]));
            temp.erase(temp.begin() + q);
            option->options[q]->produce(temp);
        }
    }
};

#endif  // INCLUDE_TREE_H_
