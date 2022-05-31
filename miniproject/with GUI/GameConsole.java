
/** 
 * This is my Wordle game
 * @author Yuchen Zhou
 * @version 1.0
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

import static java.lang.System.out;

/**
 * the initial frame of the game
 * i want to make it looks more like a game mechine that we played
 * on the street when we were kids
 * and the data store is also like mechine
 * we can store the player's rank info untill the mechine is powered off
 * 
 */
public class GameConsole extends JFrame implements Initial {
    /**
     * the game console itself
     * used in it's inner class which implement the actionlistener interface
     */
    private GameConsole gameConsole = this;
    /**
     * the game frame
     */
    private GameFrame game = new GameFrame();
    /**
     * the rank list of player
     */
    private ArrayList<String> playerList;
    /**
     * the list of valid words
     */
    private String player;

    /**
     * initialize the gameframe
     * and run the test
     * 
     * @param args you can enter your player name or just enter nothing
     */
    public static void main(String[] args) {
        String name = "";
        if (args.length > 0)
            name = args[0];
        else
            name = null;
        GameConsole myGame = new GameConsole(name);

        myGame.runtest();

    }

    /**
     * initilize the game console
     * 
     * @param player the name of player
     */
    GameConsole(String player) {
        if (player != null)
            this.player = player.trim().toLowerCase();

    }

    /**
     * use to print the location of component
     * used in modify the component while testing
     * 
     * @param c component
     */
    public void positest(Component c) {
        Rectangle r = c.getBounds();
        out.println(r);
    }

    /**
     * the main function which
     * put all the setting of page into the Eventqueue
     * to avoid the main thread interrupt the swing event thread
     * 
     */
    public void runtest() {
        EventQueue.invokeLater(() -> {
            initial(this, "GameConsole", null);
            this.setBackground(java.awt.Color.black);
            /**
             * setting of the button/frame/layout
             */

            JLabel label = new JLabel("    WELCOME TO WORDLE GAME");
            JPanel panel = new JPanel();
            JButton startButton = new JButton("Start");
            JButton rankButton = new JButton("rank");
            JButton quitButton = new JButton("Quit");
            JButton ruleButton = new JButton("Rule");
            panel.add(startButton);
            panel.add(rankButton);
            panel.add(ruleButton);
            panel.add(quitButton);
            startButton.addActionListener(new StartAction());
            rankButton.addActionListener(new RankAction());
            ruleButton.addActionListener(new RuleAction());
            quitButton.addActionListener((e) -> {
                JOptionPane.showMessageDialog(this,
                        "                 you have won " + game.getInfo()
                                + " times\n                THANKS FOR PLAYING",
                        "score",
                        JOptionPane.PLAIN_MESSAGE);
                System.exit(0);

            });

            positest(this);
            positest(panel);
            wordInitial(label);
            add(label, BorderLayout.CENTER);
            getContentPane().add(panel, BorderLayout.SOUTH);
            getContentPane().setBackground(java.awt.Color.gray);
            panel.setOpaque(true);

        });

        // setOpacity(true);

        // startButton.setBounds(380, 230, 100, 50);
        // rankButton.setBounds(330, 190, 100, 50);
        // positest(startButton);
        // positest(rankButton);

    }

    // public void run() {

    // initial(this, "GameConsole", null);
    // JButton startButton = new JButton("Start");
    // JButton rankButton = new JButton("rank");
    // // getContentPane().
    // add(startButton);
    // // getContentPane().
    // add(rankButton);
    // startButton.setSize(10, 10);
    // startButton.setSize(10, 10);
    // startButton.addActionListener(new StartAction());
    // Point a = startButton.getLocation();
    // startButton.setLocation(a.x + 10, a.y + 10);
    // rankButton.addActionListener(this);
    // }

    /**
     * start button
     * the inner class to implement the action
     * click start button and start the game
     * 
     */
    private class StartAction implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            game.initial(game, "Wordle", null);
            game.run(gameConsole);
            setVisible(false);

        }

    }

    /**
     * rule button
     * the inner class to implement the action
     * click rule button and show the rules
     * 
     */
    private class RuleAction implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            JFrame table = new JFrame("rule");
            JPanel panel = new JPanel();
            JButton back = new JButton("back");
            initial(table, "rule", null);
            table.getContentPane().setBackground(java.awt.Color.cyan);
            table.add(panel);
            panel.add(new JLabel("                     "));
            panel.add(new JLabel("                     "));
            panel.add(new JLabel("                     "));
            panel.add(new JLabel("An English word consisting of five letters is selected at random (by the computer)"));
            panel.add(new JLabel("from a list of words, but kept hidden from the human player."));
            panel.add(new JLabel("The player tries to guess the 5-letter word. "));
            panel.add(new JLabel("The player is allowed to make 6 guesses in total to discover the target word."));
            panel.add(new JLabel("The player is given feedback after each attempt they make."));
            panel.add(new JLabel(" The feedback is as follows;"));
            panel.add(new JLabel("There are three colours that the cells containing the letters can be:"));
            panel.add(new JLabel("green, yellow, or grey."));
            panel.add(new JLabel("1. Green means the letter is contained in the word and is in that position."));
            panel.add(new JLabel("2. Yellow means the letter is contained in the word but not in that position."));
            panel.add(new JLabel("3. Grey means the letter is not contained in the word."));
            table.add(back, BorderLayout.SOUTH);
            back.addActionListener((event) -> {
                table.setVisible(false);
            });

            table.setVisible(true);

        }

    }

    /**
     * rank button
     * the inner class to implement the action
     * click rule button and show the rank
     * 
     */
    private class RankAction implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            if (game.getInfo() != 0) {
                JOptionPane.showMessageDialog(gameConsole,
                        "You have won " + game.getInfo() + " times\nYour rank is NO.1 ", "Congrats",
                        JOptionPane.PLAIN_MESSAGE);
            } else
                JOptionPane.showMessageDialog(gameConsole, "No rank now", "Error",
                        JOptionPane.WARNING_MESSAGE);

            // setVisible(false);

        }

    }

}