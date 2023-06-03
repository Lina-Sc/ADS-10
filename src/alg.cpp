// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int n) {
    if (n > 1)
      return n * fact(n - 1);
    return 1;
}
std::vector<char> getPerm(const Tree& tree, int n) {
    if (tree.getSize() == 0 || n > fact(tree.getSize()))
        return {};
    if (tree.getCharacter_set() == '*')
        n--;
    std::vector<char> res;
    int temp = fact(tree.getSize() - 1);
    res.push_back(tree[n / temp].getCharacter_set());
    std::vector<char> c = getPerm(tree[n / temp], n % temp);
    res.insert(res.end(), c.begin(), c.end());
    return res;
}
