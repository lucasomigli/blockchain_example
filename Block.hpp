#ifndef BLOCK.HPP

#include <common.hpp>

class Block
{
private:
    int id;
    int value;
    std::unique_ptr<Block> previousBlock = nullptr;
    std::unique_ptr<Block> nextBlock = nullptr;

public:
    Block(const int &val);
    ~Block(){};

    void setNextBlock(Block &block);
    Block getNextBlock();

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
    this->nextBlock = std::make_unique<Block>(block);
};
Block Block::getNextBlock() { return *nextBlock; };

int Block::getValue() const { return this->value; };
int Block::getID() const { return this->id; };
void Block::printBlock() const
{
    std::cout << "Block n. " << this->getID() << ", value: " << this->getValue() << std::endl;
};

#endif BLOCK.HPP