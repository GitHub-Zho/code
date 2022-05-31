import javax.swing.*;
import javax.swing.border.EmptyBorder;

// import java.awt.event.Flow;
import java.awt.*;
import java.awt.event.*;

/**
 * the frame to play the game
 * 
 */
public class GameFrame extends JFrame implements Initial, KeyListener {
    /**
     * the father console
     */
    private GameConsole gameConsole;
    /**
     * the wordtest class
     */
    private WordTest wordTest;
    /**
     * winning times
     */
    private int win;
    /**
     * tries in one round
     */
    private int tries;
    /**
     * word player input
     */
    private String guess;
    /**
     * textfield
     */
    private JTextField inputField;
    // private JLabel[] lables = new JLabel[6];
    /**
     * labelss to show the words
     */
    private JLabel[] words = new JLabel[30];
    // private JPanel[] panels = new JPanel[6];
    /**
     * the font of words
     */
    private Font fWord = new Font(Font.SANS_SERIF, Font.BOLD, 20);

    /**
     * set the frame and bind the constraint
     */

    GridBagConstraints gridBagConstraints = new GridBagConstraints();

    /**
     * initialize
     * 
     */
    GameFrame() {
        wordTest = new WordTest();
        win = 0;
        setting();
    }

    /**
     * to run this frame and bind the father frame
     * 
     * @param gameConsole the parent frame
     */
    public void run(GameConsole gameConsole) {
        this.gameConsole = gameConsole;
        start();

    }

    /**
     * to start the game
     * reset the data and the page
     */
    public void start() {
        System.out.println("start");
        tries = 0;
        guess = "";
        wordTest.setKeyword();
        inputField.setText("");
        for (int i = 0; i < 30; i++) {
            words[i].setText("X");
            words[i].setFont(fWord);
            words[i].setForeground(java.awt.Color.DARK_GRAY);
        }

    }

    /**
     * return the game info of player to parent frame
     * 
     * @return the times of winning
     */
    public int getInfo() {
        return win;

    }

    /**
     * the setting of the frame
     * the layout and buttons
     * //
     */
    private void setting() {
        GridBagLayout gridBagLayout = new GridBagLayout();
        setLayout(gridBagLayout);
        // setLayout(null);

        /**
         * setting of the frame/layout/constraint/button/message box
         */
        JPanel buttonContainer = new JPanel();
        JButton backButton = new JButton("Back");
        JButton restartButton = new JButton("Restart");
        inputField = new JTextField();

        for (int i = 0; i < 6; i++) {
            JLabel roundLabel = new JLabel("round" + (i + 1));
            JPanel wordContainer = new JPanel();
            JLabel word;
            wordContainer.setBorder(new EmptyBorder(0, 110, 0, 0));
            FlowLayout f = (FlowLayout) wordContainer.getLayout();
            f.setHgap(40);
            add(roundLabel, gcs(0, i + 1, 20, 1));
            add(wordContainer, gcs(1, i + 1, 30, 1));
            for (int j = 0; j < 5; j++) {
                word = new JLabel("X");
                word.setPreferredSize(new Dimension(30, 20));
                word.setFont(fWord);
                words[i * 5 + j] = word;
                wordContainer.add(word);
            }

        }

        // gconstraint.fill = GridBagConstraints.BOTH;

        buttonContainer.add(restartButton);
        buttonContainer.add(backButton);
        FlowLayout f = (FlowLayout) buttonContainer.getLayout();
        f.setHgap(100);
        add(inputField, gcs(0, 7, 350, 1));
        add(buttonContainer, gcs(0, 8, 200, 1));

        inputField.addKeyListener(this);
        restartButton.addActionListener((e) -> start());

        backButton.addActionListener((e) -> {

            setVisible(false);
            gameConsole.setVisible(true);
        });

    }

    // private void setting1() {
    // GridBagLayout gridBagLayout = new GridBagLayout();
    // setLayout(gridBagLayout);

    // // setLayout(null);

    // /**
    // * setting of the frame/layout/constraint/button/message box
    // */
    // JPanel buttonPanel = new JPanel();
    // JButton backButton = new JButton("Back");
    // JButton restartButton = new JButton("Restart");
    // textField = new JTextField();

    // for (int i = 0; i < 6; i++) {
    // JLabel jLabel = new JLabel("round" + (i + 1));
    // JPanel jPanel = new JPanel();
    // JLabel word;
    // add(jLabel, gcs(0, i + 1, 3, 1));
    // add(jPanel, gcs(7, i + 1, 3, 1));
    // jPanel.setBorder(new EmptyBorder(0, 110, 0, 0));
    // FlowLayout f = (FlowLayout) jPanel.getLayout();

    // f.setHgap(40);
    // for (int j = 0; j < 5; j++) {
    // word = new JLabel("X");
    // word.setForeground(java.awt.Color.PINK);
    // word.setFont(fWord);
    // words[i * 5 + j] = word;
    // jPanel.add(word);
    // }

    // }

    // // gconstraint.fill = GridBagConstraints.BOTH;

