import java.io.IOException;

/**
 * the interface to print out the error info when input is in wrong format
 */
public interface WrongInput {

    default void wrongInput() {
        System.out.println("Wrong input, plz try again");
        // try {
        // Thread.sleep(2000);
        // Process process = Runtime.getRuntime().exec("cls");
        // process.waitFor();

        // } catch (InterruptedException e) {
        // // TODO Auto-generated catch block
        // e.printStackTrace();
        // }
        // catch (IOException e) {
        // // TODO Auto-generated catch block
        // e.printStackTrace();
        // }

    }

    default void wrongInput(String output) {
        System.out.println(output);
        try {
            Thread.sleep(2000);
            // Process process = Runtime.getRuntime().exec("cls");

        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        // catch (IOException e) {
        // // TODO Auto-generated catch block
        // e.printStackTrace();
        // }

    }
}
