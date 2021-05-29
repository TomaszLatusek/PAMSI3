

class Board
{
private:
    int size;
    int inRowToWin;
    char **fields;

public:
    Board(int size, int inRowToWin);
    ~Board();
    void print();
    void init();
    void makeMove(int row, int column, char sign);
    int getSize() { return size; };
    bool isFieldEmpty(int i, int j);
    friend class AI;
};
