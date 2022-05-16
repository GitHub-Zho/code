import static java.lang.System.out;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;


/**
 * All infor about the game 
 * like the rank, the author
 */
public class Wordle implements WrongInput{
    private static ArrayList<String> rank;
    private int round;
    private int fastone;
    private String player;

    public static void main(String[] args) {
        new Wordle().start();
    }


    
/**
 * into the game
 */
    public void start() {
        while(true){
            rules();
        Scanner receiver = new Scanner(System.in);
        String in =receiver.nextLine();
        if( in.length() == 1 && in.toLowerCase().charAt(0) == 'j'){          
                newGame();
                break;
            
        }
        else{
            wrongInput();          
            }
        }
        
    }

    /**
     * creat a game class
     */
    private void newGame(){
        Game aGame = new Game();
        aGame.start();
    }

    /**
     * print the rules of the game
     */
    private static void rules() {
        out.println();
        out.println("welcome to our wordle game!");
        out.println("the rules are as follow:");
        out.println("An English word consisting of five letters is selected at random");
        out.println("You will have 6 guesses in total to discover the target word.");
        out.println("There are three colours that the cells containing the letters can be; green, yellow, or grey.");
        out.println("1. Green means the letter is contained in the word and is in that position.");
        out.println("2. Yellow means the letter is contained in the word but not in that position.");
        out.println("3. Grey means the letter is not contained in the word.");
        out.println();
        out.println("Now ,press 'J' to start the game!");
    }

    
}
