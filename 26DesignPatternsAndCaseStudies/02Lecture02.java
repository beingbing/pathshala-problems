// ~~ design tic-tac-toe 2 ~~

// class diagram: create boxes for entities and show the relationship between them using arrows.

/*

                             TicTacToe
                           / |      |   \
                          /  |      |    \
                         ↓   |      ↓     ↓
                    Result---|--→Player  Board
                             |   /      /
                             |  /      /
                             ↓ ↓      /
                             Move    ↩

*/

// always go for class diagram after covering all the steps thought in lecture 1.

// by drawing this diagram we can clearly see as why top-bottom approach is simpler, as going from
// bottom-top it's hard to come up with all we need and dependencies between classes.

// in last class, we established that our design is not abiding by OCP.

// extension means: identifying the entities which can behave differently when extended and write them
// accordingly so that when we extend it in future, the extension can be done easily and without any
// hassle.

// but we are also not following DIP (dependencies inversion principle)
// it says, high level classes should depend on abstraction and not on concretion.
// here,
// Move being a concrete class is understandable as it is a data class which definitely won't change.
// but,
// something which you know might change frequently in future, should depend upon its abstraction
// rather than its concrete implementation.

// so now we will be working on creating an interface for classes which can be extended.

// first of all we will try to create interface out of Player class.

// while creating an interface we are actually defining a contract.
// contract means that any class which wishes to implement that interface must have the mentioned
// methods inside it.

public interface Player {
    Move play();

    char getSymbol();
}

public class HumanPlayer implements Player {
    private final char symbol;

    public HumanPlayer(char symbol) {
        this.symbol = symbol;
    }

    @Override
    public Move play() {
        System.out.println("fetching move from console");
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt(), y = scanner.nextInt();
        return new Move(x, y);
    }

    @Override
    public char getSymbol() {
        return this.symbol;
    }
}

public class ComputerPlayer implements Player {
    private final char symbol;

    public ComputerPlayer(char symbol) {
        this.symbol = symbol;
    }

    @Override
    public Move play() {
        int x = (int)Math.random(), y = (int)Math.random();
        return new Move(x%3, y%3);
    }

    @Override
    public char getSymbol() {
        return this.symbol;
    }
}

public class TicTacToeSimulator {
    public static void main(String[] args) {
        TicTacToe tictactoe = new TicTacToe(new HumanPlayer('X'), new ComputerPlayer('0'), new Board());
        Result result = tictactoe.start();
        if (result.isDraw()) print('match ended in a draw');
        else System.out.println("Player with symbol " + currentPlayer.getSymbol() + " Won");
    }
}

// the above implementation makes TicTacToe class highly robust in terms of what type of players are playing
// the game.

// now our implementation follows OCP and DIP.

// what if we have a requirement where we want an nxn board.
// for this,

public interface Board {
    void applyMove(Move move, char symbol);
    boolean isFull();
    boolean hasWinningLine(char symbol);
    int getDimension();     // it will make validation check for invalid x and y easy
}

public class GeneralBoard implements Board {
    private final char[][] board;

    public GeneralBoard() {
        this.board = new char[3][3];
        for (int i{0}; i<3; i++) {
            for (int j{0}; j<3; j++) {
                this.board[i][j] = '.';
            }
        }
    }

    @Override
    public void applyMove(Move move, char symbol) {
        this.board[move.getX()][move.getY()] = symbol;
    }

    @Override
    public boolean isFull() {
        for (int i{0}; i<3; i++) {
            for (int j{0}; j<3; j++) {
                if (this.board[i][j] == '.') return false;
            }
        }
        return true;
    }

    @Override
    public boolean hasWinningLine(char symbol) {
        return hasHorizontalWinningLine(symbol) || hasVerticalWinningLine(symbol) || hasDiagonalWinningLine(symbol);
    }

    @Override
    public int getDimension() {
        return this.board.length;
    }

    private boolean hasHorizontalWinningLine(char symbol) {
        for (int i{0}; i<3; i++) {
            if (this.board[i][0] == symbol && this.board[i][1] == symbol && this.board[i][2] == symbol) return true;
        }
        return false;
    }

    private boolean hasVerticalWinningLine(char symbol) {
        for (int i{0}; i<3; i++) {
            if (this.board[0][i] == symbol && this.board[1][i] == symbol && this.board[2][i] == symbol) return true;
        }
        return false;
    }

