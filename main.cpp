#include "common.hpp"
#include "Blockchain.hpp"

void print(std::string s)
{
    std::cout << s << std::endl;
};

int main()
{
    print("Blochchain is instantiated.");
    Blockchain *bc = new Blockchain();

    //random creation of a vector of values
    std::vector<int> v{247, 135, 356, 435, 524365, 543426, 6892, 43, 2, 22, 3425, 46};

    print("Iterate trough the blockchain and create new nodes.");
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        Block b(*it);
        bc->pushBlock(b);
    };

    bc->printBlockChain();
};