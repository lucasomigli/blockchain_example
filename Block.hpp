#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "common.hpp"

class Block
{
private:
    int id;
    int value;
    std::shared_ptr<Block> previousBlock = nullptr;
    std::shared_ptr<Block> nextBlock = nullptr;

public:
    Block(const int &val);
    ~Block(){};

    void setNextBlock(Block &block);
    void setPreviousBlock(Block &block);
    Block getNextBlock();
    std::shared_ptr<Block> getNextBlockPtr();
    Block getPreviousBlock();
    bool isLastBlock() const;

    int getValue() const;
    int getID() const;
    void printBlock() const;

    bool genesis = false;
};

Block::Block(const int &val = 0)
{
    value = val;
    if (genesis != true)
    {
        id = rand() * 10 ^ 6;
    }
    else
    {
        id = 0;
    }
};

void Block::setNextBlock(Block &block)
{
    block.setPreviousBlock(*this);
    this->nextBlock = std::make_shared<Block>(block);
};
void Block::setPreviousBlock(Block &block)
{
    this->previousBlock = std::make_shared<Block>(block);
};
Block Block::getNextBlock() { return *nextBlock; };
std::shared_ptr<Block> Block::getNextBlockPtr() { return nextBlock; };
Block Block::getPreviousBlock() { return *previousBlock; };

bool Block::isLastBlock() const
{
    return nextBlock == nullptr && !genesis;
};

int Block::getValue() const { return this->value; };
int Block::getID() const { return this->id; };
void Block::printBlock() const
{
    int prevID = previousBlock != nullptr ? previousBlock->getID() : 0;
    int nextID = nextBlock != nullptr ? nextBlock->getID() : 0;
    std::cout << "Previous Block ID: " << prevID << "; Block ID " << getID()
              << ", value: " << value << std::endl;
};

#endif