    private boolean hasDiagonalWinningLine(char symbol) {
        return (this.board[0][0] == symbol && this.board[1][1] == symbol && this.board[2][2] == symbol)
            || (this.board[0][2] == symbol && this.board[1][1] == symbol && this.board[2][0] == symbol);
    }
}

public class CustomBoard implements Board {
    private final char[][] board;

    public CustomBoard(int n) {
        this.board = new char[n][n];
        for (int i{0}; i<n; i++) {
            for (int j{0}; j<n; j++) {
                this.board[i][j] = '.';
            }
        }
    }

    @Override
    public void applyMove(Move move, char symbol) {
        this.board[move.getX()][move.getY()] = symbol;
    }

    @Override
    public boolean isFull() {
        for (int i{0}; i<3; i++) {
            for (int j{0}; j<3; j++) {
                if (this.board[i][j] == '.') return false;
            }
        }
        return true;
    }

    @Override
    public boolean hasWinningLine(char symbol) {
        return hasHorizontalWinningLine(symbol) || hasVerticalWinningLine(symbol) || hasDiagonalWinningLine(symbol);
    }

    @Override
    public int getDimension() {
        return this.board.length;
    }

    private boolean hasHorizontalWinningLine(char symbol) {
        for (int i{0}; i<3; i++) {
            if (this.board[i][0] == symbol && this.board[i][1] == symbol && this.board[i][2] == symbol) return true;
        }
        return false;
    }

    private boolean hasVerticalWinningLine(char symbol) {
        for (int i{0}; i<3; i++) {
            if (this.board[0][i] == symbol && this.board[1][i] == symbol && this.board[2][i] == symbol) return true;
        }
        return false;
    }

    private boolean hasDiagonalWinningLine(char symbol) {
        return (this.board[0][0] == symbol && this.board[1][1] == symbol && this.board[2][2] == symbol)
            || (this.board[0][2] == symbol && this.board[1][1] == symbol && this.board[2][0] == symbol);
    }
}

// it is obvious that we can not foresight all the upcoming extension but still we should write our code in a way
// that we leave scope for some of the generic extensions which we know that might come in future.

public class TicTacToeSimulator {
    public static void main(String[] args) {
        TicTacToe tictactoe = new TicTacToe(new HumanPlayer('X'), new ComputerPlayer('0'), new CustomBoard(9));
        Result result = tictactoe.start();
        if (result.isDraw()) print('match ended in a draw');
        else System.out.println("Player with symbol " + currentPlayer.getSymbol() + " Won");
    }
}

// here we can see that TicTacToe class is no more capable of only playing tictactoe to two player,
// it can now orchestrate any two player board game with alternate attempts. so, why not we change its name
// from TicTacToe -> TwoPlayerBoardGame 

// when you see that you are needing different data classes implementation of same class for different
// requirements then go for Generics

// Note: explore Generics in java

public interface Game {
    Result start();
}

public class TwoPlayerBoardGame implements Game { 
    @Override
    public Result start() { 
        Player currentPlayer = this.player1;
        while (!this.board.isFull) {
            Move currentMove = currentPlayer.play();
            this.board.applyMove(currentMove, currentPlayer.getSymbol());
            if (this.board.hasWinningLine(currentPlayer.getSymbol())) {
                System.out.println("Player with symbol " + currentPlayer.getSymbol() + " Won");
                return new Result(false, currentPlayer);
            }
            if (currentPlayer == player1) currentPlayer = player2;
            else currentPlayer = player1;
        }
        return new Result(true, null);
     }
}

// now we can change TicTacToeSimulator -> GameSimulator

public class GameSimulator {
    public static void main(String[] args) {
        Game tictactoe = new TicTacToe(new HumanPlayer('X'), new ComputerPlayer('0'), new CustomBoard(9));
        Result result = tictactoe.start();
        if (result.isDraw()) print('match ended in a draw');
        else System.out.println("Player with symbol " + currentPlayer.getSymbol() + " Won");
    }
}

// now tictactoe game depends on abstraction Player and Board, which in return has concrete implementation
// and as now there is no direct link between tictactoe and move, hence we can say that DIP is also followed.

// a part of new class diagram (after we introduced changes to follow all design principles)

/*

                        TicTacToe
                        |     \
                        |      \
                        ↓       ↓
                    Player      Board
                ↗        ↑
            Human      computer
            Player     player
*/
