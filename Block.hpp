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
    Block getPreviousBlock();

    int getValue() const;
    int getID() const;
    void printBlock() const;
};

Block::Block(const int &val = 0) : value(val)
{
    this->id = previousBlock->getID() + 1;
};

void Block::setNextBlock(Block &block)
{
    this->nextBlock = std::make_shared<Block>(block);
};
void Block::setPreviousBlock(Block &block)
{
    this->previousBlock = std::make_shared<Block>(block);
};
Block Block::getNextBlock() { return *nextBlock; };
Block Block::getPreviousBlock() { return *previousBlock; };

int Block::getValue() const { return this->value; };
int Block::getID() const { return this->id; };
void Block::printBlock() const
{
    std::cout << "Block n. " << this->getID() << ", value: " << this->getValue() << std::endl;
};

#endif