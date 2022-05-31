import java.util.ArrayList;

import java.util.List;
import java.util.Scanner;

import static java.lang.System.out;

public class Game implements WrongInput {
    private int round = 0;
    private int win = 0;
    private int tries;
    private boolean end = false;
    private String outcome;
    private String keyWord;
    private String guess;
    private Scanner receiver;
    private List<String> words;
    private List<Color> colors;

    public static void main(String[] args) {
        new Game().start();
    }

    /**
     * start the game
     * recieve the input and store it
     * send it to compare()
     */
    public void start() {
        receiver = new Scanner(System.in);
        while (true) {
            round++;
            initialize();
            for (; tries < 6 && !end;) {
                guess = receiver.nextLine().trim().toLowerCase();
                if (guess != null && guess.length() == 5 && isValid()) {
                    tries++;
                    words.add(guess);
                    compare();
                } else {
                    wrongInput();
                }
            }
            if (end())
                break;

        }

    }

    /**
     * print the info of all tries
     * 
     * @return used to deside whether continue or not
     */
    private boolean end() {
        out.println();
        out.println("The answer is \033[32;1m" + keyWord + "\033[0m");
        out.println("you " + outcome + " this round!");
        out.println("you had played " + round + " round");
        out.println("you had winned " + win + " round");
        out.println("press 'r' to continue the game");
        out.println("press any other key to quit the game");
        if (receiver.nextLine().toLowerCase().charAt(0) == 'r') {
            return false;
        } else {
            out.println("thanks for playing");
            return true;
        }

    }

    /**
     * to reset the params
     * 
     */
    private void initialize() {
        tries = 0;
        guess = null;
        getKeyword();
        end = false;
        outcome = "lose";
        words = new ArrayList<String>();
        colors = new ArrayList<Color>();
        out.println("now you can start the guess!");
    }

    /**
     * later we can get the word by invoking others interface
     * to get a random valid key word
     * but now we just ues a word to test the function
     * 
     * 
     */
    private void getKeyword() {
        keyWord = "yield";
    }

    /**
     * compare the guess word and the key word
     * then call the printguess() to print the feedback
     */
    private void compare() {
        if (guess.equals(keyWord)) {
            win++;
            outcome = "win";
            end = true;
        } else {
            for (int i = 0; i < 5; i++) {
                char c = guess.charAt(i);
                if (c == keyWord.charAt(i)) {
                    colors.add(Color.GREEN);
                } else if (keyWord.indexOf(c) != -1) {
                    colors.add(Color.YELLOW);
                } else {
                    colors.add(Color.GREY);
                }
            }
            for (int i = 0; i < tries; i++) {
                printGuess(i);
            }
            System.out.print("\033[0m \n");
            out.println("you can try again");

        }

    }

    /**
     * print the word
     * 
     * @param index the num of the word
     */
    private void printGuess(int index) {
        if (words != null && words.size() > index) {
            String s = words.get(index);
            out.println();
            for (int j = 0; j < 5; j++) {
                printWord(colors.get(index * 5 + j), s.charAt(j));

            }
            // out.println();

        }
    }

    /**
     * use \033 to change the type of print
     * pattern [
     * color num : background(41-46), foreground(31-36)
     * 1: bold 3:cross 4:underline
     * %d,%d------\33[%d;%d;4m %n
     * 
     * @param color
     * @param c
     */
    private void printWord(Color color, char c) {
        switch (color) {
            case GREEN: {
                System.out.print("\033[32;1m" + c);
                break;
            }
            case YELLOW: {
                System.out.print("\033[33;1m" + c);
                break;
            }
            case GREY: {
                System.out.print("\033[30;1m" + c);
                break;
            }

        }

    }

    /***
     * it can invoke some interface implemented by others to judge whether "guess"
     * is a valid word
     * but for now i will just return true
     * 
     * @param guess
     * @return
     */
    private boolean isValid() {
        // if(guess .......)
        return true;
    }

}
