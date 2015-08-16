import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// UVa 118 - Mutant Flatworld Explorers
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=54
public class Main {

    public static void main(String[] args) {
        final Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(System.out));

        int C = scanner.nextInt();
        int R = scanner.nextInt();
        final World world = new World(R+1, C+1);

        while (scanner.hasNext()) {
            C = scanner.nextInt();
            R = scanner.nextInt();
            char ch = scanner.next().charAt(0);
            Direction dir;
            switch (ch) {
                case 'N':
                    dir = Direction.N;
                    break;
                case 'E':
                    dir = Direction.E;
                    break;
                case 'S':
                    dir = Direction.S;
                    break;
                default: // 'W'
                    dir = Direction.W;
                    break;
            }
            final Position start = new Position(R, C, dir);
            final String sequence = scanner.next();
            final Position result = world.explore(start, sequence);
            writer.printf("%d %d %s", result.col, result.row, result.direction);
            if (result.isLost) {
                writer.print(" LOST");
            }
            writer.println();
        }
        writer.flush();
    }
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
    boolean isLost;

    public Position(int row, int col, Direction direction) {
        this.row = row;
        this.col = col;
        this.direction = direction;
        this.isLost = false;
    }
}

class World {
    private int R;
    private int C;
    // isDanger[r][c] = true if a bot fell of at this spot.
    private boolean[][] isDanger;

    public World(int R, int C) {
        this.R = R;
        this.C = C;
        this.isDanger = new boolean[R][C];
        for (int i = 0; i < R; i++)
            Arrays.fill(isDanger[i], false);
    }

    public Position explore(Position position, String sequence) {
        for (char ch : sequence.toCharArray()) {
            Position next = move(ch, position);
            if (0 <= next.row && next.row < R && 0 <= next.col && next.col < C) {
                position = next;
            } else {
                if (!isDanger[position.row][position.col]) {
                    /*
                     No bot has fallen here before. We cannot ignore the current instruction.
                     Mark this spot before falling.
                    */
                    isDanger[position.row][position.col] = true;
                    position.isLost = true;
                    return position;
                }
            }
        }
        return position;
    }

    private Position move(char ch, Position current) {
        if (ch == 'L') {
            return new Position(current.row, current.col, turnLeft(current.direction));
        } else if (ch == 'R') {
            return new Position(current.row, current.col, turnRight(current.direction));
        } else { // ch == 'F'
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