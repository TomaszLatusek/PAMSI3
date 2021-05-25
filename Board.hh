

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
    void makeMove(int row, int column, char sign);
    friend class AI;
};
