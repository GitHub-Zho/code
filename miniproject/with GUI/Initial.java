
import javax.swing.*;
import java.awt.*;

/**
 * an interface to initialize the frame and the word setting
 * to make the frame self-adaptive
 * while running in different enviroment
 */
public interface Initial {
    /**
     * to initial the frame
     * 
     * @param JF     frame to be initialized
     * @param title  the title of frame
     * @param father the father frame used to set a relativent location
     */
    default void initial(JFrame JF, String title, JFrame father) {
        Toolkit kit = Toolkit.getDefaultToolkit();
        Dimension screenSize = kit.getScreenSize();
        int screenWidth = screenSize.width;
        int screenHeight = screenSize.height;
        JF.setSize(screenWidth / 2, screenHeight / 2);
        JF.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JF.setTitle(title);
        JF.setLocationRelativeTo(father);
        JF.setVisible(true);
        // JF.setLocationByPlatform(true);

    }

    /**
     * to initialize the same font of a component
     * 
     * @param c component
     */
    default void wordInitial(Component c) {
        c.setFont(new Font("Serif", 4, 38));

    }
}
