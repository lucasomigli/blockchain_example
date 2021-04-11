#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "common.hpp"
#include "Block.hpp"

class Blockchain
{
private:
    std::vector<std::shared_ptr<Block>> blockchain;

public:
    Blockchain(const int &val);
    ~Blockchain(){};

    int getSize() const;

    int getLatestBlockID() const;
    int getLatestBlockValue() const;
    Block getLatestBlock() const;
    Block getBlockAt(int id) const;

    void pushBlock(Block &block);
    void insertBlock(Block &block, int index);
    void deleteBlockID(int id);
    void deleteBlockAt(int index);

    void printBlockChain() const;
    void printBlockChain(int index) const;
};

Blockchain::Blockchain(const int &val)
{
    Block *genesis;
    std::shared_ptr<Block> p(genesis);
    blockchain.push_back(p);
};

int Blockchain::getSize() const { return blockchain.size(); };

int Blockchain::getLatestBlockID() const
{
    return this->blockchain[getSize() - 1]->getID();
};

int Blockchain::getLatestBlockValue() const
{
    return this->blockchain[getSize() - 1]->getValue();
};

Block Blockchain::getLatestBlock() const
{
    return *(blockchain[getSize() - 1]);
};

Block Blockchain::getBlockAt(int id) const
{
    for (int i = 0; i < blockchain.size(); i++)
    {
        if (blockchain[i]->getID() == id)
        {
            return *(blockchain[i]);
        }
    }
    throw "Index does not exist.";
};

void Blockchain::pushBlock(Block &block)
{
    Block latest = getLatestBlock();
    block.setPreviousBlock(latest);
    latest.setNextBlock(block);
}
void Blockchain::insertBlock(Block &block, int index)
{
    try
    {
        Block tmp = (blockchain[index]->getNextBlock());
        blockchain[index]->setNextBlock(block);
        tmp.setPreviousBlock(block);
        block.setNextBlock(tmp);
        block.setPreviousBlock(*blockchain[index]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
};
void Blockchain::deleteBlockID(int id)
{
    for (int i = 0; i < blockchain.size(); i++)
    {
        if (blockchain[i]->getID() == id)
        {
            blockchain[i - 1]->setNextBlock(*(blockchain[i + 1]));
            (blockchain[i + 1])->setPreviousBlock(*blockchain[i - 1]);
            blockchain.erase(blockchain.begin() + i);
        }
    }
    throw "Index does not exist.";
};
void Blockchain::deleteBlockAt(int index)
{
    if (blockchain.size() > index)
    {
        blockchain[index - 1]->setNextBlock(*(blockchain[index + 1]));
        (blockchain[index + 1])->setPreviousBlock(*blockchain[index - 1]);
        blockchain.erase(blockchain.begin() + index);
    }
    else
    {
        throw "Index does not exist.";
    }
};

void Blockchain::printBlockChain() const
{
    std::cout << "----------------Blockchain starts----------------" << std::endl;
    for (int i = 0; i < blockchain.size(); i++)
    {
        blockchain[i]->printBlock();
    }
    std::cout << "----------------Blockchain ends----------------" << std::endl;
};
void Blockchain::printBlockChain(int index) const
{
    std::cout << "----------------Blockchain starts----------------" << std::endl;
    for (int i = 0; i < index; i++)
    {
        blockchain[i]->printBlock();
    }
    std::cout << "----------------Blockchain Uo to index ends----------------" << std::endl;
};

#endif