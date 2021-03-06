// ~~ design tic-tac-toe 1 ~~

// 3x3 board, 2 players, symbol -> x or o

// if a player has it's symbol in a continuous row of 3 cells, either horizontal, vertical or diagonal first
// then that player wins.

// step 1: gather concrete requirements

// Players should take turn one after another -> vague (count of players not specified)
// Players take turn -> vague (no information on board, not specified how many turns a player take at a time)
// game either ends in a draw or a win -> vague (condition for draw/win not clearly specified)


// requirements -
// - 3x3 board
// - 2 player to play the game
// - each player makes a turn alternatively
// - either a symbol 'X' or '0' is assigned to a player, and each player needs to have a unique symbol
// associated with them.
// - in every turn a player puts its symbol on the board and fills an empty cell on the board with symbol
// assigned to that player.
// - game termination scenarios -
//     - if board is full then it's a draw
//     - if there is a straight line of 3 cells either vertical, horizontal or diagonal filled with the same
//     symbol, then its a victory, and owner of that symbol is the winner.


// step 2: identification of entities (classes)
// - board
// - player
// - game
// - symbol
// - turn/move

// Note: 'players play game' shows us that game is dependent on players.


// step 3: write a rough code.

//      game (will get everything in motion)
//         /   \
//     player  board
//     /
// symbol

// while we get to writing the actual classes, there are two strategies -
// - top bottom approach (go with this instead)
// - bottom top approach (theoretically looks more practical but it isn't)

// bottom to top is very hard to execute, as many-a-times it happens that top level entities gives us an idea
// about how and what should be in lower level entities but vice versa is very hard to come up with.

public class TicTacToe {
    public static void main(String[] args) {
        Player player1 = new Player('X');
        Player player2 = new Player('0');
        Player currentPlayer = player1;
        Board board = new Board();
        while (!board.isFull()) {
            Move currentMove = currentPlayer.play();
            board.applyMove(currentMove, currentPlayer.getSymbol());
            if (board.hasWinningLine(currentPlayer.getSymbol())) {
                System.out.println("Player with symbol " + currentPlayer.getSymbol() + " Won");
                break;
            }
            if (currentPlayer == player1) currentPlayer = player2;
            else currentPlayer = player1;
        }
        System.out.println('Match drawn');
    }
}

// Move will be a data-class, it will not have any methods other than getters and setters.

// board is a behavior based entity, we need to check it's behavior after every move.

// all this logic is orchestrating our game, main() should not have it. game class should have all this
// and should be responsible to start the game.

public class TicTacToe {
    private final Player player1, player2;
    private final Board board;

    public TicTacToe(Player player1, Player player2, Board board) {
        this.player1 = player1;
        this.player2 = player2;
        this.board = board;
    }

    Result start() {
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

// why i introduced new entity 'Result'

// because our last code was not testable, as our code should be highly testable.

// testable means -

// --i/p--> method --o/p-->

// this process must be testable for every scenario. (the output should match with expected output)

// as main() is not testable (void in nature), to validate if we are getting expected results we felt the
// need to introduce a new entity 'Result'.

public class Result {
    private final boolean isDraw;
    private final Player winner;

    public Result(boolean isDraw, Player winner) {
        this.isDraw = isDraw;
        this.winner = winner;
    }

    public boolean isDraw() {
        return isDraw;
    }

    public Player getWinner() {
        return winner;
    }
}

public class Player {
    private final char symbol;

    public Player(char symbol) {
        this.symbol = symbol;
    }

    public Move play() {
        System.out.println("fetching move from console");
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt(), y = scanner.nextInt();
        return new Move(x, y);
    }

    public char getSymbol() {
        return this.symbol;
    }
}

public class Board {
    private final char[][] board;

    public Board() {
        this.board = new char[3][3];
        for (int i{0}; i<3; i++) {
            for (int j{0}; j<3; j++) {
                this.board[i][j] = '.';
            }
        }
    }

    public void applyMove(Move move, char symbol) {
        this.board[move.getX()][move.getY()] = symbol;
    }

    public boolean isFull() {
        for (int i{0}; i<3; i++) {
            for (int j{0}; j<3; j++) {
                if (this.board[i][j] == '.') return false;
            }
        }
        return true;
    }

    public boolean hasWinningLine(char symbol) {
        return hasHorizontalWinningLine(symbol) || hasVerticalWinningLine(symbol) || hasDiagonalWinningLine(symbol);
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

public class Move {
    private final int x;
    private final int y;

    public Move(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

public class TicTacToeSimulator {
    public static void main(String[] args) {
        TicTacToe tictactoe = new TicTacToe(new Player('X'), new Player('0'), new Board());
        Result result = tictactoe.start();
        if (result.isDraw()) print('match ended in a draw');
        else System.out.println("Player with symbol " + currentPlayer.getSymbol() + " Won");
    }
}

// we haven't covered any validations like -
// - what if player enters already filled cells (applyMove() should have it)
// - what if player enters out of bound cells

// our implementation satisfies
// - single responsibility principle    -> yes
// - open close principle               -> no
// as player class should be extensible to support computer player also.
// because if i want to support different types of players then Player should be a polymorphic type.
// Player should be an interface in that case.

// Next we will see how can we convert our code into an extensible code.
