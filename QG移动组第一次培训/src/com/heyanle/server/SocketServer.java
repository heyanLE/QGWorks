package com.heyanle.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by HeYanLe on 2020/4/22 0022.
 * https://github.com/heyanLE
 */
public class SocketServer {

    private boolean mStatus = false;
    private ServerSocket mServerSocket;

    public SocketServer(int port) throws IOException{
        mServerSocket = new ServerSocket(port);
    }

    public void start(){

        new Thread(new Runnable() {
            @Override
            public void run() {
                try{
                    System.out.println("Socket Server Running ！！！");
                    mStatus = true;
                    while (mStatus){
                        new ConnectionThread(mServerSocket.accept()).start();
                    }
                }catch (IOException e){
                    e.printStackTrace();
                }

            }
        }).start();
    }

    public void stop(){
        try{
            mServerSocket.close();
        }catch (IOException e){
            e.printStackTrace();
        }

    }

}

