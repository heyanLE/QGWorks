package com.heyanle.client;

import com.heyanle.server.ConnectionThread;
import com.heyanle.server.SocketServer;
import com.heyanle.utils.FileUtils;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

/**
 * Created by HeYanLe on 2020/4/22 0022.
 * https://github.com/heyanLE
 */
public class Main {

    private static Socket socket;
    public static final String HOST = "127.0.0.1";
    public static final int PORT = 8080;
    private static DataOutputStream out;
    private static DataInputStream in;
    private static Scanner S = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        socket = new Socket(HOST, PORT);
        out = new DataOutputStream(socket.getOutputStream());
        in = new DataInputStream(socket.getInputStream());

        System.out.println("Connect to Server !!!");


        while(!socket.isClosed()){
            for(int i = 0; i < 15; i++) {
                System.out.append("#");
            }
            System.out.println();
            System.out.println();
            System.out.println("Please enter the file path and name :");
            System.out.println("You can exit by enter 'stop'");
            String input = S.nextLine();
            if (input.equals("stop")){
                out.writeUTF(ConnectionThread.COMMAND_DISCONNECT);
                out.flush();
                System.out.println("Bye Bye ~");
                socket.close();
                return;
            }else {
                requestFile(input);
            }
        }
    }

    public static void requestFile(String path) throws IOException{
        StringBuilder request = new StringBuilder(ConnectionThread.COMMAND_FILE_REQUEST)
                .append("&&")
                .append(path);
        out.writeUTF(request.toString());
        out.flush();
        String[] response = in.readUTF().split("&&");
        switch (response[0]){
            case ConnectionThread.RESPONSE_FILE_ENABLE:
                System.out.println("Well, please enter the target path :");
                File file = null;
                file = FileUtils.toTargetPath(S.nextLine());
                while (file == null){
                    System.out.println("Well, please enter the right target path :");
                    file = FileUtils.toTargetPath(S.nextLine());
                }
                System.out.println("Well, please enter the target name :");
                File f = new File(file.getAbsolutePath()+File.separator+S.nextLine());
                if (f.exists()){
                    System.out.println("The file seem to be exist, would you like to overwrite ? [Y/N]");
                    String s = S.nextLine();
                    if(s.startsWith("Y") || s.startsWith("y")){
                        f.delete();
                        f.createNewFile();
                    }else{
                        return;
                    }
                }
                file.mkdirs();
                request.setLength(0);
                request.append(ConnectionThread.COMMAND_FILE_BYTES);
                request.append("&&");
                request.append(response[1]);
                out.writeUTF(request.toString());
                long fileLength = Long.parseLong(response[2]);
                GetFileBytes(f, fileLength);
                break;
            case ConnectionThread.RESPONSE_FILE_DISABLED:
                System.out.println("The path is wrong or the file is not exist !!!!");
                break;
        }


    }

    public static void GetFileBytes(File file ,long fileLength) throws IOException{
        FileOutputStream out = new FileOutputStream(file);
        byte[] bytes = new byte[1024];
        int length = 0;

        ShowProgress();
        while(true){
            length = in.read(bytes, 0, bytes.length);
            out.write(bytes ,0, length);

            ShowProgress((int)(((double)file.length()/((double)(fileLength)))*100));
            if (fileLength == file.length()){
                break;
            }
        }
        System.out.println("Complete !!");
        System.out.println();
        System.out.println();
    }
    public static void ShowProgress(){
        System.out.println();
        System.out.print("Progress 00% [----------]");
    }
    public static void ShowProgress(int percent){
        for(int i = 0 ; i < 26 ; i ++){
            System.out.print("\b");
        }
        System.out.print("Progress "+(percent<10?("0"+percent):percent)+"% [");
        for(int i = 1 ; i <= 10 ; i ++){
            if(i <= percent /10 ){
                System.out.print("█");
            }else{
                System.out.print("-");
            }
        }
        System.out.print("]");

    }
}
