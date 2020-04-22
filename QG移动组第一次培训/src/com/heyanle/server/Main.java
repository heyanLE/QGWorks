package com.heyanle.server;

import java.io.IOException;
import java.util.Scanner;

/**
 * Created by HeYanLe on 2020/4/22 0022.
 * https://github.com/heyanLE
 */
public class Main {

    public static final int PORT = 8080;

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        // write your code here
        SocketServer socketServer = new SocketServer(PORT);
        socketServer.start();
        System.out.println("You can close the server by input anything");
        String in = s.next();
        System.out.println("Bye Bye ~");
        socketServer.stop();
    }

}
