import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import static java.lang.System.out;

public class Game implements WrongInput{
    private int round = 0; 
    private int win = 0;
    private int tries;
    private boolean end =false;
    private String outcome;
    private String keyWord; 
    private String guess;
    private Scanner receiver;
    private List<String> words;
    private List<Color> colors;

    public static void main(String[] args) {
        new Game().start();
    }

    public void start() {
        receiver = new Scanner(System.in);
        while(true){
            round++;       
            initialize();
            for(;tries<6 && !end;){                            
                guess = receiver.nextLine().trim().toLowerCase();
                if(guess != null && guess.length() == 5 && isValid()){
                    tries++;
                    words.add(guess);
                    compare();                                               
                }
                else{               
                    wrongInput();
                }
            }
            if(end()) break;
            
        }
        

    }

    private boolean end() {
        out.println();
        out.println("The answer is \033[32;1m"+keyWord+"\033[0m");
        out.println("you "+outcome+" this round!");
        out.println("you had played "+round+" round");
        out.println("you had winned "+win+" round");
        out.println("press 'r' to continue the game");
        out.println("press any other key to quit the game");
        if(receiver.nextLine().toLowerCase().charAt(0)=='r'){
            return false;
        }
        else{
            out.println("thanks for playing");            
            return true;                       
        }
        
    }

    private void initialize() {
        tries =0;
        guess = null;
        getKeyword();
        end = false;
        outcome ="lose";
        words =new ArrayList<String>();
        colors =new ArrayList<Color>();
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
        keyWord ="yield";
    }

    private void compare() {
        if(guess.equals(keyWord)){
            win++;
            outcome = "win";
            end =true;
        }
        else{
            for(int i=0;i<5;i++){
                char c =guess.charAt(i);
                if( c == keyWord.charAt(i)){
                    colors.add(Color.GREEN);
                }
                else if(keyWord.indexOf(c) != -1){
                    colors.add(Color.YELLOW);
                }
                else{
                    colors.add(Color.GREY);
                }
            }
            for(int i=0;i<tries;i++){
                printGuess(i);
            }
            System.out.print("\033[0m \n");
            out.println("you can try again");

        }
        
                
    }

    private void printGuess(int index) {
        if(words != null && words.size() > index){
                String s = words.get(index);
                out.println();
                for(int j =0;j<5;j++){
                    printWord(colors.get(index*5+j),s.charAt(j));
                    
                }
                // out.println();
                
            }
        }
    
/**
 * pattern 前面的图案 such as "=============="
* 颜色代号：背景颜色代号(41-46)；前景色代号(31-36)
* 数字+m：1加粗；3斜体；4下划线
* 要打印的内容
 * @param color
 * @param c
 */
    private void printWord(Color color, char c) {
        switch(color){
            case GREEN:{
                System.out.print("\033[32;1m" + c); 
                break;
            }
            case YELLOW:{
                System.out.print("\033[33;1m" + c);
                break;
            }
            case GREY:{
                System.out.print("\033[30;1m" + c);
                break;
            }
            
            // 前景色是%d,背景色是%d------\33[%d;%d;4m %n
        }

    }

    /***
     * it can invoke some interface implemented by others to judge whether "guess" is a valid word
     * buti will just return true so far 
     * 
     * @param guess 
     * @return
     */
    private boolean isValid() {
        // if(guess .......)
        return true;
    }

    
}
    