    // // getContentPane().
    // buttonPanel.add(restartButton);
    // // getContentPane().add(backButton);
    // buttonPanel.add(backButton);
    // add(textField, gcs(0, 7, 300, 1));
    // add(buttonPanel, gcs(0, 8, 30, 1));

    // textField.addKeyListener(this);
    // restartButton.addActionListener((e) -> start());

    // backButton.addActionListener((e) -> {

    // setVisible(false);
    // gameConsole.setVisible(true);
    // });

    // }

    /**
     * a method to simplize the setting of a constraint
     * 
     * @param girdx  girdx of constraint
     * @param girdy  girdy of constraint
     * @param width  width of constraint
     * @param height height of constraint
     * @return constraint
     */
    private GridBagConstraints gcs(int girdx, int girdy, int width, int height) {

        gridBagConstraints.gridx = girdx;
        gridBagConstraints.gridy = girdy;
        gridBagConstraints.gridwidth = width;
        gridBagConstraints.gridheight = height;
        gridBagConstraints.fill = GridBagConstraints.BOTH;
        gridBagConstraints.insets.top = 10;
        // gridBagConstraints.insets.right = 50;
        return gridBagConstraints;

    }

    /**
     * method to refresh the frame
     * 
     * @param s the string show in the frame
     */
    private void refresh(String s) {
        for (int i = 0; i < s.length(); i++) {
            JLabel characterContainer = words[tries * 5 + i];
            characterContainer.setText("" + s.charAt(i));
        }
        for (int i = s.length(); i < 5; i++) {
            JLabel characterContainer = words[tries * 5 + i];
            characterContainer.setText("X");

        }

    }

    /**
     * the method need to be override to implement the interface
     */
    @Override
    public void keyTyped(KeyEvent e) {

    }

    /**
     * the method need to be override to implement the interface
     */
    @Override
    public void keyPressed(KeyEvent e) {
        // TODO Auto-generated method stub
    }

    /**
     * to get the input and the "enter" to end input
     * then call the method in wordtest to judge the word
     * then change the color of the word and print in frame
     * show the error info if it is an invalid word
     * 
     */
    @Override
    public void keyReleased(KeyEvent e) {

        // TODO Auto-generated method stub
        if (e.getSource() == inputField) {
            char keychar = e.getKeyChar();
            int keycode = e.getKeyCode();

            /** keycode is "enter" */
            if (keycode == 10) {
                // get enter
                System.out.println("catch --- 'enter' ---");
                System.out.println("get guess --- " + guess + " ---");

                guess = inputField.getText().trim().toUpperCase();

                /** judge if it has len of 5 */
                if (guess.length() == 5) {
                    /** judge if it is a valid word */
                    if (wordTest.isValid(guess)) {
                        /** judge if it is a correct guess */
                        boolean rightGuess = wordTest.compare(guess);

                        java.awt.Color[] colors = wordTest.getColors();
                        for (int i = 0; i < 5; i++) {
                            JLabel characterContainer = words[tries * 5 + i];
                            characterContainer.setForeground(colors[i]);
                            characterContainer.setText("" + guess.charAt(i));
                        }

                        if (rightGuess) {
                            win++;
                            JOptionPane.showMessageDialog(this, "Congrats!\nthe answer is " +
                                    wordTest.getKeyword(),
                                    "you win",
                                    JOptionPane.PLAIN_MESSAGE);
                            start();

                        }

                        /** run out of all the chances, end this round */

                        else if (tries++ == 5) {

                            JOptionPane.showMessageDialog(this,
                                    "Sorry!\nthe answer is " + wordTest.getKeyword() + "\n you could try again",
                                    "you fail",
                                    JOptionPane.PLAIN_MESSAGE);
                            start();
                        } /** wrong guess , show the color of guess */

                    } else {
                        JOptionPane.showMessageDialog(this, "not a valid word, please try again",
                                "Error",
                                JOptionPane.WARNING_MESSAGE);
                        refresh("");

                    }

                }
                /**
                 * lengh of guess is under 5
                 * sent the error and clear the textfield
                 */
                else if (!guess.equals("")) {
                    JOptionPane.showMessageDialog(this, "invalid input, please try again",
                            "Error",
                            JOptionPane.WARNING_MESSAGE);

                    refresh("");

                }
                guess = "";
                inputField.setText("");

            }
            /**
             * keycode is "baskspace"
             * 
             */
            else if (keycode == 8) {
                System.out.println("catch --- 'backspace' ---");
                if (guess.length() > 0) {
                    guess = guess.substring(0, guess.length() - 1);
                }
                refresh(guess);
                inputField.setText(guess);

            }
            /**
             * keycode is a valid char
             * add this char into "guess"
             */

            else if (Character.isLetter(keychar) && guess.length() < 5) {
                guess += Character.toString(keychar).toUpperCase();

                System.out.println(guess);
                refresh(guess);
                inputField.setText(guess);

            }
            /**
             * ignore the input if it is an invalid input
             * and clear the textfield
             */
            else {
                inputField.setText(guess);
            }
        }

    }

}
