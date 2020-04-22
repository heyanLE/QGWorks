package com.heyanle.server;

import com.heyanle.utils.FileUtils;

import java.io.*;
import java.net.Socket;

/**
 * Created by HeYanLe on 2020/4/22 0022.
 * https://github.com/heyanLE
 */
public class ConnectionThread extends Thread {

    public static final String RESPONSE_FILE_DISABLED = "FILE_DISABLED";
    public static final String RESPONSE_FILE_ENABLE = "FILE_ENABLE";
    public static final String RESPONSE_UNKNOWN_COMMAND = "UNKNOWN_COMMAND";

    public static final String COMMAND_FILE_REQUEST = "FILE_REQUEST";
    public static final String COMMAND_FILE_BYTES = "FILE_BYTES";
    public static final String COMMAND_DISCONNECT = "DISCONNECT";

    private final Socket mSocket;
    private DataInputStream mIn;
    private DataOutputStream mOut;
    private boolean mStatus;

    public ConnectionThread(Socket mSocket) {
        this.mSocket = mSocket;
    }

    @Override
    public void run() {
        try{
            System.out.println("Client Connected : "+mSocket.getLocalAddress());
            mIn = new DataInputStream(mSocket.getInputStream());
            mOut = new DataOutputStream(mSocket.getOutputStream());
            mStatus = true;
            while(mStatus) {
                waitRequest();
            }
        }catch (IOException e){
            e.printStackTrace();
        }
    }


    private void disconnect(){
        try{
            mOut.close();
        }catch (IOException e){
            e.printStackTrace();
        }

        try{
            mIn.close();
        }catch (IOException e){
            e.printStackTrace();
        }

        try{
            mSocket.close();
        }catch (IOException e){
            e.printStackTrace();
        }

        mStatus = false;
    }

    public void waitRequest() throws IOException{
        String content = mIn.readUTF();
        String[] command = content.split("&&");
        if(command.length > 0){
            switch (command[0]){
                case COMMAND_FILE_REQUEST:
                    if (command.length >= 2){
                        responseFile(command[1]);
                    }else{
                        responseFile("");
                    }
                    return;
                case COMMAND_FILE_BYTES:
                    if (command.length >= 2){
                        responseFileByte(command[1]);
                    }else{
                        responseFileByte("");
                    }
                    return;
                case COMMAND_DISCONNECT:
                    disconnect();
                    return;
            }
        }
        responseUnknown();

    }

    public void responseFile(String path) throws IOException{
        StringBuilder response = new StringBuilder();
        File file = FileUtils.toFile(path);
        if(file == null){
            response.append(RESPONSE_FILE_DISABLED)
                    .append("&&")
                    .append(path);
        }else{
            response.append(RESPONSE_FILE_ENABLE)
                    .append("&&")
                    .append(file.getCanonicalFile())
                    .append("&&")
                    .append(file.length());
        }
        mOut.writeUTF(response.toString());
        mOut.flush();
    }
    public void responseFileByte(String path) throws IOException{
        File file = FileUtils.toFile(path);
        if(file == null){
            mOut.writeUTF(RESPONSE_FILE_DISABLED+"&&"+path);
            mOut.flush();
        }else{
            FileInputStream fileInput = new FileInputStream(file);
            byte[] bytes = new byte[1024];
            int length = 0;
            while((length = fileInput.read(bytes)) != -1) {
                mOut.write(bytes, 0, length);
                mOut.flush();
            }
            fileInput.close();
        }
    }

    public void responseUnknown() throws IOException{
        mOut.writeUTF(RESPONSE_UNKNOWN_COMMAND);
        mOut.flush();
    }


}
