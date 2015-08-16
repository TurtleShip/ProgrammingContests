public class Board2D {
}

enum Direction {
    N(1, 0), E(0, 1), S(-1, 0), W(0, -1);
    int dr;
    int dc;

    Direction(int dr, int dc) {
        this.dr = dr;
        this.dc = dc;
    }
}


class Position {
    int row;
    int col;
    Direction direction;

    public Position(int row, int col, Direction direction) {
        this.row = row;
        this.col = col;
        this.direction = direction;
    }
}

// this class simulate 2D board
class Board {
    private int R;
    private int C;

    public Board(int R, int C) {
        this.R = R;
        this.C = C;
    }

    /*
        Starting at 'position' Position,
        explores the given sequence, consisting of 'L' (left), 'R' (right), 'F' (forward),
        and returns the final position.
     */
    public Position explore(Position position, String sequence) {
        for (char ch : sequence.toCharArray()) {
            Position next = move(ch, position);
            if (0 <= next.row && next.row < R && 0 <= next.col && next.col < C) {
                position = next;
            } else {
                // do a custom thing when a player goes out of board
                throw new RuntimeException("I fell off the board!");
            }
        }
        return position;
    }

    private Position move(char ch, Position current) {
        if (ch == 'L') { // left
            return new Position(current.row, current.col, turnLeft(current.direction));
        } else if (ch == 'R') { // right
            return new Position(current.row, current.col, turnRight(current.direction));
        } else { // ch == 'F' , forward
            return new Position(current.row + current.direction.dr, current.col + current.direction.dc, current.direction);
        }
    }

    private Direction turnLeft(Direction dir) {
        switch (dir) {
            case N:
                return Direction.W;
            case W:
                return Direction.S;
            case S:
                return Direction.E;
            case E:
                return Direction.N;
            default:
                throw new RuntimeException("WTF");
        }
    }

    private Direction turnRight(Direction dir) {
        switch (dir) {
            case N:
                return Direction.E;
            case E:
                return Direction.S;
            case S:
                return Direction.W;
            case W:
                return Direction.N;
            default:
                throw new RuntimeException("WTF");
        }
    }
}